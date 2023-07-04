/* vim:ts=4:sw=4:et:so=10:
 *
 * getop.c
 *      Get next operator or numeric operand.
 * 
 * Description:
 *      Excerpt from section 4.3 part of Reverse Polish Notation (RPN)
 *      calculator application.
 *
 * Input:
 *      Describe the expected input.
 *
 * Build:
 *      See rpn.c
 *
 */

#include <ctype.h>
#include <stdio.h>                              /* for EOF */

#define NUMBER '0'

int getch(void);
void ungetch(int c);

int getop(char s[]) {

    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;                               /* not a number */
    i = 0;
    if (isdigit(c))                             /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                               /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}



