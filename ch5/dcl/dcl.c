/*
 * dcl.c
 *      Core DCL routines dcl() and dirdcl().
 *
 * Description:
 *      This file implements the two routines dcl() and dirdcl() for parsing
 *      the simplified C declaration grammar specified in section 5.12 
 *      Complicated Declarations.
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.      
 *
 * Build:
 *      How to build this program or a build example (incl make targets).
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
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
    
    if (tokentype == '(') {                 /* ( dcl )  */
        dcl();
        if (tokentype != ')')
            printf("dirdcl(): error: missing )\n");
    } else if (tokentype == NAME)           /* variable name */
        strcpy(name, token);
    else
        printf("dirdcl(): error: expected name or (dcl)\n");
    while ((type=gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}
