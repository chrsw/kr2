/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl_main_ex5-20.c
 *      Exercise 5-20 solution main().
 *
 * Description:
 *      Modified dcl application from section 5.12 of the text, this  version
 *      implements a recursive-descent parser of a C declaration with support
 *      for function argument types. Function argument types can be omitted
 *      and the application should still work.
 *
 * Input:
 *      C declaration w/ function argument types (optional).
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
 *          dcl:            optional *'s direct-dcl
 *          direct-dcl:     name
 *                          (dcl)
 *                          direct-dcl(optional function argument types)
 *                          direct-dcl[optional size]
 * 
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o dcl-ex5-20 dcl_main_ex5-20.c \
 *        dcl_ex5-20.c gettoken_ex5-20.c getch.c
 *
 * Run:
 *      ./dcl-ex5-20 # Then type input line, hit enter. Ctrl-D to quit.
 *      - or -
 *      ./dcl_ex5-20 < test/dcl_test_arg2.txt
 *
 * TODO:
 *      Friendlier function argument descriptions. E.g., for 
 *      void foo(char *, int *)
 *      "foo: function taking pointer to char and pointer to int"
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl_ex5-20.h"
#include "gettoken.h"

int tokentype;			        /* type of the last token */
char token[MAXTOKEN];		    /* last token string */
char name[MAXTOKEN];            /* identifier name */
char datatype[MAXTOKEN];        /* data type = char, int, etc. */
char out [1000];                /* output string */
char arg[MAXTOKEN];
int ret = 0;                    /* application returns non-zero if error */
unsigned int debug = 0;                  /* set to 1 for debug output */

/* convert declaration to words */
int main(int argc, char *argv[]) {

    /* silence -Wunused-parameter */
    (void)argc;
    (void)argv;

    while (gettoken() != EOF) {                 /* first token on line */
        strcpy(datatype, token);                /* is the datatype */
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
