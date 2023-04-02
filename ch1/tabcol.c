/* vim:ts=4:sw=4:et:
 *
 * tabcol.c
 *      Highlight colums that fall on tab colums with block character.
 *
 * Description:
 *      Helper code on the path to Chapter 1, Exercise 20.
 *      
 * Input:
 *      Text input with line breaks.
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
        if (c == '\n') {            // rest tab count every line
            i = 0;
        }
        if ((t == 0) && (i > 0))    // if we're on a tab column,
            printf("\033[7m%c\033[m", c);
        else
            printf("%c",c);
    }

    return 0;
}
