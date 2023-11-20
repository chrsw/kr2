/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dcl_ex5_18.c
 *      Solution to exercise 5-18.
 *
 * Description:
 *      Make dcl recover from input errors.
 *
 * Input:
 *      C declaration. Declarations are a subset of legal C declarations and
 *      must only span 1 line.
 *
 * Output:
 *      Plain text English description of the C declaration on the input.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o dcl-ex5-18 dcl_ex5-18.c dcl.c gettoken.c\
 *      getch.c
 *
 * Run:
 *      $ ./dcl # Then type input line, hit enter, hit Ctrl-D
 *      - or -
 *      $ ./dcl < dcl_test.txt # to redirect from a file
 *      - or -
 *      $ echo "int *x" | ./dcl-5-18
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "gettoken.h"
#include "getch.h"


int tokentype;			        /* type of the last token */
char token[MAXTOKEN];		    /* last token string */
char name[MAXTOKEN];            /* identifier name */
char datatype[MAXTOKEN];        /* data type = char, int, etc. */
char out [1000];                /* output string */
int is_datatype(char *s);

/* convert declaration to words */
int main(int argc, char *argv[]) {

    /* silence -Wunused-parameter */
    (void)argc;
    (void)argv;

    datatype[0] = '\0';
    strcpy(datatype, "int");   /* integer by default */
    while (gettoken() != EOF) {     /* first token on line */
        if (is_datatype(token)) {    /* is the datatype */
            printf("datatype is %s\n", token);
            strcpy(datatype, token);
        } else {
            printf("missing datatype: token = %s\n", token);
            printf("                  name = %s\n", name);
            printf("                  tokentype = 0x%02X\n", tokentype);
            ungetch(tokentype);
        }
        out[0] = '\0';
        dcl();                      /* parse rest of line */
        if (tokentype != '\n')
            printf("dcl: syntax error: 0x%02X\n", tokentype);
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
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



