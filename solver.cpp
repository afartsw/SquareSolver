#include "solver.hpp"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


enum result compare_numbers(double num1, double num2) {
    assert(isfinite(num1));
    assert(isfinite(num2));

    if ((num2 - num1) > PRECISION)
        return LESS;
    else if ((num1 - num2) > PRECISION)
        return MORE;
    else
        return EQUALLY;
}


void SolveSquare(Equation *eq) {
    assert(isfinite(eq->coeff_a));
    assert(isfinite(eq->coeff_b));
    assert(isfinite(eq->coeff_c));
    assert(isfinite(eq->root1));
    assert(isfinite(eq->root2));

    if (compare_numbers(eq->coeff_a, 0.0) == EQUALLY) {
        if (compare_numbers(eq->coeff_b, 0.0) == EQUALLY) {
            if (compare_numbers(eq->coeff_c, 0.0) == EQUALLY)
                eq->nRoots = -1;
            else
                eq->nRoots = 0;
        } else {
                eq->root1 = -eq->coeff_c / eq->coeff_b;
                eq->nRoots = 1;
        }
    } else {
        double discriminant = eq->coeff_b * eq->coeff_b  -  4 * eq->coeff_a * eq->coeff_c;

        assert(isfinite(discriminant));

        if (compare_numbers(discriminant, 0.0) == EQUALLY) {
            eq->root1 = -eq->coeff_b / (2 * eq->coeff_a);
            eq->nRoots = 1;
        } else if (compare_numbers(discriminant, 0.0) == MORE) {
            double sqrt_discriminant = sqrt(discriminant);
            eq->root1 = (-eq->coeff_b - sqrt_discriminant) / (2 * eq->coeff_a);
            eq->root2 = (-eq->coeff_b + sqrt_discriminant) / (2 * eq->coeff_a);

            if (compare_numbers(eq->root1, eq->root2) == MORE) {
                double temp = eq->root2;
                eq->root2 = eq->root1;
                eq->root1 = temp;
            }
            eq->nRoots = 2;
        } else {
            eq->nRoots = 0;
        }
    }
}



