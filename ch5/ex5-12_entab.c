/*
 * ex5-12_entab.c
 *      Solution to Chapter 5, Exercise 12. See ex5-12.txt.
 *
 * Run example:
 *      $ ./ex5-12_entab -4 +6
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TABWIDTH 8                              // Using a tab width of 8



int main(int argc, char *argv[])
{
    int c, i, t;
    i = 0;
    t = 0;
    int space = 0;

    int ts = 0;                 /* tab stops, from user */
    int sc = 0;                 /* starting column, from user */
    int ui[2];                  /* user input */

    while (--argc > 0 && ((*++argv)[0] == '-' || (*argv)[0] == '+')) {
        printf("entab: %s\n", *argv);
        ui[i++] = atoi((*argv));
        //++argv;
    }

    if (i != 0) {
        i = 0;
        if (ui[0] < 0) ui[0] = -ui[0];
        printf("entab: tab stops = %d\tstarting column = %d\n", ui[1], ui[0]);
    } else {
        ui[0] = 0;
        ui[1] = TABWIDTH;
    }


    // read every character from standard input
    // exec loop for every char
    while ((c = getchar()) != EOF) {

        i++;
        if (c == '\n') i = 0;
        // any time a space char is found, start or keep counting
        if (c == ' ') {
            if (++space == ui[1]) {
                // found enough spaces in a row
                printf("\t");
                // the tab char will stop at the next tabstop
                // (probably multiples of 8)
                // i contains the column number
                t = space;
                while (t-- > i % ui[1]) {
                    printf(" ");
                }
                space = 0;
            }
        } else {
            // print the non-space char, the total number of spaces if less
            // than TABWIDTH or a tab char.
            for (t = ui[0]; t < space; t++) printf(".");
            space = 0;
            printf("%c",c);
        }
    }

    return i;
}
