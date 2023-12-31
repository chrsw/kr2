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
 *      The baseline of this app is from the 'cow' application which builds a list
 *      of words and their occurances. cow = Count Occurence of Words. The
 *      application for exercise 6-3 is supposed to track every non-trivial word
 *      and maintain a list of lines in which every word appears.
 *
 *      To support this, we can modify the tree node data structure.The node
 *      structure will include a pointer to an array of numbers instead of an
 *      integer count.
 *      Every time a new occurance of a word is encountered on a new line,
 *      addtree() will add another element to the lines array for that word
 *      structure.
 *
 *      The lines array in each word node needs to be a dynamic array
 *      because we don't know how many lines the word will apear on.
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
 *      $ gcc -o ex6-3 ex6-3.c ex6_3_tree.c ex6_3_getword.c \
 *      talloc.c ch6_strdup.c getch.c
 *      - or -
 *      $ make ex6-3
 *
 * Run:
 *      $ ./ex6-3 < test/input_ex6_3.txt
 * 
 * TODO:
 *      Use dynamic memory for list of line nubmers words appear.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "ex6_3_tnode.h"
#include "ex6_3_getword.h"
#include "ex6-3.h"
#include "tree.h"

int linen = 1;              /* Used to track which line number we're on */

/* ex6-3:  print word cross-reference */
int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (ex6_3_getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word);
    }
    printf("WORD\t\tCOUNT\tLINES\n");
    treeprint(root);
    return 0;
}
