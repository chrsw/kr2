/* vim:ts=4:sw=4:et:
 *
 * bgetword.c
 *      Better version of getword(). Handles underscores (_).
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
void ungetch(int);

/* bgetword: get next word or character from input, better version */
int bgetword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_') {
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
