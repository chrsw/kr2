/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * gettoken_ex5-20.c
 *      Find the next token, including function arguments. 
 *
 * Description:
 *      gettoken() skips any leading whitespace then finds the next token
 *      in the input; a "token" is a name, pair of parentheses, a pair of
 *      brackets perhaps including a number, or any other single character.
 *      This version of gettoken() is for the solution to exercise 5-20 where
 *      function arguments are also expected to be identified.
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
 *      TBD 
 *
 * Implementation:
 *      TBD
 *
 * Build:
 *      Used in the dcl app. See dcl build instructions in main() file.
 *
 * Run:
 *      Used in the dcl app. See dcl run instructions in main() file.
 *
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "getch.h"
#include "dcl_ex5-20.h"
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
            if (debug) printf("%s(%d): tokentype = PARENS\n", __func__, __LINE__);
            return tokentype = PARENS;
        } else {
            ungetch(c);
            /* if name is already found and the next chars are alphanumeric 
             * then we found function arg(s). treat everything found before
             * the next ')' as part of one argument string even, though
             * multiple args can be split by ',' in the declaration. 
             */
            if (strlen(name) > 0) {
                (void)getch();
                p = token;
                for (*p++ = c; (c = getch()) != ')'; )
                    *p++ = c;
                *p = '\0';
                ungetch(c);   
                tokentype = ARG;
                if (debug) printf("%s(%d): tokentype = ARG\n", __func__, __LINE__);
                return tokentype = ARG;
            }
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        if (debug) printf("%s(%d): tokentype = BRACKETS\n", __func__, __LINE__);
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        if (strlen(name) == 0){
            if (debug) printf("%s(%d): tokentype = NAME\n", __func__, __LINE__);
            return tokentype = NAME;
        } else {
            if (debug) printf("%s(%d): tokentype = ARG\n", __func__, __LINE__);
            return tokentype = ARG;
        }
    } else if (c == ')') {
        strcpy(token, "()");
        if (debug) printf("%s(%d): tokentype = PARENS\n", __func__, __LINE__);
        return tokentype = PARENS;
    } else {
        tokentype = c;
        if (debug) printf("%s(%d): tokentype = 0x%02X ('%c')\n", __func__, __LINE__, tokentype, tokentype);
        return tokentype = c;
    }
    return 0;
}