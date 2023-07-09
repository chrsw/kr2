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
 * Returns:
 *      Return value and parameter update to match integer representation
 *      on standard input.
 *
 * Build:
 *      Compile into larger app or statically link in after:
 *      $ gcc -c getint.c
 *
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);                                /* defined in getch.c */
void ungetch(int);

int getint(int *pn) {
   
    int c, sign;
 
    while (isspace(c = getch())) 
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                  
        return 0;                               /* it's not a number */
    }
    sign = (c == '-') ? -1 : 1;                 /* determine the sign */
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())      /* conver ascii characters */ 
        *pn = 10 * *pn + (c - '0');             /* to numeric values */
    *pn *= sign;
    if (c != EOF)
        ungetch(c); 

    return c;
}
