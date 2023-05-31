/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-9.c
 *      Copy input to output, replacing one or more blanks by a single
 *      blank.
 *
 * Description:
 *      Copy standard input to standard output. Squeeze mutliple spaces 
 *      and tabs into one blank.
 *
 * Input:
 *      Stream of text on standard input.
 *
 */

#include <stdio.h>

#define TEXT 0
#define SPACE 1

int main(int argc, char *argv[])
{

    int c;
    int space = TEXT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && space == TEXT) {
            space = SPACE;
            putchar(c);
        } else if ( c == ' ' && space == SPACE) {
            /* skip printing this char */
        } else {
            space = TEXT;
            putchar(c);
        }
    }

    return 0;
}
