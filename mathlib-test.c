#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

/* 
 * Prints a table comparing implementations of arcsin, arcos, arctan, and log
 * from mathlib.c to their respective library functions found in math.h. Allows
 * user to use command line arguments: -a for all, -s for arcsin, -c for arccos,
 * -t for arctan, and -l for log.
 *
 * argc: stores number of command-line arguments entered by user
 * argv: array of character pointers listing all arguments.
 *
 * Returns 0 for program success, 1 for program failure.
 */
int main(int argc, char **argv) {
    // define integer opt to keep track of when parsing is finished
    // define bool flags to make sure each function prints at most once
    int opt;
    bool is_print_a = false;
    bool is_print_s = false;
    bool is_print_c = false;
    bool is_print_t = false;
    bool is_print_l = false;

    // while loop that runs while getopt does not return -1 (parsing finished)
    // set printing flags to true if valid program argument exists
    while ((opt = getopt(argc, argv, "asctl")) != -1) {
        switch (opt) {
        case 'a': is_print_a = true; break;
        case 's': is_print_s = true; break;
        case 'c': is_print_c = true; break;
        case 't': is_print_t = true; break;
        case 'l': is_print_l = true; break;
        // if invalid program argument inputted then print error message and return
        default:
            printf("%s\n", "Program usage: ./mathlib-test -[asctl]");
            printf("%s\n", "  -a   Runs all tests (arcsin, arccos, arctan, log)");
            printf("%s\n", "  -s   Runs arcsin tests");
            printf("%s\n", "  -c   Runs arccos tests");
            printf("%s\n", "  -t   Runs arctan tests");
            printf("%s\n", "  -l   Runs log tests");
            return 1;
        }
    }

    // check printing flags and print the corresponding tables
    if (is_print_a == true) {
        printf("%3.4s %17.8s %17.8s %17.10s\n", "x", "arcSin", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = -1.0; i < 1.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcSin(i), asin(i),
                arcSin(i) - asin(i));
        }

        printf("%3.4s %17.8s %17.8s %17.10s\n", "x", "arcCos", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = -1.0; i < 1.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcCos(i), acos(i),
                arcCos(i) - acos(i));
        }

        printf("%3.4s %17.8s %17.8s %17.10s\n", "x", "arcTan", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = 1.0; i < 10.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcTan(i), atan(i),
                arcTan(i) - atan(i));
        }

        printf("%3.4s %14.8s %20.8s %17.10s\n", "x", "Log", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = 1.0; i < 10.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, Log(i), log(i), Log(i) - log(i));
        }
        return 0; //return here since all prints all functions
    }

    if (is_print_s == true) {
        printf("%3.4s %17.8s %17.8s %17.10s\n", "x", "arcSin", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = -1.0; i < 1.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcSin(i), asin(i),
                arcSin(i) - asin(i));
        }
    }

    if (is_print_c == true) {
        printf("%3.4s %17.8s %17.8s %17.10s\n", "x", "arcCos", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = -1.0; i < 1.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcCos(i), acos(i),
                arcCos(i) - acos(i));
        }
    }

    if (is_print_t == true) {
        printf("%3.4s %17.8s %17.8s %17.10s\n", "x", "arcTan", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = 1.0; i < 10.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcTan(i), atan(i),
                arcTan(i) - atan(i));
        }
    }

    if (is_print_l == true) {
        printf("%3.4s %14.8s %20.8s %17.10s\n", "x", "Log", "Library", "Difference");
        printf("%3.4s %17.8s %17.8s %17.10s\n", "-", "------", "-------", "----------");
        for (double i = 1.0; i < 10.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, Log(i), log(i), Log(i) - log(i));
        }
    }
    return 0;
}
