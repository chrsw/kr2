/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * undcl_main.c
 *      Convert word descriptions to declaration.
 *
 * Build:
 *      $ gcc -o dcl dcl_main.c
 *
 * Run:
 *      $ ./dcl < dcl_test.txt
 *
 */

#include <stdio.h>

/* undcl:  convert word descriptions to declaration */
int main(int argc, char *argv[]) {

    int type;
    char temp[MAXTOKEN];
    
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS) 
                strcat(out,token);
            else if (type == '*') {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out,temp);
            } else 
                printf("invalid input at %s\n", token);
    }
    return 0;
}
