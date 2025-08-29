#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "solver.hpp"
#include "unit_test.hpp"


void testing(Equation tests[], size_t count_tests) {
    int count_success = 0;

    assert(count_tests > NULL);

    for (int i = 0; i < count_tests; i++) {
        Equation eq = {tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, 0, 0, 0};
        SolveSquare(&eq);

        if (compare_numbers(tests[i].nRoots, -1) == EQUALLY) {
            if (!(compare_numbers(tests[i].nRoots, eq.nRoots) == EQUALLY))
                printf(FAILED " (should be infinity of roots)\n\033[0m", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.nRoots);
            else {
                printf(SUCCESS);
                ++count_success;
            }
        } else if (compare_numbers(tests[i].nRoots, 0) == EQUALLY) {
            if (!(compare_numbers(tests[i].nRoots, eq.nRoots) == EQUALLY))
                printf(FAILED " (should be without roots)\n\033[0m", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.nRoots);
            else {
                printf(SUCCESS);
                ++count_success;
            }
        } else if (compare_numbers(tests[i].nRoots, 1) == EQUALLY) {
            if (!((compare_numbers(tests[i].nRoots, eq.nRoots) == EQUALLY) && (compare_numbers(eq.root1, tests[i].root1) == EQUALLY)))
                printf(FAILED ", root1 = %lf (should be root1 = %lf)\n\033[0m", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.nRoots, eq.root1, tests[i].root1);
            else {
                printf(SUCCESS);
                ++count_success;
            }
        } else {
            if (!((compare_numbers(tests[i].nRoots, eq.nRoots) == EQUALLY) && (compare_numbers(eq.root1, tests[i].root1) == EQUALLY) && (compare_numbers(eq.root2, tests[i].root2) == EQUALLY)))
                printf(FAILED ", root1 = %lf, root2 = %lf (should be root1 = %lf, root2 = %lf)\n\033[0m", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.nRoots, eq.root1, eq.root2, tests[i].root1, tests[i].root2);
            else {
                printf(SUCCESS);
                ++count_success;
            }
        }
    }

    assert(count_success > NULL);

    printf("\033[1;32m Completed %d of %d tests successfully\n\033[0m", count_success, count_tests);
}


void test() {
    Equation eq = {};
    static Equation tests[5]= {
     (Equation){-1,  5, -4,  2,  1,  4},
     (Equation){ 0,  0,  0, -1,  0,  0},
     (Equation){ 1,  1,  1,  0,  0,  0},
     (Equation){ 1, -6,  9,  1,  3,  0},
     (Equation){ 1, 91, -792,  2,  -99,  8}
    };

    testing(tests, sizeof(tests)/sizeof(tests[0]));
}
