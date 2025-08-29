#include "solver.hpp"
#include "run.hpp"
#include "unit_test.hpp"
#include "file_test.hpp"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


/**
 *\brief Функция, которая выводит помощь в использовании программы
 */
void help() {
    printf("Usage: final.exe [options] file...\nOptions:\n--run             Enter coefficients from console\n--test            The coefficients are taken from the array of structures\n--file            The coefficients are taken from the file\n--help            Help in using the program");
}


/**
 *\brief Функция, которая говорит о неправильном вводе и показывает как вызвать help
 */
void incorrect_input() {
    printf("Incorrect input! Write ./final --help to understand how the program works\n");
}


int main(int argc, char *argv[]) {
    bool flag_run = false;
    bool flag_test = false;
    bool flag_file = false;
    bool flag_help = false;


    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--run") == 0)
            flag_run = true;
        else if (strcmp(argv[i], "--test") == 0)
            flag_test = true;
        else if (strcmp(argv[i], "--file") == 0)
            flag_file = true;
        else if (strcmp(argv[i], "--help") == 0)
            flag_help = true;
    }


    if  (flag_run)
        run();
    else if (flag_test)
        test();
    else if (flag_file)
        file_tests();
    else if (flag_help)
        help();
    else
        incorrect_input();

    return 0;
}
