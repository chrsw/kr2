/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-2.c
 *      Convert string s to double. Support scientific notation.
 *      e.g. 123.45-e6
 *
 * Description:
 *      Only a single positive digit exponent is supported.
 *      According to IEEE-754, float is a 32-bit type with 8 bits
 *      for the exponent and double is a 64-bit type with 11 bits for
 *      the exponent. 2^11 = 2048.
 *      The largest exponent size supported in this solution is 4 digits.
 *      Negative and postive mantissas are supported.
 *      Negative and positive exponents are supported.
 *
 * Input:
 *      String representing float or double.
 *      ex. 123.45e3
 *
 * TODO:
 *      Use own code instead of math lib for pow().
 *      Use own code instead of std lib for atoi().
 *
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

double ex4_2_atof(char s[]);            /* Std lib already has  */
                                        /* atoi(), atof(), etc. */
double ex4_2_atof(char s[])
{

    double val, power;
    int i, sign, exp;
    double d_exp;
    char *exp_loc = NULL;               /* for searching exponent */
    const char eE[] = "eE";                
    int exp_sign = 1;

    exp = 0;        /* default value of exp will be zero */
                    /* exp means * 10 ^ exp */
                    /* 10 ^ 0 = 1, so zero is a safe value */

    for (i = 0; isspace(s[i]); i++)     /* skip leading white space */
        ;

    exp_loc = strpbrk(s, eE);           /* find exponent */

    if (exp_loc != NULL)                /* ex is location of e/E, if any */
        exp_loc++;                      /* exponent value starts here */

    if (exp_loc != NULL)                /* get exponent sign */
        switch (*exp_loc) {
            case '+':
                exp_sign = 1;
                exp_loc++;
                break;
            case '-':
                exp_sign = -1;
                exp_loc++;
                break;
            default:
                break;
        }
    //exp_sign = (*exp_loc == '-') ? -1 : 1;
    // exp_loc now points at the first digit of the exponent, if any
    if (exp_loc != NULL) {            
        exp = atoi(exp_loc);
    }
    d_exp = pow(10,exp_sign * exp);     /* exp means * 10 ^ exp */
                                        /* we don't want zero ruining */
                                        /* the calculations later */

#ifdef DEBUG       
    printf("%s: e: %d\n", __func__, exp);
    printf("%s: d_exp: %f\n", __func__, d_exp);
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

    return sign * d_exp * val / power;
}
