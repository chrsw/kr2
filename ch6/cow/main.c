/*
 * main.c
 *      main() driver for cow - Count Occurance of Words. Count each time a
 *      word appears on input.
 *
 * Original text description:
 *      "Suppose we want to handle the more general problem of counting
 *      the occurances all the words in some input. Since the list of
 *      words isn't known in advance we can't convenientlyh sort it and
 *      use a binary search. Yet we can't do a linear search for each
 *      word as it arrives to see if it's already been seen; the program
 *      would take too long.
 *      - snip -
 *      One solution is to keep the set of words seen so far sorted at all
 *      times, by placing each word into its proper position ino the order
 *      in which it arrives. We will use a data structure called a 'binary
 *      tree'.
 *
 * Modifications:
 *      Not all words are counted on the input unless ORIG_GETWORD is defined.
 *
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      List of words seen on the input and a count of their respective
 *      occurances.
 *
 * Design:
 *      See section 6.5. Self-referential Structures.
 *
 * Build:
 *      $ gcc -o cow main.c tree.c getword.c talloc.c ch6_strdup.c getch.c
 *      - or -
 *      $ make
 *
 * Run:
 *      $ ./cow < test/input.txt
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tnode.h"
#include "getword.h"
#include "cow.h"
#include "tree.h"

/* cow:  word frequency count */
int main(int argc, char *argv[])
{

    (void)argc;
    (void)argv;

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}
