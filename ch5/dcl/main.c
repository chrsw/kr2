/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl.c
 *      dcl app main().
 *
 * Description:
 *      Template for code and solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
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
 *      $ gcc -Wall -Wextra -Wpedantic -o dcl main.c dcl.c gettoken.c getch.c
 *
 * Run:
 *      ./dcl # Then type input line, hit enter, hit Ctrl-D
 *
 * Notes:
 *      Seems to work better when input is typed into stdin rather then
 *      redirected from file.
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "gettoken.h"

int tokentype;			/* type of the last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc. */
char out [1000];		/* output string */

/* convert declaration to words */
int main(int argc, char *argv[]) {

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