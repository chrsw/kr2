/* vim:ts=4:sw=4:et:
 *
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

    while ((c = getchar()) != EOF) {
        ++i;
        if (c == '\n') {
            printf("%d\n", i);
            i = 0;
        }
    }

    return 0;
}
