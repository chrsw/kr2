/* vim:ts=4:sw=4:et:so=10:
 *
 * strcscmp.c
 *      Compare strings s, t. Return -1 if s less than t, 0 if s equal to t
 *      and 1 if s greater than t.
 *      Case insensitive.
 *
 *
 * Build:
 *      $ gcc -c strcscmp.c
 *
 */

#include <ctype.h>
#include <string.h>

int strcscmp(char *s, char *t);

int strcscmp(char *s, char *t) {

    int ret = 0;
    char *s2 = s;
    char *t2 = t;

    while (*s != '\0') {
        if (tolower(*s) > tolower(*t))
            return 1;
        else if (tolower(*s) < tolower(*t))
            return -1;
        else {
            s++;
            t++;
        }
    }

    if (strlen(t2) > strlen(s2))
       return -1; 

    return ret;
}
