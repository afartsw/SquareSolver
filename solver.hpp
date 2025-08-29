#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


#define FAILED "\033[1;31m FAILED: SolveSquare(%lf, %lf, %lf) -> nRoots = %d"
#define SUCCESS "\033[1;32m Success\n\033[0m"

const double PRECISION = 1e-6;


enum result {
    LESS = 0,
    EQUALLY = 1,
    MORE = 2
};

struct Equation {
    double coeff_a /** Коэффициент a уравнения ax^2 + bx + c = 0 */, coeff_b /** Коэффициент b уравнения ax^2 + bx + c = 0 */, coeff_c /** Коэффициент c уравнения ax^2 + bx + c = 0 */;
    int nRoots /** Количество корней уравнения */;
    double root1 /** Меньший корень уравнения */, root2 /** Больший корень уравнения */;
};

/**
 *\param eq Структура, в которой находятся коэффициенты уравнения
 *\brief Функция, которая выполняет вычисление количества корней и их значений
 */
void SolveSquare(Equation *eq);


/**
 *\param num1 Первое число типа double для сравнения
 *\param num2 Второе число типа double для сравнения
 *\brief Функция, которая сравнивает два числа типа double
 */
enum result compare_numbers(double num1, double num2);

#endif
