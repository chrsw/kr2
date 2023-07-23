/* vim:ts=4:sw=4:et:so=10:
 *
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

	while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b' ) {
            putchar('\\');
            putchar('b');
        } else {
		    putchar(c);
        }
	}


    return 0;
}
