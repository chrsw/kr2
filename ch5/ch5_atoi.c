/* vim:ts=4:sw=4:et:so=10:
 *
 * ch5_atoi.c
 *      Convert s to integer, pointer version.
 *
 * Description:
 *      Part of exercise 5-6.
 *
 * Input:
 *      Character string.
 *
 * Build:
 *      $ gcc -c ch5_atoi.c
 *
 */

#include <ctype.h>

/* chapter 5 atoi; convert s to integer; pointer version */
int ch5_atoi(char *s) {

    int i, n, sign;
    char *s2 = s;
    i = 0;
   
    while (isspace(*s2))             /* skip white space */
        s2++;
    
    sign = (*s2 == '-') ? -1 : 1;
    if (*s2 == '+' || *s2 == '-')  /* skip sign */
        s2++;
    for (n = 0; isdigit(*s2); )
        n = 10 * n + (*s2++ - '0');
    return sign * n;
}
