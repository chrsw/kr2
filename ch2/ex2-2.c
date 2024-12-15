/*
 * ex2-2.c
 *      Read a line into s, return length.
 *      Implement getline() without using '&&' or '||'.
 *
 * Input:
 *      Character array, limit
 *
 * Note:
 *      There appears to be an error from the text. The original getline()
 *      definition on page 29 uses this in the middle relational experession
 *      in the for loop:
 *          i<lim-1 && (c=getchar())!=EOF && c!='\n';
 *      but on page 42 this expression is used:
 *          1<lim-1 && (c = getchar()) != '\n' && c != EOF;
 *      Is this on purpose? Are these expressions equivalent?
 *
 */

#include <stdio.h>

#define MAXLINE 100

int _getline(void);             // _ to avoid confliect with standar lib
                                // definition

int _getline(void)
{
    int c, i;
    extern char line[];
    
    for (i = 0; !!(i < MAXLINE-1)
        + !!((c=getchar()) != EOF) + !!(c != '\n') == 3; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
