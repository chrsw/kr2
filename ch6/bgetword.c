/* vim:ts=4:sw=4:et:
 *
 * bgetword.c
 *      Better version of getword(). Handles underscores (_) and string
 *      constants.
 *
 * Description:
 *      By "handle string constants" we mean don't ignore the "s and
 *      consider words inside the ""s.
 *
 * Input:
 *      Stream of characters on standard input.
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
    while (isspace(c = getch()) || c == '"')
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
