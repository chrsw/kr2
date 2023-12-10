/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl_main.c
 *      dcl app main().
 *
 * Description:
 *      Excerpt from text section 5.12. A stated in the text, this application
 *      implements a recursive-descent parser. For more details see the other
 *      source files specified in the build instructions.
 *      Allow simple function arguments.
 *
 * Input:
 *      C declaration.
 *
 * Output:
 *      Plain text English description of the C declaration on the input.
 *
 * Design:
 *      The grammar specified in Section 5.12:
 *          dcl:            optional *'s direct-dcl
 *          direct-dcl:     name
 *                          (dcl)
 *                          direct-dcl()
 *                          direct-dcl[optional size]
 *      Modified dcl for adding functional argument type:
 *          dcl:            optinal *'s direct-dcl
 *          direct-dcl:     name
 *                          (dcl)
 *                          direct-dcl(optional function argument type)
 *                          direct-dcl[optional size]
 * 
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o dcl_arg dcl_main_arg.c dcl_arg.c gettoken_arg.c\
 *      getch.c
 *
 * Run:
 *      ./dcl_arg # Then type input line, hit enter. Ctlr-D to quit.
 *      - or -
 *      ./dcl_arg < dcl_test.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl_ex5-20.h"
#include "gettoken.h"

int tokentype;			/* type of the last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];           /* identifier name */
char datatype[MAXTOKEN];       /* data type = char, int, etc. */
char out [1000];               /* output string */
char arg[MAXTOKEN];
int ret = 0;

/* convert declaration to words */
int main(int argc, char *argv[]) {

    /* silence -Wunused-parameter */
    (void)argc;
    (void)argv;

    while (gettoken() != EOF) {                 /* first token on line */
        strcpy(datatype, token);      /* is the datatype */
        out[0] = '\0';
        dcl();                                  /* parse rest of line */
        if (tokentype != '\n') {
            printf("dcl: syntax error: tokentype = 0x%02X ('%c')\n", tokentype, tokentype);
            ret = 1;
        }
        printf("%s: %s %s\n\n", name, out, datatype);
    }
    return ret;
}
