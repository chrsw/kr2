/*
 * ex5-1.c
 *      As written in the text, getint() treats a + or - not followed by a
 *      digit as a valid representation of 0. Fix it to push such a character
 *      back on the input.
 *
 * Description:
 *      Solution to excercise 5.1.
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
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            c = *pn;                    /* return orginal value if error */
            pn = NULL;
            return c;
        }
    }
    /* convert ascii values into numeric values */
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c); 

    return c;
}
