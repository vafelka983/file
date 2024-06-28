#ifndef METRIC_REGISTER_H
#define METRIC_REGISTER_H

#include <map>
#include <iostream>

using namespace std;

// Класс для регистрации метрик
class MetricRegister {
public:
    // Получение единственного экземпляра класса (реализация синглетона)
    static MetricRegister& getInstance();

    // Добавление метрики в реестр по ключу, времени отклика и времени ожидания. было решенно добавить ключ.Он помогает связать определенное время отклика и временное ожидание с конкретной метрикой в рамках общего хранилища или реестра метрик
    bool add_metr(int key, int resp_t, int wait_t);

    // Вывод всех метрик из реестра
    bool show_metr();

    // Возвращает сумму времени отклика и времени ожидания для метрики с указанным ключом
    int count_cometr(int key);

private:
    // Приватный конструктор и оператор копирования для синглетона
    MetricRegister() = default;
    MetricRegister(const MetricRegister&) = delete;
    MetricRegister& operator=(const MetricRegister&) = delete;

    map<int, pair<int, int>> metrics; // Коллекция для хранения метрик
};

#endif