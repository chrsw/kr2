/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl_ex5_18.c
 *      Solution to exercise 5-18.
 *
 * Description:
 *      Make dcl recover from input errors.
 *
 * Input:
 *      C declaration.
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

int is_datatype(char *s);

/* convert declaration to words */
int main(int argc, char *argv[]) {

    (void)argc;
    (void)argv;

    while (gettoken() != EOF) {     /* first token on line */
        if (is_datatype(token))
            strcpy(datatype, token);     /* is the datatype */
        else
            strcpy(datatype, "int");
        out[0] = '\0';
        dcl();                      /* parse rest of line */
        if (tokentype != '\n')
            printf("dcl: syntax error: 0x%02X\n", tokentype);
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}


/* is_datatype:  check to see if a token is a valid datatype */
int is_datatype(char *s)
{
   return (!strcmp(s, "void"));
}
