/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl_ex5-20.c
 *      Expand dcl to handle declarations with function argument types,
 *      qualifiers like cosnt, and so on.
 *
 * Description:
 *      Function argument types, e.g.:
 *      int f(int x);
 *      int g(void *p);
 *      
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      The grammar specified in Section 5.12:
 *          dcl:            optional *'s direct-dcl
 *          direct-dcl:     name
 *                          (dcl)
 *                          direct-dcl()
 *                          direct-dcl[optional size]
 *      Modified dcl for adding functional argument types:
 *          dcl:            optinal *'s direct-dcl
 *          direct-dcl:     name
 *                          (dcl)
 *                          direct-dcl(optional function arguments types)
 *                          direct-dcl[optional size]
 * 
 * Implementation:
 *      Details on how the code implements the design.      
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o dcl-ex5-20 dcl_main_ex5-20.c \
 *      dcl_ex5-20.c gettoken_ex5-20.c getch.c
 *
 * Run:
 *      $ echo "int f(int)" | ./dcl-ex5-20
 *
 * Notes:
 *      Additional functionality to be added to dcl across exercise copies of
 *      dcl.c, gettoken.c and dcl_main.c.
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "gettoken.h"

int is_datatype(char *s);

/* dcl:  parse a declarator */
void dcl(void) {

    int ns;
    
    for (ns = 0; gettoken() == '*'; )       /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}


/* dirdcl:  parse a direct declarator */
void dirdcl(void) {
    
    int type;
    
    if (tokentype == '(') {                 /* ( dcl )  */
        dcl();
        if (tokentype != ')')
            printf("dirdcl(): error: missing )\n");
    } else if (tokentype == NAME) {          /* variable name */
        strcpy(name, token);
    } else if (is_datatype(token)) {
        strcat(out, "function taking ");
        strcat(out, token);
        strcat(out, " returning");
        fn_args = 1;
    }
    else {
        printf("dirdcl(): error: expected name or (dcl).");
        isprint(tokentype) ? printf(" tokentype: %c\n", tokentype) :
                             printf(" tokentype: %d\n", tokentype);
        printf("token: %s\n", token);
    }
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


/* is_datatype:  check to see if a token is a valid datatype */
int is_datatype(char *s) {
    
    int ret = 0;
    int idx = 0;
    char *types[] = {"char", "double", "float", 
                     "int", "long", "short", 
                     "unsigned", "void", NULL};

    while (types[idx] != NULL) {
        if (strcmp(types[idx], s) == 0) {
            ret = 1;
            break;
        }
        idx++;
    }
    return ret;
}

