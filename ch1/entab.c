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
    int j = 0;
    i = 0;
    t = 0;

    // read from stdin
    while ((c = getchar()) != EOF) {

        i++;

        if (c == '\n') {                    // line pos running count
            i = 0;                       
        }

        
        // how many spaces until the next tab?
        // what is the current pos w.r.t. the previous tab?
        // how to get a number that increments every time a
        // character is read then resets on the next tab stop? 
        if (c == '\t') {
        
            //t = i % 9;                        // tab pos running count
            // a tab key will advance the cursor the number of spaces
            // until the next tab position.
            // here, instead of a tab being printed, this will print
            // the number of chars until the next tab.
            //printf("%d", 8 - (i % 8));
            j = 9 - (i % 9);
            //printf("%d", 8);
            for (j; j > 0; j--) {
                printf("%d", 9 - (i % 9));
                //printf(" ");
                i++;
            }
        } else 
            printf("%c",c);
        }

        //if ((t == 0) && (i > 0))            // highlight
        //    printf("\033[7m%c\033[m", c);   // on a tab column

    return 0;
}
