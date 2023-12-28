/* vim:ts=4:sw=4:et:
 *
 * ex6-1.c
 *      getword() implementations, including for Chapter 6, exercise 1
 *      solution.
 *
 * Description:
 *      Get words from input. 
 *      Handle string literals.
 *      Handle preprocessor control lines.
 *      Handle comments.
 *      Handle underscores
 *
 * Input:
 *      char *w:    String to store word, if found.
 *      int lim:    Max word length.
 *
 * Output:
 *      Returns first character of word found.
 *      Copies found word into character string passed as 1st parameter.
 *
 * Original description:
 *      This function gets its input from buffered standard input via
 *      getch().
 *      
 *      This function is called in a while loop looking for words or EOF.
 *
 *      Skips the leading white space characters (isspace() returns true if
 *      character in argument is form-feed, newline, carriage return,
 *      horizontal tab or vertical tab).
 *
 *      Checks that the first non-white space character is not EOF. Function
 *      will return if the first non-white space character is EOF, setting the
 *      first character of word in the parameter to NULL then returning EOF.
 *
 *      If the first character found is not an upper case letter or a lower
 *      case letter (isalpha() == islower() || isupper() then the function
 *      also sets the 1st character of the input word string to
 *      NULL then immediately returns the non-letter character.
 *
 *      Once the EOF and non-letter checks are passed, then we assume we are
 *      at the start of a word. This function then calls getch() repeatedly
 *      until a non-alphanumeric character is found (isalnum() == 
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
 *      description still applies except for the following.
 *
 *      Now when a underscore character is encountered, it is treated as part
 *      of the word that is in. This is a very simple version of the solution
 *      and probably still has some problems.
 *      
 *      In order to avoid being confused by string literals, the double-
 *      quote character is now ignored along with leading white space.
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
 *      This solution will also try a similar approach with the C
 *      preprocessor character '#': ignore everything from # to the end
 *      of the line.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o getword_test getword_test.c\
 *      ex6-1.c getch.c
 *
 * Run:
 *      $ ./getword_test < getword_test6.txt
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int getch(void);
int getchb(void);
void ungetch(int);

/* ex6_1_getword:  getword with added capabilities from Exercise 6.1 */
int ex6_1_getword(char *word, int lim)
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
