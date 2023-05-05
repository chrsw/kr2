/* vim:ts=4:sw=4:et:so=10:
 *
 * cpl_atof.c
 *      Convert string s to double.
 *
 * Description:
 *      Template file for solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
 *
 * Input:
 *      Describe the expected input.
 *
 * Other info:
 * Returns, build, notes, etc. 
 * 
 *
 */

#include <ctype.h>

double cpl_atof(char s[]);

double cpl_atof(char s[])
{

    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    
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

    return sign * val / power;
}
