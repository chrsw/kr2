/* vim:ts=4:sw=4:et:so=10:
 *
 * getline.c
 *      getline() from section 1.9. Get a line of text from standard input.
 *
 * $ gcc -c getline.c
 */

#include <stdio.h>

/* getline: read a line into s, return length */
int sec1_9_getline(char s[], int lim) {

    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
