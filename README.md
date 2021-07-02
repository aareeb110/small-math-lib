# Purpose

This program prints out a table of up to four functions: sin^-1, cos^-1, tan^-1,
and log. The table contains x-values that are used to test implementations of 
the four functions and those of the <math.h> library, as well as the difference
in their outputs.

# Building

Typing "make" will build the program

Typing "make clean" will remove the binaries

# Running

Run the program by typing

	$ ./mathlib-test -[program arguments]

where -a = all functions, -s = sin^-1, -c = cos^-1, -t = tan^-1, -l = log
