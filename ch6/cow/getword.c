/*
 * File:
 *      getword.c
 *
 * Description:
 *      Inspired from Section 6.3.
 *
 * Input:
 *      Text on standard input.
 */

#include <ctype.h>
#include <stdio.h>
#include "getch.h"
#include "getword.h"

#ifdef ORIG_GETWORD
/* getword: get next word or character from input 
 *          very similiar version in K&R2, page 136 
 */
int getword(char *word, int lim) {

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
#else
/* getword:  get next word or character from input, very similiar version in K&R2, 
 * page 136 with added capabilities from Exercise 6.1
 */
int getword(char *word, int lim)
{
    int c;
    char *w = word;

    /* Find the first non-white space */
    /* And non-quote character to accept words inside string literals */
    while (isspace(c = getch()) || c == '"')
        ;
    if (c != EOF && c != '/' && c != '#')   /* still haven't reached EOF... */
        *w++ = c;                           /* or found a comment */

    /* Look for comments, if found skip like skipping white space */
    if (c == '/')
        if ((c = getch()) == '*')
            while ((c = getch()) != '/');
                ;

    /* Look for start of preprocessor statement '#' */
    if (c == '#')
        while ((c = getch()) != '\n');
            ;

   if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

   for ( ; --lim > 0; w++)
        /* Include underscores as part of words */
        if (!(isalnum(*w = getch())) && (*w != '_')) {
            ungetch(*w);
            break;
    }
    *w = '\0';
    return word[0];
}
#endif