#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "solver.hpp"



/**
 *\param tests Массив структур, в которых записаны коэффициенты уравнений из файла
 *\param count_tests Количество тестов, записанных в файле
 *\brief Функция, которая выводит правильность решения квадратных уравнений из файла
 */
void testing_file(Equation tests[], size_t count_tests, FILE * file_out);


/**
 *\brief Функция, которая запускает решатель квадратных уравнений из файла
 */
void file_tests();

#endif
