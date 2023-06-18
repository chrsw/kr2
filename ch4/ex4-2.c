/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-2.c
 *      Convert string s to double. Support scientific notation.
 *      e.g. 123.45-e6
 *
 * Description:
 *      Only a single positive digit exponent is supported.
 *
 * Input:
 *      ex. 123.45e3
 *
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

double ex4_2_atof(char s[]);            /* Std lib already has  */
                                        /* atoi(), atof(), etc. */
double ex4_2_atof(char s[])
{

    double val, power;
    int i, sign, exp;

    char *exp_loc = NULL;               /* for searching exponent */
    const char eE[] = "eE";                

    exp = 0;        /* default value of exp will be zero */
                    /* exp means * 10 ^ exp */
                    /* 10 ^ 0 = 1 */

    for (i = 0; isspace(s[i]); i++)     /* skip leading white space */
        ;

    exp_loc = strpbrk(s, eE);           /* find exponent */
    if (exp_loc != NULL)            
        exp = *++exp_loc - '0';

    if (exp) exp = pow(10,exp);         /* exp means * 10 ^ exp */
                                        /* we don't want zero ruining */
                                        /* the calculations later */

// For debugging...
#ifdef DEBUG       
    printf("%s: e: %d\n", __func__, exp);
#endif

    /* extract leading sign character, if any */ 
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
       val = 10.0 * val + (s[i] - '0'); 
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * exp * val / power;
}
