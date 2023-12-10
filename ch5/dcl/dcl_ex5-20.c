/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl_ex5-20.c
 *      Part of exercise 5-20 solution. Based on dcl.c.
 *
 * Description:
 *      This file implements the two routines dcl() and dirdcl() for parsing
 *      the simplified C declaration grammar specified in section 5.12 
 *      Complicated Declarations.
 *
 * Input:
 *      One C declaration per line. Limited sub-set of C declaration
 *      syntax.
 *
 * Output:
 *      English description of C declaration passed on the input.
 *
 * Design:
 *      Modified recursive decent parser from section 5.12 example.
 * 
 * Implementation:
 *      TBD
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o dcl-ex5-20 dcl_main_ex5-20.c\
 *      dcl_ex5-20.c gettoken_ex5-20.c getch.c
 *
 * Run:
 *      $ ./dcl-ex5-20 < test/dcl_test_arg.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl_ex5-20.h"
#include "gettoken.h"


/* dcl:  parse a declarator (dcl) */
void dcl(void) {

    int ns;
    
    for (ns = 0; gettoken() == '*'; )       /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}


/* dirdcl:  parse a direct declarator (dir-dcl) */
void dirdcl(void) {
    
    int type;
    
    if (tokentype == '(' || tokentype == ARG) {                 /* ( dcl )  */
        dcl();
        if (tokentype != ')' && tokentype != ARG)
            printf("dirdcl(): error: missing ), tokentype = %d\n", tokentype);
    } else if (tokentype == NAME)           /* variable name */
        strcpy(name, token);
    else if (tokentype == ')') 
        strcpy(arg, token);
    else
        printf("dirdcl(): error: expected name or (dcl), tokentype = %d\n", tokentype);
    while ((type=gettoken()) == PARENS || type == BRACKETS || type == '(' || type == ARG) {
        if (type == PARENS)
            strcat(out, " function returning");
        else if (type == BRACKETS){
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
        else if (type == ARG) {
            strcat(out, " function taking ");
            strcat(out, token);
            strcat(out, " and");
        } else {
        }
        
    }
}
