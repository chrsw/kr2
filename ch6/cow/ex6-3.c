/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ex6-3.c
 *      Print a cross reference of wrods in a document.
 *
 * Description:
 *      White a cross-referencer that prints a list of all words in a
 *      document, and for each word, a list of the line numbers on which it
 *      occurs. Remove noise words like "the", "and" and so on.
 *
 * Design:
 *      TBD
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      List of words seen on the input and a list of their line
 *      appearances.
 *
 * Design:
 *      Based off the code in section 6.5. Self-referential Structures.
 *
 * Build:
 *      $ gcc -o ex6-3 ex6-3.c tree.c getword.c talloc.c ch6_strdup.c getch.c
 *      - or -
 *      $ make ex6-3
 *
 * Run:
 *      $ ./ex6-3 <name length> < test_input.txt
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "tnode.h"
#include "getword.h"
#include "cow.h"
#include "tree.h"

#define MAXLEN 100

/* ex6-3:  print word cross-reference */
int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXLEN];

    root = NULL;
    while (getword(word, MAXLEN) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word);
    }
    treeprint(root);
    return 0;
}
