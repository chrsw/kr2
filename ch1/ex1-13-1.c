/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-13.c
 *      Write a program to print a histogram of the lengths of words in its
 *      input. 1st part of exercise 13: horizontal orientation of histogram.
 *
 * Description:
 *
 * Input:
 *      Stream of text.
 *
 */

#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

int lengths[25] = {0};

int main(void) {

    int c, wl, state, i;
    
    state = OUT;
    wl = 0;
    
    while ((c = getchar()) != EOF ) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            lengths[wl]++;
            wl = 0;
        }
        else if (state == OUT ) {
            state = IN;
            wl = 1;
        }
        else { 
            wl++; 
        }
    }

    for (i =  1; i < 25; i++ ) printf("%d\n", lengths[i]);
    return 0;
}
