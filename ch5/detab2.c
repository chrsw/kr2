/* vim:ts=4:sw=4:et:
 *
 * detab.c
 *      Solution to Chapter 5, Exercise 11.
 *
 * Description:
 *      Modify the programs 'entab' and 'detab' (written as exercises in
 *      chapter 1) to accept a list of tab stops as arguments. Use default
 *      tab settings if there are no arguments.
 *      
 * Input:
 *      Text input with line breaks. Lines can't be too long.
 * 
 * Build:
 *      $ gcc -o detab2 detab2.c
 *
 * Run:
 *      $ cat tab_test.txt | ./detab2.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 9

int main(int argc, char *argv[])
{
    int c, i, t, j;
    i = j = t = 0;
    
    int ts = TABSTOP;

    // see if a command line arg changes ts value.
    if (argc == 2 ) {
        argv++;
        ts = atoi(*argv);
        printf("found tab stop argument: %d\n", ts);
    }

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
            j = ts - (i % ts );

            for (j; j > 0; j--) {
                printf(" ");
                i++;
            }
        } else 
            printf("%c",c);
        }

    return 0;
}
