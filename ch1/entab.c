/* vim:ts=4:sw=4:et:
 *
 * entab.c
 *      Solution to Chapter 1, Exercise 21.
 *
 * Description:
 *      Write a program entab that replaces strings of blanks in the input
 *      with the proper number of blanks to space to the next tab stop.
 *      Assume a fixed set of tab stops, say every n columns.
 *      
 * Input:
 *      Text input with line breaks. Lines can't be too long.
 *
 * Returns:
 *      Total chars read.
 *
 */

#include <stdio.h>
#include <stdbool.h>

#define TABWIDTH 8                              // Using a tab width of 8

int main(int argc, char *argv[])
{
    int c, i, t;
    i = 0;
    t = 0;
    int space = 0;

    // read every character from standard input
    // exec loop for every char
    while ((c = getchar()) != EOF) {

        i++;
        if (c == '\n') i = 0;
        // any time a space char is found, start or keep counting
        if (c == ' ') {
            if (++space == TABWIDTH) {
                // found enough spaces in a row
                printf("\t");
                // the tab char will stop at the next tabstop
                // (probably multiples of 8)
                // i contains the column number
                t = space;
                while (t-- > i % TABWIDTH) {
                    printf(" ");
                }
                space = 0;
            }
        } else {
            // print the non-space char, the total number of spaces if less
            // than TABWIDTH or a tab char.
            for (t = 0; t < space; t++) printf(".");
            space = 0;
            printf("%c",c);
        }
    }

    return i;
}
