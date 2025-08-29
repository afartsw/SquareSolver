#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "solver.hpp"
#include "unit_test.hpp"
#include "file_test.hpp"



void testing_file(Equation tests[], size_t count_tests, FILE * file_out) {
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
                fprintf(file_out, "Square equation %lf * x^2 + %lf * x + %lf has infinity of roots\n", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c);
                ++count_success;
            }
        } else if (compare_numbers(tests[i].nRoots, 0) == EQUALLY) {
            if (!(compare_numbers(tests[i].nRoots, eq.nRoots) == EQUALLY))
                printf(FAILED " (should be without roots)\n\033[0m", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.nRoots);
            else {
                printf(SUCCESS);
                fprintf(file_out, "Square equation %lf * x^2 + %lf * x + %lf has no roots\n", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c);
                ++count_success;
            }
        } else if (compare_numbers(tests[i].nRoots, 1) == EQUALLY) {
            if (!((compare_numbers(tests[i].nRoots, eq.nRoots) == EQUALLY) && (compare_numbers(eq.root1, tests[i].root1) == EQUALLY)))
                printf(FAILED ", root1 = %lf (should be root1 = %lf)\n\033[0m", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.nRoots, eq.root1, tests[i].root1);
            else {
                printf(SUCCESS);
                fprintf(file_out, "Square equation %lf * x^2 + %lf * x + %lf has one root. root1 = %lf\n", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.root1);
                ++count_success;
            }
        } else {
            if (!((compare_numbers(tests[i].nRoots, eq.nRoots) == EQUALLY) && (compare_numbers(eq.root1, tests[i].root1) == EQUALLY) && (compare_numbers(eq.root2, tests[i].root2) == EQUALLY)))
                printf(FAILED ", root1 = %lf, root2 = %lf (should be root1 = %lf, root2 = %lf)\n\033[0m", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.nRoots, eq.root1, eq.root2, tests[i].root1, tests[i].root2);
            else {
                printf(SUCCESS);
                fprintf(file_out, "Square equation %lf * x^2 + %lf * x + %lf has two roots. root1 = %lf, root2 = %lf\n", tests[i].coeff_a, tests[i].coeff_b, tests[i].coeff_c, eq.root1, eq.root2);
                ++count_success;
            }
        }
    }

    assert(count_success > NULL);

    printf("\033[1;32m Completed %d of %d tests successfully\n\033[0m", count_success, count_tests);
}


void file_tests() {
    Equation eq = {};
    Equation tests[10] = {};

    FILE * file_in = fopen("tests.txt", "r");
    FILE * file_out = fopen("solutions.txt", "w");


    if (file_in == NULL) {
        printf("ERROR");
        return;
    }

    if (file_out == NULL) {
        printf("ERROR");
        return;
    }


    for (int i = 0; i < 10; i++) {
        int n = fscanf(file_in, "%lf%lf%lf%d%lf%lf", &eq.coeff_a, &eq.coeff_b, &eq.coeff_c, &eq.nRoots, &eq.root1, &eq.root2);
        tests[i] = eq;
    }

    testing_file(tests, sizeof(tests)/sizeof(tests[0]), file_out);

    fclose(file_in);
    fclose(file_out);
}




















