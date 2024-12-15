/*
 * ex5-2.c
 *      Write getfloat(), the floating point analog of getint().
 *
 * Description:
 *      Converts fractional part using snippet from getop() in
 *      section 4.3.
 *
 * Input:
 *      Plain text on standard input.
 *
 * Returns:
 *      Double in parameter reference, non-zero for conversion success.
 *      
 * Build:
 *      $ gcc -c ex5-2.c
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);                                /* defined in getch.c */
void ungetch(int);

int getfloat(double *pd) {
   
    int c, sign, i;
    double d = 1.0;

    while (isspace(c = getch())) 
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                  
        return 0;                               /* it's not a number */
    }

    sign = (c == '-') ? -1 : 1;                 /* determine the sign */

    if (c == '+' || c == '-')
        c = getch();
                                                /* collect integer part */
     for (*pd = 0; isdigit(c); c = getch())     /* convert ASCII characters */ 
        *pd = 10 * *pd + (c - '0');             /* to numeric values */
    if (c == '.')                               /* collect fraction part */
        while (isdigit(c=getch())) {
            d /= 10;
            *pd += d * (c - '0');
        }
    *pd *= sign;
    if (c != EOF)
        ungetch(c); 

    return c;
}
