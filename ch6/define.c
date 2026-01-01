/*
 * define.c
 *      Solution 6-6. Simple #define processor. Stores #define'd names
 *      in a hash table using the table lookup routines from Section 6.6.
 *
 * Input:
 *      Plain text. Specifically with #define statements.
 *
 * Build:
 *      $ gcc -o define define.c getword.c getch.c table.c
 *
 * Run:
 *      $ ./define < ex6-6_test.txt
 *      - or -
 *      $ cat ex6-6_test.txt | ./define
 *
 */

#include <stdio.h>
#include <string.h>
#include "table.h"
#include "getch.h"
#include "getword.h"

/* words is an array of 10 words, each word can be 99 letters */
/* one element is used by the '\0' (NULL) character */
char words[40][100];


/* main:  process input and build symbol table. Look for the word
 * #define and add the next word to the table.
 */
int main(int argc, char *argv[]) 
{

    (void)argc;
    (void)argv;

    char word[100];
    char first_word[100];
    int count = 0;
    int i = 0;
    int in_define = 0;
    int first_word_set = 0;

    while (dgetword(word, 100) != EOF) {
        if (word[0] != '\0') {
            if (!first_word_set) {
                strcpy(first_word, word);
                first_word_set = 1;
            }
            count++;
            strcpy(words[i++ % 40], word);
            if (strcmp(word, "#define") == 0) {
                in_define = 1;
            } else if (in_define == 1) {
                install(word, " ");
                in_define = 0;
            }
        }
    }

    return 0;
}
