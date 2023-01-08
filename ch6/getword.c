/* vim:ts=4:sw=4:et:
 *
 * getword.c
 *
 * Description:
 *      Details
 *
 * Input:
 *
 */

#include <ctype.h>
#include <stdio.h>

int getch(void);
int getchb(void);
void ungetch(int);

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        if (c == EOF)
            return '\0';
        else
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
