/* vim:ts=4:sw=4:et:so=10:
 *
 * getint.c
 *      Get next integer from input.
 *
 * Description:
 *      Excerpt from section 5.2.
 *
 * Input:
 *      Standard input.
 *
 * Other info:
 *      Returns, build, notes, etc. 
 *
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);                        /* defined in getch.c */
void ungetch(int);

int getint(int *pn) {
   
    int c, sign;
 
    while (isspace(c = getch())) 
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                  
        return 0;                       /* it's not a number */
    }
    sign = (c == '-') ? -1 : 1;          /* determine the sign */
    if (c == '+' || c == '-')
        c = getch();
    /* convert ascii values into numeric values */
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c); 

    return c;
}
