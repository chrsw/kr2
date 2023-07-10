/* vim:ts=4:sw=4:et:so=10:
 *
 * ex5-2.c
 *      Write getfloat(), the floating point analog of getint().
 *
 * Input:
 *      Standard input.
 *
 * Returns:
 *      Double.
 * Build:
 *      $ gcc -c ex5-2.c
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);                        /* defined in getch.c */
void ungetch(int);

int getfloat(double *pd) {
   
    int c, sign, i;
    double d = 1.0;

    *pd = 0; 

    while (isspace(c = getch())) 
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                  
        return 0;                       /* it's not a number */
    }
    sign = (c == '-') ? -1 : 1;          /* determine the sign */
    if (c == '+' || c == '-')
        c = getch();
    /* collect integer part */
     for (*pd = 0; isdigit(c); c = getch())      /* conver ascii characters */ 
        *pd = 10 * *pd + (c - '0');             /* to numeric values */
    if (c == '.')               /* collect fraction part */
        while (isdigit(c=getch())) {
            d /= 10;
            *pd += d * (c - '0');
        }
    *pd *= sign;
    if (c != EOF)
        ungetch(c); 

    return c;
}
