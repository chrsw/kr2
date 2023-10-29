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

int tokentype;			/* type of the last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc. */
char out [1000];		/* output string */


int main(int argc, char *argv[]) {

    while (gettoken() != EOF) {     /* first token on line */
        strcpy(datatype, token);     /* is the datatype */
        out[0] = '\0';
        dcl();                      /* parse rest of line */
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
