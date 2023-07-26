/* vim:ts=4:sw=4:et:so=10:
 *
 * ex5-6_getline.c
 *      Partial solution to exercise 5-6. Use pointers instead of array.
 *
 * $ gcc -c ex5-6_getline.c
 */

#include <stdio.h>

/* getline: read a line into s, return length */
int ex5_6_getline(char *s, int lim) {

    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        *s++ = c;
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s++ = '\0';
    return i;
}
