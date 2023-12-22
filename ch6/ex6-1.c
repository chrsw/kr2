/* vim:ts=4:sw=4:et:
 *
 * ex6-1.c
 *      getword() implementation for Chapter 6, exercise 1 solution.
 *
 * Description:
 *      Get words from input. 
 *      Handle string literals.
 *      Handle preprocessor control lines
 *
 * Build:
 *      $ gcc -Wall -c ex6-1.c
 * TODO:
 *      Handle comments.
 *      Write test driver.
 *      Clean warnings.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int getch(void);
int getchb(void);
void ungetch(int);

typedef enum comments {
    NONE = 0,       /* Not in comment */
    START,          /* '/' */
    IN_BLOCK,       /* Block comment started with '/' then '*' */
    IN_LINE,        /* One a comment line '/' then '/' */
    END_BLOCK      /* start of end of block comment '*' */
} comstate;


/* Are we at the start of a line or not? */
static bool newline = false;

/* getword: get next word or character from input 
 *          very similar version in K&R2, page 136 
 */
int getword(char *word, int lim)
{

    int c;
    char *w = word;

    while (isspace(c = getch())) /* find the first non-white space */
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

/* bgetword:    Get next word or character from input.
 *              Better version, handles underscores.
 *              Handles string constants.
 *
 * returns:
 *              Last character in word.
 *              Word found pointed to by word parameter.
 *              0 - if word skipped.
 *              word[0] non-alphanumeric if word is skipped.
 *
 *              Preprocessor lines start at the beginning of a line
 * TODO:        Find out if we're in a comment or not.
 */
int bgetword(char *word, int lim)
{
    int c;
                                            /* Don't count words in */
                                            /* comments */
    bool cmt[3] = {false, false, false};  /* track comment state */ 
    char *w = word;

    comstate comment_state = NONE;

    /* Preprocessor statements start on a new line 
     * The first thing we do is test for new line and if we're at 
     * the start of a preprocessor statement then ignore the rest of
     * of the line.
     */
    if ((c = getch()) == '\n') {
        /* Start of a new line */
        if ((c = getch()) == '#') {
            /* Ignore rest of line */
            while ((c = getch()) != '\n')
                ;
        } else {
            ungetch(c);
        }
    } else {
        ungetch(c);
    }


    /* Comments, like this one, start anywhere with '/' followed by 
     * '*'. Comments wont nest (for this solution). Any words found
     * inside a comment block are skipped. Comments end with '*' followed
     * by '/' 
     */
    if ( c == '/' && comment_state == NONE) {
        comment_state = START;
    } else if (c == '*' && comment_state == START) {
        comment_state = IN_BLOCK;
    } else if (c == '*' && comment_state == IN_BLOCK) {
        comment_state = END_BLOCK;
    } else if (c == '/' && comment_state == END_BLOCK){
        comment_state = NONE;
    }


    /* Look for 1st non-white space or opening quote for string literals */ 
    /* Closing " is handled later */
    while (isblank(c = getch()) || c == '"') 
        ;
    if (c != EOF)                   /* still haven't reached EOF... */
        *w++ = c;
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isgraph(*w = getch()) || *w == '"') {
            ungetch(*w);
            break;
        }
    *w = '\0';
    if (comment_state == NONE)
        return word[0];
    else
        return 0;
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
    if (!isalpha(c) && c != '_') {
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
