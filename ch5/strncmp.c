/* vim:ts=4:sw=4:et:so=10:
 *
 * strncmp.c
 *      Compare strings s, t. Return -1 if s less than t, 0 if s equal to t
 *      and 1 if s greater than t. Up to n characters.
 *
 * Description:
 *      Partial solution to exercise 5-5.
 *
 * Input:
 *      2 strings and a length passed as parameterds.
 *
 * Build:
 *      $ gcc -c strncmp.c
 *
 */

#include <stdio.h>

int ch5_strncmp(char *s, char *t, int n);

int ch5_strncmp(char *s, char *t, int n) {

    int ret = 0;
    int len_s, len_t;
    len_s = 0;
    len_t = 0; 
    char *s2 = s;
    char *t2 = t;
    int n2 = n;

    while (*s2++ && n2--) ++len_s;
    n2 = n;
    while (*t2++ && n2--) ++len_t;
    
    if (len_s > len_t)
        return 1;
    else if (len_s < len_t)
        return -1;
    else
        ;
  
    /* strings are same length up to n */ 
    while (*s != '\0' && n-- ) {
        if (*s > *t)
            ret = 1;
        else if (*s < *t)
            ret = -1;
        else
            ;
    }
        
    return ret;
}
