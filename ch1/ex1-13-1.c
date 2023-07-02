/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-13.c
 *      Write a program to print a histogram of the lengths of words in its
 *      input. 1st part of exercise 13: horizontal orientation of histogram.
 *
 * Input:
 *      Stream of text.
 *
 */

#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */
#define MAXLENGTH 25

int lengths[MAXLENGTH] = {0};

int main(void) {

    int c, wl, state;
    int i, j; 

    state = OUT;
    wl = 0;
   
    /* read standad input and store word lengths */ 
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

    /* show lengths as a histogram; one '-' = one count */
    for (i = 1; i < MAXLENGTH; i++) {
        for (j = 0; j < lengths[i]; j++){
            printf("-");
        }
        printf("\n");
    }    


    return 0;
}
