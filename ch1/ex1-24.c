/*
 * ex1-23.c
 *      Write a program to check a C program for rudimentary syntax errors
 *      like unbalanced parentheses, brackets and braces. Don't forget about
 *      quotes, both single and double, escape sequences and comments.
 *
 * Description:
 *      Starting with the solution from 1-23 and going from there. That
 *      solution strips comments from C source text.
 *
 * Input:
 *      A C source file.
 *
 * Output:
 *      Returns 0 or 1 to the OS based on if the C source input file
 *      was valid or not. 0 for valid. 1 for invalid.
 *
 * Design:
 * 
 * Implementation:
 *      Checks to see ['s, {'s and ('s are balanced outside of comments.
 *      Checks to see ''s, "'s and \'s are even outside of comments.
 *
 * Build:
 *      $ gcc -o 1-24 1-24.c
 *
 * Run:
 *      $ ./ex1-24 < file.c
 *
 * Notes:
 *      Only the most basic checking is included in this solution.
 *      See ex1-24.txt for more details.
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

    int oparens,         /* counts */
        obraces,         
        obrackets, 
        cparens,
        cbraces,
        cbrackets,
        squotes,
        dquotes,
        escapes = 0;
    
    int invalid = 0;    
    state = NORMAL;
    
    while ((c = getchar()) != EOF ) {
        if (state == NORMAL) {
            if (c == '/') {
                state = IN_SLASH;
                pc = c;
                continue;
            }
            if (c == '\(') oparens++;
            if (c == ')') cparens++;
            if (c == '{') obraces++;
            if (c == '}') cbraces++;
            if (c == '[') obrackets++;
            if (c == ']') cbrackets++;
            if (c == '\'') squotes++;
            if (c == '\"') dquotes++;
            if (c == '\"') escapes++;
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
            pc = 0;
        }
    }

    if ((oparens != cparens) ||
        (obraces != cbraces) ||
        (obrackets != cbrackets))
        invalid = 1;

    if (((squotes % 2) == 1) ||
        ((dquotes % 2) == 1) ||
        ((escapes % 2) == 1))
        invalid = 1;

    return invalid;
}
