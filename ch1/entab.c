/* vim:ts=4:sw=4:et:
 *
 * entab.c
 *      Solution to Chapter 1, Exercise 20.
 *
 * Description:
 *      Helper code on the path to Chapter 1, Exercise 20.
 *      
 * Input:
 *      Text input with line breaks. Lines can't be too long.
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c, i, t;
    int j = 0;
    i = 0;
    t = 0;

    // read every character from standard input
    // exec loop for every char
    while ((c = getchar()) != EOF) {

        i++;

        if (c == '\n') {                    // line pos running count
            i = 0;                       
        }
    
        // any time a tab char is found
        // replace the tab char with the number of spaces
        // until the next tab column
        if (c == '\t') {
            // tab columns are every eight chars and 1st column is 1
            j = 9 - (i % 9);

            for (j; j > 0; j--) {
                printf(" ");
                i++;
            }
        } else 
            printf("%c",c);
        }

    return 0;
}
