/* vim:ts=4:sw=4:et:so=10:
 *
 * wc.c
 *      Barebones version of the UNIX program wc.
 *
 * Description:
 *      Simple wc example from section 1.5.4 Word Counting.
 *
 * Input:
 *      Stream of text.
 *
 *
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