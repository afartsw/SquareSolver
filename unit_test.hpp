#ifndef UNIT_TEST_H
#define UNIT_TESTN_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "solver.hpp"


/**
 *\param tests Массив структур, в которых записаны коэффициенты уравнений
 *\param count_tests Количество тестов, записанных в массиве
 *\brief Функция, которая выводит правильность решения квадратных уравнений из массива структур
 */
void testing(Equation tests[], size_t count_tests);

/**
 *\brief Функция, которая запускает решение квадратных уравнений из массива структур
 */
void test();

#endif
