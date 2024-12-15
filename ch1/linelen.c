/*
 * linelen.c
 *      Print the length of each line on standard input.
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
    int c, i;
  
    i = 0;

    // read from stdin
    // TBD: should a blank line be length '0' or '1'?
    while ((c = getchar()) != EOF) {
        ++i;
        if (c == '\n') {
            printf("%d\n", i);
            i = 0;
        }
    }

    return 0;
}
