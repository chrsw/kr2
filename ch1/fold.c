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
 * TODO:
 *      Fill a dynamic array while reading input
 *      If there's a blank character, set to INBLANK
 *      and stop a count
 *      If a non-blank character occurs before the n-th column or new line
 *      then sent to inspace and keep counting, recover the count.
 *      If there's a new line then only write output to that count
 *      If there's the n-th column, then only write to that count pulus a new
 *      line.
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
