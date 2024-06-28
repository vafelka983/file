#include "MetricRegister.h"

// Реализация паттерна Singleton: возвращает единственный экземпляр класса MetricRegister
MetricRegister& MetricRegister::getInstance() {
    static MetricRegister instance; // Создаем статический экземпляр
    return instance;
}

// Функция для добавления новой метрики с временем ответа и временем ожидания
bool MetricRegister::add_metr(int key, int resp_t, int wait_t) {
    if (metrics.find(key) == metrics.end()) { // Проверяем, что ключ отсутствует в метриках
        metrics[key] = make_pair(resp_t, wait_t); // Добавляем метрику
        return true; // Возвращаем true, если метрика успешно добавлена
    }
    return false; // Возвращаем false, если метрика с таким ключом уже существует
}

// Функция для вывода всех сохраненных метрик
bool MetricRegister::show_metr() {
    if (metrics.empty()) { // Проверяем, что контейнер с метриками не пуст
        return false; // Возвращаем false, если нет сохраненных метрик
    }
    for (map<int, pair<int, int>>::const_iterator it = metrics.begin(); it != metrics.end(); ++it) {
        std::cout << "Ключ: " << it->first; // Выводим ключ
        std::cout << " - Response Time: " << it->second.first; // Выводим время ответа
        std::cout << " - Wait Time: " << it->second.second << '\n'; // Выводим время ожидания
    }
    return true; // Возвращаем true после успешного вывода метрик
}

// Функция для подсчета общего времени (суммы времени ответа и времени ожидания) для заданного ключа
int MetricRegister::count_cometr(int key) {
    if (metrics.find(key) != metrics.end()) { // Проверяем, что метрика с данным ключом существует
        return metrics[key].first + metrics[key].second; // Возвращаем сумму времени ответа и времени ожидания
    }
    return -1; // Возвращаем -1, если метрика с заданным ключом не найдена
}