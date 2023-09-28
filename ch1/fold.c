/* vim:ts=4:sw=4:et:so=10:
 *
 * fold.c
 *      Exercise 1-22. Split long lines into specified column lengths.
 *
 * Description:
 *      Write a program to "fold" long input lines into two or more shorter
 *      lines after the last non-blank character that occurs before the n-th
 *      column of input. Make sure your program does something intelligent
 *      with very long lines and if there are no blanks or tabs before the
 *      specified column.
 *
 * Input:
 *      Text with arbitrarily long input lines.
 *
 * Output:
 *      Folded input.
 *
 * Build:
 *      $ gcc -o fold fold.c
 *
 * Run:
 *      $ ./fold < fold_test.txt
 *       - or -
 *      $ make fold # make will figure out what to do even without a target.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int c;
    int col = 0;                        /* column for last character found */
    unsigned int i = 0;
    int n = 72;
    char *line;


    if (argc == 2)
        n = atoi(*++argv);

    if (n < 1 || n > 1000)
        n = 72;
    printf("n = %d\n", n);

    line = (char *)malloc(n+2);
    if (line == NULL)
        return -1;

    while ((c=getchar()) != EOF) {
        /* split long lines */
        if (i <= n) {
            line[i++] = c;
            /* save column if character */
            if(!isspace(c)) { 
                col = i;
            }            
        } else {
            if (!isspace(c)) line[col++] = c;
            line[col++] = '\n';
            line[col++] = '\0';
            printf("%s", line);
            i = 0;
            col = 0;
        }
        /* print short lines */
        if (c == '\n') {
            if (col > 1)
                line[col++] = '\n';
            line[col++] = '\0';
            printf("%s", line);
            i = 0;
            col = 0;
        }
    }
    return 0;
}
