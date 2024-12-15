/*
 * getword.c
 *      Different versions of getword() from Chapter 6.
 *
 * Input:
 *      Text on standard input.
 *
 * Returns:
 *      First letter of found word, word in parameter string or EOF.
 */

#include <ctype.h>
#include <stdio.h>

int getch(void);
int getchb(void);
void ungetch(int);


/* getword:  get next word or character from input K&R2, page 136  */
int getword(char *word, int lim) {

    int c;
    char *w = word;
    while (isspace(c = getch()))    /* find the first non-white space */
        ;
    if (c != EOF)                   /* still haven't reached EOF... */
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


/* bgetword:  get next word or character from input. Handles underscores. */
int bgetword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF) 
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


/* getwordb:  get next word or character from input */
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
