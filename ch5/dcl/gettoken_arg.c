/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * gettoken.c
 *      Find the next token. From Chapter 5, Section 5.12 Complicated
 *      Declarations.
 *
 * Description:
 *      gettoken() skips any leading whitespace then finds the next token
 *      in the input; a "token" is a name, pair of parentheses, a pair of
 *      brackets perhaps including a number, or any other single character.
 *
 * Input:
 *      Standard input via getch().
 *
 * Returns:
 *      token:      string containing the found token.
 *      tokentype:  integer enum containing the token category: name,
 *                  parentheses, brakets.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      Used in the dcl app. See dcl build instructions in dcl_main.c.
 *
 * Run:
 *      Used in the dcl app. See dcl run instructions in dcl_main.c.
 *
 */

#include <ctype.h>
#include <string.h>
#include "getch.h"
#include "dcl.h"
#include "gettoken.h"

/* gettoken:  return next token */
int gettoken(void) {

    int c;
    char *p = token;
   
    /* skip whitespace */ 
    while((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else 
        return tokentype = c;
    
    return 0;
}
