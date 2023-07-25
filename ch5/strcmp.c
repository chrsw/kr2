/* vim:ts=4:sw=4:et:so=10:
 *
 * strcmp.c
 *      Compare strings s, t. Return -1 if s less than t, 0 if s equal to t
 *      and 1 if s greater than t.
 *
 * Description:
 *      Template for code and solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
 *
 * Input:
 *      Describe the expected input.
 *
 * Build:
 *      $ gcc -c strcmp.c
 *
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Nots:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>

int ch5_strcmp(char *s, char *t) {

    int ret = 0;
    int len_s, len_t;
    len_s = 0;
    len_t = 0; 
    char *s2 = s;
    char *t2 = t;

    while (*s2++) ++len_s;
    while (*t2++) ++len_t;
    
    if (len_s > len_t)
        return 1;
    else if (len_s < len_t)
        return -1;
    else
        ;
  
    /* strings are same length */ 
    while (*s != '\0') {
        if (*s > *t)
            ret = 1;
        else if (*s < *t)
            ret = -1;
        else
            ;
    }
        
    return ret;
}
