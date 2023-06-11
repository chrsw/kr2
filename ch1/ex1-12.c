/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-12.c
 *      Write a program that prints its inputs one word per line.
 *
 * Description:
 *
 * Input:
 *      Text.
 *
 */

#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

int main(void) {

    int c, state;
    
    state = OUT;
    
    while ((c = getchar()) != EOF ) {
        if (c != ' ' && c != '\t')
            putchar(c);
        if (c == '\n') {
            state = OUT;
        }
        else if (c == ' ' || c == '\t') {
            state = OUT;
            putchar('\n');
        }
        else if (state == OUT ) {
            state = IN;
        }
        else { /* do nothing */ }
    }

    return 0;
}
