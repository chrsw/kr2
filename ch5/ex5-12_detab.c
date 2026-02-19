/*
 * ex5-12_detab.c
 *      Solution to Chapter 5, Exercise 12.
 *
 * Build:
 *      $ gcc -o ex5-12_detab ex5-12_detab.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 9

int main(int argc, char *argv[])
{
    int c, i, t, j;
    i = j = t = 0;
    int ts = 0;                 /* tab stops, from user */
    int sc = 0;                 /* starting column, from user */
    int ui[2];                  /* user input */

    while (--argc > 0 && ((*++argv)[0] == '-' || (*argv)[0] == '+')) {
        printf("detab: %s\n", *argv);
        ui[i++] = atoi((*argv));
        //++argv;
    }

    if (i != 0) {
        i = 0;
        if (ui[0] < 0) ui[0] = -ui[0];
        printf("detab: tab stops = %d\tstarting column = %d\n", ui[1], ui[0]);
    } else {
        ui[0] = 0;
        ui[1] = TABSTOP;
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
            j = ui[1] - (i % ui[0]);

            for (j; j > 0; j--) {
                printf(" ");
                i++;
            }
        } else 
            printf("%c",c);
        }

    return 0;
}
