/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * File:
 *      getword.c
 *
 * Description:
 *      Different versions of getword() from Chapter 6.
 *
 * Input:
 *      Text on standard input.
 */

#include <ctype.h>
#include <stdio.h>
#include "getch.h"
#include "getword.h"


/* getword: get next word or character from input 
 *          very similiar version in K&R2, page 136 
 */
int getword(char *word, int lim)
{

    int c;
    char *w = word;

    while (isspace(c = getch())) /* find the first non-whitespace */
        ;
    if (c != EOF)               /* still haven't reached EOF... */
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
    }
    *w = '\0';
    return word[0];

}

/* bgetword: Get next word or character from input.
 *           Better version, handles underscores.
 */
int bgetword(char *word, int lim)
{

    int c;
    char *w = word;
    while (isspace(c = getch())) /* find the first non-whitespace */
        ;
    if (c != EOF)               /* still haven't reached EOF... */
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isgraph(*w = getch())) {
            ungetch(*w);
            break;
    }
    *w = '\0';
    return word[0];

}


/* getwordb: get next word or character from input */
int getwordb(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getchb()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getchb())) {
        ungetch(*w);
        break;
    }
    *w = '\0';
    return word[0];

}
