/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-13.c
 *      Write a program to print a histogram of the lengths of words in its
 *      input. 2nd part of exercise 13: vertical orientation of histogram.
 *
 * Input:
 *      Stream of text.
 *
 */

#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */
#define MAXLENGTH 25
#define NROWS 25
#define NCOLUMNS 80

int lengths[MAXLENGTH] = {0};

int main(void) {

    int c, wl, state;
    int i, j, k; 

    state = OUT;
    wl = 0;
   
    /* read standard input and store word lengths */ 
    while ((c = getchar()) != EOF ) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;                /* finished a word */ 
            lengths[wl]++;              /* add one to this length */
        }
        else if (state == OUT ) {
            state = IN;
            wl = 1;
        }
        else { 
            wl++; 
        }
    }

    /* most terminals are 80 columns by 25 rows by default. 
     * this application only counts words up to 25 letters. 
     * go through each column and figure out if a history bar 
     * needs to be printed based on the length count.
     */
    for (k = NROWS; k > 0; k--) {
        for (i = 0; i < MAXLENGTH; i++)
            if (lengths[i] >= k)
                printf(" |");
            else
                printf("  ");
        printf("\n");
    }
    
    return 0;
}





