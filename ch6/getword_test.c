/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * getword_test.c
 *      Test driver for various getword() implementations.
 *      Used for exercise 6-1.
 *
 * Description:
 *      Call getword() for running with test input.
 *
 * Input:
 *      Plain text words in varioius formats.
 *
 * Build:
 *      $ gcc -o getword_test getword_test.c getword.c getch.c
 *      - or -
 *      $ gcc -o getword_test getword_test.c ex6-1.c getch.c
 *
 * Run:
 *      $ ./getword_test < getword_test.txt
 *      - or -
 *      $ ./getword_test < getword_testN.txt > getword_testN_output.txt
 *
 */

#include <stdio.h>
#include <string.h>

/* functions defined in ex6-1.c, getword functions */
int getword(char *, int);
int bgetword(char *, int);
int getwordb(char *, int);
int ex6_1_getword(char *, int);
/* words is an array of 10 words, each word can be 99 letters */
/* one element is used by the '\0' (NULL) character */
char words[20][100];


int main(int argc, char *argv[]) 
{

    (void)argc;
    (void)argv;

    char word[100];
    int count = 0;
    int i = 0;

    while (ex6_1_getword(word, 100) != EOF) {
        if (word[0] != '\0') {
            count++;
            strcpy(words[i++ % 20], word);
        }
    }

    printf("word count: %6d\n", count);
    printf("last 20 words (not in order):\n");
    for (i = 0; i < 20; i++)
        printf("\t%s\n", words[i]);

    return 0;
}
