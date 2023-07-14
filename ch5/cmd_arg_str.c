/* vim:ts=4:sw=4:et:so=10:
 *      Vim modeline for consistent editor settings across files.
 *
 *  cmd_arg_str.c
 *      Build a string from command line arguments. Practice for chapter 5
 *      exercises.
 *
 * Input:
 *      Command line parameters
 *
 * Build:
 *      $ gcc -o cmd-arg-str getline.c cmd_arg_str.c
 *
 * Run:
 *      $ ./cmd-arg-str one two three four
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

/* cmd-arg-str: build a string using cmd line arguments */
int main(int argc, char *argv[]) {

    char line[MAXLINE] = {'0'};

    int i = 0;

    char *p = (char *)malloc(MAXLINE);
    p[0] = '\0';

    ++argv;                                 /* ignore the command name */

    while (--argc > 0) {                    /* copy each command line arg */
        strcat(p, *argv++);                 /* to the end of array */
        strcat(p, " ");
    }
    
    return printf("line: %s\n", p);
   
}
