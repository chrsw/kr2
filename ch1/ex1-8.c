/* vim:ts=4:sw=4:et:
 *
 * ex1-8.c
 *      Write a program to count blanks, tabs and newlines.
 *
 * Description:
 *
 * Input:
 *      Stream of text on standard input.
 *
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    int c;

    long nb = 0;                // count of blanks, tabs, newlines
    long nt = 0;    
    long nn = 0;         

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                nb++;
                break;
            case '\t':
                nt++;
                break;
            case '\n':
                nn++;
                break;
        }
    }

    printf("blanks\t\t%ld\ntabs\t\t%ld\nnewlines\t%ld\n", nb, nt, nn);

    return 0;
}
