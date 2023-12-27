/* vim:ts=4:sw=4:et:
 *
 * ex6-1.c
 *      getword() implementation for Chapter 6, exercise 1 solution.
 *
 * Description:
 *      Get words from input. 
 *      Handle string literals.
 *      Handle preprocessor control lines.
 *
 * Input:
 *      char *w:    String to store word, if found.
 *      int lim:    Max word length.
 *
 * Output:
 *      Returns first character of word found.
 *      Copies found word into character string passed as 1st parameter.
 *
 * Design:
 *      TBD
 *
 * Build:
 *      $ gcc -Wall -c ex6-1.c
 * TODO:
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
int getword(char *word, int lim) {

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
 *
 * TODO:        Find out if we're in a comment or not.
 */
int bgetword(char *word, int lim)
{
    int c;
                                            /* Don't count words in */
                                            /* comments */
    bool cmt[3] = {false, false, false};    /* track comment state */ 
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


/* ex6_1_getword:  getword with added capabilities from Exercise 6.1
 *
 * Original description:
 *
 *      This function gets it's input from buffered standard input via
 *      getch().
 *      
 *      This function is called in a while loop looking for words or EOF.
 *
 *      Skips the leading white space characters (isspace returns true if
 *      character in argument is form-feed, newline, carraige return,
 *      horizontal tab or vertical tab).
 *
 *      Checks that the first non-whitespace character is not EOF. Function
 *      will return if the first non-whitespace character is EOF, setting the
 *      first character of word in the parameter to NULL then returning EOF.
 *
 *      If the first character found is not an upper case letter or a lower
 *      case letter (isalpha() == islower() || isupper() then the function
 *      also sets the 1st charcter of the input word string to
 *      NULL then immediately returns the non-letter character.
 *
 *      Once the EOF and non-letter checks are passed, then we assume we are
 *      at the start of a word. This function then calls getch() repeatedly
 *      until a non-alphanumber character is found (isalnum() == 
 *      isalpha() || isdigit()).
 *
 *      In the word building loop, the found alphanumeric characters are added
 *      to the string in the 1st parameter.
 *
 *      When the first non-letter or non-number character is found in the
 *      word building loop, the loop pushes the non-letter or non-number
 *      character back into the input buffer (it will be the next char read)
 *      and the loops ends.
 *
 *      After the word-building loops ends (other failed checks would have
 *      ended the function even earlier) then the function puts a NULL
 *      character at the end of the word string in the parameter list and
 *      returns the first letter of the found word.
 *
 *      When a first word character is a non-letter, it is not pushed back
 *      into the input buffer. Instead the caller is given a single character
 *      word (NULL) in the word string in the parameter list and given
 *      the non-letter character in the integer returned by the function.
 *
 * Solution description:
 *      In the solution 6-1 version of getword(), the same as the original
 *      description still applies execpt for the following.
 *
 *      Now when a underscore character is encountered, it is treated as part
 *      of the word that is in. This is a very simple version of the solution
 *      and probably still has some problems.
 *      
 *      In order to avoid being confused by string literals, the double-
 *      quote character is now ingored along with leading white space.
 *      If a quote appears in the middle of a word, instead of at the
 *      beginning or end, this strategy will break. But this is not common.
 *
 *      Should words in comments be excluded or included?
 *      The text doesn't say exactly but future exercises make it seem
 *      like words in comments should be excluded, so that's what we'll
 *      do for exercise 6-1.
 *
 *      To remove words in comments we can use a static variable that will
 *      be set to true when inside a comment and false when not inside a
 *      comment. To do this we'll use a state machine to work our way inside
 *      a comment and a state machine to get out. Comments start with '/',
 *      then '*'.
 *
 *      The text example of getword() includes '*' and '/' as individual
 *      words. See getword_test5_output.txt.
 *
 *      isalnum(*) and isalnum(/) returns zero (0).
 *
 *      This solution will skip all words (or any characters) inside the old
 *      C-style comment blocks, '/' + '*'.
 * 
 */
int ex6_1_getword(char *word, int lim)
{
    int c;
    char *w = word;
    static bool comment = false;

    /* Find the first non-white space */
    /* And non-quote character to accept words inside string literals */
    while (isspace(c = getch()) || c == '"') 
        ;
    if (c != EOF && c != '/')               /* still haven't reached EOF... */
        *w++ = c;                           /* or found a comment */

    /* Look for comments, if found skip like skipping whitespace */
    if (c == '/')
        if ((c = getch()) == '*') 
            while ((c = getch()) != '/');
                ;

   if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

   for ( ; --lim > 0; w++)
        /* Include uderscores as part of words */
        if (!(isalnum(*w = getch())) && (*w != '_')) {
            ungetch(*w);
            break;
    }
    *w = '\0';
    return word[0];

}
