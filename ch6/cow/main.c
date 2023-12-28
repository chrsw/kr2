/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * main.c
 *      main() driver for cow - Count Occurance of Words. Count each time a
 *      word appears on input.
 *
 * Description:
 *      Template for code and solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
 *
 * Input:
 *      Describe the expected input.
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
