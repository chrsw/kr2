/*
 * ch3_atoi.c
 *      Convert s to integer, version 2.
 *
 * Description:
 *      From K&R2 section 3.5
 *
 * Input:
 *      Character string.
 *
 * Build:
 *      $ gcc -c ch3_atoi.c
 *
 */

#include <ctype.h>

/* chapter 3 atoi; convert s to integer; version 2 */
int ch3_atoi(char s[]) {

    int i, n, sign;
    
    for (i = 0; isspace(s[i]); i++) /* skip white sapce */
        ;
    
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')  /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
