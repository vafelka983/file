#include "MetricRegister.h"
#include <cassert>
#include <iostream>

// Функция для тестирования добавления метрик и подсчета общего времени для заданного ключа
void test_add_and_count_cometr() {
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

    // Проверка результатов подсчета общего времени для каждого ключа
    assert(registerInstance.count_cometr(1) == 1307);
    assert(registerInstance.count_cometr(2) == 786);
    assert(registerInstance.count_cometr(3) == 1655);
    assert(registerInstance.count_cometr(4) == 1019);
    assert(registerInstance.count_cometr(5) == 1154);
    assert(registerInstance.count_cometr(6) == 913);
    assert(registerInstance.count_cometr(7) == 1509);
    assert(registerInstance.count_cometr(8) == 1011);
    assert(registerInstance.count_cometr(9) == 962);
    assert(registerInstance.count_cometr(10) == 1393);
}

int main() {
    // Вызов теста для добавления метрик и подсчета общего времени
    test_add_and_count_cometr();

    // Вывод сообщения об успешном прохождении тестов
    std::cout << "All tests passed" << endl;

    return 0;
}
