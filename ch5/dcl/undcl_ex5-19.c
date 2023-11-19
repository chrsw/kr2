/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * undcl_ex5-19.c
 *      Avoid unnecessary parentheses in undcl.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o undcl-ex5-19 undcl_ex5-19.c dcl.c gettoken.c\
 *      getch.c
 *
 * Run:
 *      $ ./dcl < dcl_test.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gettoken.h"
#include "dcl.h"


int tokentype;
char name[MAXTOKEN];           /* identifier name */
char token[MAXTOKEN];           /* identifier name */
char datatype[MAXTOKEN];       /* data type = char, int, etc. */
char out [1000];               /* output string */


/* undcl:  convert word descriptions to declaration */
int main(int argc, char *argv[]) {

    int type;
    char temp[1100+1];              /* TBD: why this value? */
    int parens = 0;
    (void)argc;
    (void)argv;

    out[0] = '\0';

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS) {
                strcat(out,token);
                parens++;
            }
            else if (type == '*') {
                if (parens > 0) {
                    sprintf(temp, "(*%s)", out);
                    parens--;
                }
                else
                    sprintf(temp, "*%s", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out,temp);
            } else 
                printf("invalid input at %s\n", token);
    }
    
    printf("%s\n", out);
    return 0;
}
