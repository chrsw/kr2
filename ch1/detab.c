/* vim:ts=4:sw=4:et:
 *
 * detab.c
 *      Solution to Chapter 1, Exercise 20.
 *
 * Description:
 *      Write a program detab that replaces tabs in the input with the proper
 *      number of blanks to space to the next tab stop. Assume a fixed set
 *      of tab stops, say ever n columns. Should n be a variable or a symbolic
 *      parameter?
 *      
 * Input:
 *      Text input with line breaks. Lines can't be too long.
 * 
 * Build:
 *      $ gcc -o detab detab.c
 *
 */

#include <stdio.h>

#define TABSTOP 9

int main(int argc, char *argv[])
{
    int c, i, t, j;
    i = j = t = 0;

    // read every character from standard input
    // execute loop for every char
    while ((c = getchar()) != EOF) {

        i++;

        if (c == '\n') {                    // line pos running count
            i = 0;                       
        }
    
        // any time a tab char is found
        // replace the tab char with the number of spaces
        // until the next tab column
        if (c == '\t') {
            // by default tab columns are every eight chars 
            // and 1st column is 1
            j = TABSTOP - (i % TABSTOP);

            for (j; j > 0; j--) {
                printf(" ");
                i++;
            }
        } else 
            printf("%c",c);
        }

    return 0;
}
