/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * main.c
 *      Print short variable name in a C program.
 *
 * Description:
 *      White a program that reads a C program and prints in alphabeti-
 *      cal order each group of variable names that are identical in the
 *      first 6 characters but different somewhere after. Don't count words
 *      within strings and comments. Make 6 a parameter that can be set
 *      from the command line.
 *
 * Design:
 *      The first thing we should do is just read a C file and find all
 *      C declarations. This means looking for the words "char", "double"
 *      float", "int", "long", "short".
 *
 *      Using the 'cow' application as a starting point, modify it just to
 *      print the variable declaration keywoards listed above.
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
#include <stdbool.h>
#include <string.h>
#include "tnode.h"
#include "getword.h"
#include "cow.h"
#include "tree.h"


const char types[][10] = {
    {"char"},
    {"double"},
    {"float"},
    {"int"},
    {"long"},
    {"short"}
}; /* types[] */

bool istype(char *s);


/* ex6-2:  print C variable names */
int main(int argc, char *argv[])
{

    (void)argc;
    (void)argv;

    int i = 0;
    struct tnode *root;
    char word[MAXWORD];


    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word);
        if (istype(word))
            printf("found type:\t%s\n", word);
    }
    //treeprint(root);
    return 0;
}

/* matches a C data type */
bool istype(char *s)
{
    bool ret = false;
    int i;
    for (i = 0; i < 6; i++)
        if (strcmp(types[i],s) == 0)
            ret = true;
    return ret;
}