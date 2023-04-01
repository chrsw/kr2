/* vim:ts=4:sw=4:et:
 *
 * tabcol.c
 *      Print the length of each line on standard input in units of
 *      tab widths (8).
 *
 * Description:
 *      Helper code on the path to Chapter 1, Exercise 20.
 *      
 * Input:
 *      Text input with line breaks.
 *
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c, i, t;
  
    i = 0;
    t = 0;

    // read from stdin
    while ((c = getchar()) != EOF) {
        ++i;
        t = i % 8;
        if (c == '\n') {
            i = 0;
        }
        if ((t == 0) && (i > 0))
            printf("\u2588");
        else
            printf("%c",c);
    }

    return 0;
}
