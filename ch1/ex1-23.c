/*
 * ex1-23.c
 *
 * Description:
 *      Write a program to remove all comments from a C program. Don't
 *      forget to handle quoted strings and character constants properly.
 *      C comments do not nest.
 *
 * Input:
 *      A C source file on standard input.
 *
 * Output:
 *      The same C source file but without block comments, on standard output.
 *
 * Design:
 *      Thoughts about this design. Read in characters from standard input.
 *      Check for the start of comment pattern. If the comment pattern starts
 *      check for the next character completing the block comment sequence.
 *      If in a comment block, do not print characters. Keep checking for
 *      end of block comment sequence.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -o 1-23 1-23.c
 *
 * Run:
 *      $ ./ex1-23 < file.c
 *
 * Notes:
 *      This exercise will focus on block comments only, since line based
 *      comments were introduced after this book was published.
 *
 */

#include <stdio.h>


#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

#define NORMAL   0      /* normal, non-comment text, print */
#define IN_SLASH 2      /* in possible start of comment block */      
#define IN_BLOCK 3      /* in comment block */
#define OUT_STAR 4      /* possibly exiting comment block */


int main(void) {

    int c, state;
    int pc = 0; 
    state = NORMAL;
    
    while ((c = getchar()) != EOF ) {
        if (state == NORMAL) {
            if (c == '/') {
                state = IN_SLASH;
                pc = c;
                continue;
            }
        }     
        if (state == IN_SLASH) {
            if (c == '*') {
                state = IN_BLOCK;
            } else
                state = NORMAL;
        }
        if (state == IN_BLOCK) {
            if (c == '*') {
                state = OUT_STAR;
                continue;
            }
        }
        if (state == OUT_STAR) {
            if (c == '/') {
                state = NORMAL;
                continue;
            } else
                state = IN_BLOCK;
        }
        if (state == NORMAL) {
            //if (pc != 0 ) putchar(pc);
            putchar(c);
            pc = 0;
        }
    }

    return 0;
}
