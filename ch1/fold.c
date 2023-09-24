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
 *      $ ./fold < input.txt
 *
 */

#include <stdio.h>

int main(void) {

    unsigned int i = 0;
    int c;
    while ((c=getchar()) != EOF) {
        if (c == '\n') i = 0;
        if (++i == 79)  { 
            putchar('\n');
            i = 0;
        }
        putchar((char)c);
    }
    if (i) putchar('\n');
    return 0;
}
