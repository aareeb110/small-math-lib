#include "mathlib.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define EPSILON 1e-10

double Abs(double x);
double Exp(double x);
double Sqrt(double x);
double arcSinHelper(double x);

/*
 * Computes the absolute value of a number.
 * Returns the result as a double.
 *
 * x: the number used in computation, represented as a double
 */
double Abs(double x) {
    return x < 0 ? -x : x;
}

/*
 * Exp() function provided by Professor Long.
 *
 * Computes e^x where x is all real numbers.
 * Uses Taylor Series approximation to calculate.
 * Returns the result as a double.
 *
 * x: exponent component of e^x, represented as a double.
 */
double Exp(double x) {
    double term = 1, sum = 1;
    for (int k = 1; Abs(term) > EPSILON; k += 1) {
        term *= x / k;
        sum += term;
    }
    return sum;
}

/*
 * Sqrt() function provided by Professor Long.
 *
 * Computes the square root of x where x >= 0.
 * Uses the Newton iterate method to calculate.
 * Returns the result as a double.
 *
 * x: the number used in computation, represented as a double.
 */
double Sqrt(double x) {
    double y = 1.0;
    assert(x >= 0);
    for (double guess = 0.0; Abs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}

/*
 * Returns the trig identity of arcsin at edge cases, to provide 
 * a better approximation, else it approximates arcSin normally.
 * Returns the result as a double.
 *
 * x: the number used in computation, represented as a double.
 */

double arcSinHelper(double x) {
    assert(x >= -1 || x <= 1);
    double guess = 0.0; // initial guess will be x0 = 0
    // keep making guesses until xn_1 - x_n < epsilon
    while (1) {
        double guess_update = guess - (sin(guess) - x) / cos(guess); // make the next best guess
        if (Abs(guess_update - guess) < EPSILON) {
            break;
        }
        guess = guess_update; // update guess
    }
    return guess;
}

/*
 * Computes arcsin of x where -1 >= x >= 1.
 * Uses Newton Method approximation to calculate.
 * This is a helper function that will be called in arcSin.
 * Returns the result as a double.
 *
 * x: the number used in computation, represented as a double.
 */
double arcSin(double x) {
    // check if x is close enough to 1.0 or -1.0 (precision comparison)
    // else approximate using pi / 2 - arcSinHelper
    assert(x >= -1 || x <= 1);
    if (Abs(x - 1) < EPSILON) {
        return arcCos(Sqrt(1.0 - x * x));
    }
    if (Abs(x + 1) < EPSILON) {
        return -arcCos(Sqrt(1.0 - x * x));
    }
    return arcSinHelper(x); // approximate arcSin normally
}

/*
 * Computes arccos of x where -1 >= x >= 1.
 * Returns the trig identity of arccos at edge cases to provide
 * a better approximation, else it approximates arcCos normally.
 * Returns the result as a double.
 *
 * x: the number used in computation, represented as a double.
 */
double arcCos(double x) {
    // check if x is close enough to 1.0 or -1.0 (precision comparison)
    // else approximate using pi / 2 - arcSinHelper
    assert(x >= -1 || x <= 1);
    if (Abs(x - 1) < EPSILON) {
        return arcSinHelper(Sqrt(1.0 - x * x));
    }
    if (Abs(x + 1) < EPSILON) {
        return M_PI - arcSinHelper(Sqrt(1.0 - x * x));
    }
    return M_PI_2 - arcSinHelper(x); // approximate arcCos normally
}

/*
 * Computes arctan of x where x is all real numbers.
 * Uses arcSin's implementation to calculate.
 * Returns the result as a double.
 *
 * x: the number used in computation, represented as a double.
 */
double arcTan(double x) {
    return arcSin(x / Sqrt(x * x + 1.0));
}

/*
 * Computes natural log of x where x is positive real numbers.
 * Uses Newton iterate method to calculate.
 * Returns the result as a double.
 *
 * x: the number used in computation, represented as a double.
 */
double Log(double x) {
    assert(x > 0);
    double guess = 1.0; // initial guess will be x0 = 1
    // keep making guesses until xn_1 - x_n < epsilon
    while (1) {
        double guess_update = guess + (x - Exp(guess)) / Exp(guess); // make the next best guess
        if (Abs(guess_update - guess) < EPSILON) {
            break;
        }
        guess = guess_update; // update guess
    }
    return guess;
}
