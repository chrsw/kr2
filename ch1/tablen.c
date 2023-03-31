/* vim:ts=4:sw=4:et:
 *
 * linelen.c
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
    // TBD: should a blank line be length '0' or '1'?
    while ((c = getchar()) != EOF) {
        ++i;
        t = i % 8;
        if (c == '\n') {
            printf("%d\n", t);
            i = 0;
        }
    }

    return 0;
}
