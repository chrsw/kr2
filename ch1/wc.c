/*
 * wc.c
 *      Word count. Bare bones version of the Unix program wc.
 *
 * Description:
 *      Simple wc example from section 1.5.4 Word Counting.
 *      Part of solution 1-11.
 *
 * Input:
 *      Stream of text.
 *
 * Build:
 *      $ gcc -o wc wc.c
 *
 * Test:
 *      $ ./wc < ex1-11.txt
 */

#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

int main(void) {

    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    
    while ((c = getchar()) != EOF ) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT ) {
            state = IN;
            ++nw;
        }
        else { /* do nothing */ }
    }

    printf("%d %d %d\n", nl, nw, nc);    
    return 0;
}
