/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * getword_test.c
 *      Test driver for various getword() implementations.
 *      Useful for exercise 6-1.
 *
 * Description:
 *      Call getword() (and similar functions) for running with test input.
 *
 * Input:
 *      Plain text words in varioius formats.
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
 *      $ gcc -o getword_test getword_test.c getword.c getch.c
 *      - or -
 *      $ gcc -o getword_test getword_test.c ex6-1.c getch.c
 *
 * Run:
 *      $ ./getword_test < getword_test.txt
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>

/* functions defined in ex6-1.c, getword functions */
int getword(char *, int);
int bgetword(char *, int);
int getwordb(char *, int);

int main(int argc, char *argv[]) 
{

    char word[100];
    int count = 0;

    while (bgetword(word, 100) != EOF)
        count++;

    printf("word count: %6d\n", count);

    return 0;
}
