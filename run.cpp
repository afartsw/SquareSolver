#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "solver.hpp"
#include "run.hpp"


/**
 *\brief Функция, которая очищает буфер ввода после некорректных коэффициентов
 */
void skip_line() {
    int c = 0;

    while ((c = getchar()) != '\n' && c != EOF);
}


/**
 *\brief Функция, которая спрашивает пользователя о желании продолжить ввод
 */
bool quit_condition() {
    int n = 5;
    char entered_string[10] = "";

    printf("Do you want to continue typing?\nTo exit, write quit\n");
    skip_line();
    fgets(entered_string, n, stdin);

    assert(entered_string != '\0');

    return !(compare_numbers(strcmp(entered_string, "quit"), 0.0) == EQUALLY);
}


/**
 *\param eq Структура, в которой указываются коэффициенты уравнения
 *\brief Функция, которая считывает коэффициенты с консоли
 */
int read_coefficients(Equation *eq) {
    printf("Enter the coefficients of the quadratic equation ax^2 + bx + c = 0 (a, b, c): ");

    assert(isfinite(eq->coeff_a));
    assert(isfinite(eq->coeff_b));
    assert(isfinite(eq->coeff_c));

    int count_coeffs = scanf("%lf %lf %lf", &(eq->coeff_a), &(eq->coeff_b), &(eq->coeff_c));

    while (count_coeffs != 3) {
        printf("Incorrect input. Try to enter it again.\n");
        skip_line();
        count_coeffs = scanf("%lf%lf%lf", &(eq->coeff_a), &(eq->coeff_b), &(eq->coeff_c));
    }

}


/**
 *\param eq Структура, в которой указываются коэффициенты уравнения, количество корней и сами корни
 *\brief Функция, которая выводит решение квадратного уравнения
 */
int print_result(const Equation *eq) {
    assert(eq->nRoots > -1);

    switch(eq->nRoots) {
        case -1:
            printf("An infinite number of solutions\n");
            break;
        case 0:
            printf("There are no solutions\n");
            break;
        case 1:
            printf("One root:\nx = %.4lf\n", eq->root1);
            break;
        case 2:
            printf("Two roots:\nx1 = %.4lf\nx2 = %.4lf\n", eq->root1, eq->root2);
            break;
        default:
            break;
    }
}


void run() {
    Equation eq = {};
    bool should_continue = true;

    while (should_continue) {
        read_coefficients(&eq);
        SolveSquare(&eq);
        print_result(&eq);
        should_continue = quit_condition();
    }
}

