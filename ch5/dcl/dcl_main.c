/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl_main.c
 *      dcl app main().
 *
 * Input:
 *      C declaration.
 *
 * Description:
 *      Excerpt for text section 5.12. A stated in the text, this application
 *      implements a recursive-descent parser.
 *
 * Output:
 *      Plain text English description of the C declaration on the input.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o dcl dcl_main.c dcl.c gettoken.c\
 *      getch.c
 *
 * Run:
 *      ./dcl # Then type input line, hit enter, hit Ctrl-D
 *      - or -
 *      ./dcl < dcl_test.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "gettoken.h"

int tokentype;			/* type of the last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];           /* identifier name */
char datatype[MAXTOKEN];       /* data type = char, int, etc. */
char out [1000];               /* output string */

/* convert declaration to words */
int main(int argc, char *argv[]) {

    /* silence -Wunused-parameter */
    (void)argc;
    (void)argv;

    while (gettoken() != EOF) {     /* first token on line */
        strcpy(datatype, token);     /* is the datatype */
        out[0] = '\0';
        dcl();                      /* parse rest of line */
        if (tokentype != '\n')
            printf("dcl: syntax error: 0x%02X\n", tokentype);
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
