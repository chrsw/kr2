/*
 * ex6-2.c
 *      Print short variable names in a C program.
 *
 * Description:
 *      White a program that reads a C program and prints in alphabetical
 *      order each group of variable names that are identical in the
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
 *      print the variable declaration keywords listed above.
 *
 * Output:
 *      List of words seen on the input and a count of their respective
 *      occurrences.
 *
 * Design:
 *      See section 6.5. Self-referential Structures.
 *
 * Build:
 *      $ gcc -o ex6-2 ex6-2.c tree.c getword.c talloc.c ch6_strdup.c getch.c
 *      - or -
 *      $ make ex6-2
 *
 * Run:
 *      $ ./ex6-2 <name length> < main.c
 *
 * TODO:
 *      Support structs and typedefs.
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

#define MAXVAR 100

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
    struct tnode *root;
    char word[MAXVAR];
    char name[MAXVAR];
    int length = 6;

    /* Get variable name length from command line if available */ 
    if (argc == 2)
        length = atoi(argv[1]);
    /* Clamp length to something sane */
    if (length < 1 || length > 100)
        length = 6;

    root = NULL;
    while (getword(word, length) != EOF) {
        if (istype(word)) {
            /* if a type is found, the next word might be a variable name */
            if (getword(name, length) == EOF)
                break;
            if (isalpha(name[0]))
                root = addtree(root, name);
        }
    }
    treeprint(root);
    return 0;
}

/* istype:  matches a C data type */
bool istype(char *s)
{
    bool ret = false;
    int i;
    for (i = 0; i <= 6; i++)
        if (!strcmp(types[i],s))
            ret = true;
    return ret;
}
