/*
 * entab2.c
 *      Partial solution to Chapter 5, Exercise 11.
 *
 * Description:
 *     Modify the programs 'entab' and 'detab' to accept a list of tab
 *     stops as arguments. Use the default tab settings if there are no
 *     arguments. 
 *          
 * Input:
 *      Text input with line breaks. Lines can't be too long.
 *      Command line arguments.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c, i, t;
    int args;
    int tabstops[100] = {0};
    int tabcount = 0;
    int ts = 0;
    int j = 0;
    i = 0;
    t = 0;

    args = argc;

    while (--args > 0) {
        tabstops[i++] = atoi(*++argv);
    }
    
    for (i = 0; i < argc-1; i++)    
        printf("%d\n", tabstops[i]);
    i = 0;

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
            // use tabstops from list created on command line
            tabcount = tabstops[ts] == 0 ? 9 : tabstops[ts];
            j = tabcount - (i % tabcount);

            for (j; j > 0; j--) {
                printf(" ");
                i++;
            }
            ts++;
        } else 
            printf("%c",c);
        }

    return 0;
}
