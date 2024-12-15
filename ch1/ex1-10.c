/*
 * ex1-10.c
 *      Write a program to copy its input to its output, replacing each tab
 *      by \t, each backspace by \b, and each backslash by \\. This makes
 *      tabs and backspaces visible in an unambiguous way.
 *
 * Input:
 *      ASCII data on standard input.
 *
 * Output:
 *      Copy of output modified per instructions in summary.
 *
 * Build:
 *      $ gcc -o ex1-10 ex1-10.c
 *
 * Run:
 *      ./ex1-10
 *
 * Nots:
 *      Start program, type input, end with Ctrl-D (EOF).
 *
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int c;

	while ((c = getchar()) != EOF) {            /* read every char in stdin */
        if (c == '\t') {                        /* replace tabs */
            putchar('\\');
            putchar('t');
        } else if (c == '\b' ) {                /* replace backspace */
            putchar('\\');
            putchar('b');
        } else {                                /* everything else as-is */
		    putchar(c);
        }
	}

    return 0;
}
