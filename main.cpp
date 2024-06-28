#include "MetricRegister.h"
#include <iostream>

using namespace std;

int main() {
    // Получение единственного экземпляра класса MetricRegister
    MetricRegister& registerInstance = MetricRegister::getInstance();

    // Добавление метрик с временем отклика и временем ожидания
    registerInstance.add_metr(1, 462, 845);
    registerInstance.add_metr(2, 96, 690);
    registerInstance.add_metr(3, 667, 988);
    registerInstance.add_metr(4, 317, 702);
    registerInstance.add_metr(5, 485, 669);
    registerInstance.add_metr(6, 294, 619);
    registerInstance.add_metr(7, 586, 923);
    registerInstance.add_metr(8, 108, 903);
    registerInstance.add_metr(9, 333, 629);
    registerInstance.add_metr(10, 623, 770);

    cout << "Metric output:" << '\n';
    // Вывод всех метрик
    registerInstance.show_metr();

    int key = 3;
    // Подсчет общего времени отклика и ожидания для метрики с ключом key
    int cometr = registerInstance.count_cometr(key);
    if (cometr != -1) {
        cout << "Adding metrics for a key " << key << ": " << cometr << '\n';
    }
    else {
        cout << "Key " << key << " was not found in metrics" << '\n';
    }

    return 0;
}