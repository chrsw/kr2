/* vim:ts=4:sw=4:et:so=10:
 *
 * trim.c
 *      Remove trailing blanks, tabs, newlines.
 *
 * Input:
 *      Null terminated C string.
 *
 */

#include <string.h>

int trim(char s[]) {

    int n;

    for (n = strlen(s)-1; n >= 0; --n)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}
