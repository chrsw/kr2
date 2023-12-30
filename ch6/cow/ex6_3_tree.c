/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ex6_3_tree.c
 *      Create or add to a tree.
 *
 * Description:
 *      This verison is to support exercise 6-3.
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
 *      See makefile or main.c.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ch6_strdup.h"
#include "ex6-3.h"
#include "talloc.h"
#include "ex6_3_tnode.h"
#include "tree.h"

/* addtree:  add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{

    int cond;
    
    if (p == NULL){                 /* a new word has arrived */
        p = talloc();               /* make a new node */
        p->word = ch6_strdup(w);
        p->count = 1;
        p->lines = (int *)malloc(sizeof(int)+1);
        p->lines[0] = linen;
        p->lines[1] = -1;           /* indicates no more lines found */
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0){
        p->count++;
        p->lines = (int *)realloc(p->lines, p->count+1);                 /* repeated word */
        p->lines[p->count] = linen;
        p->lines[p->count+1] = -1;
    }
    else if (cond < 0)              /* less than into left subtree */
        p->left = addtree(p->left, w);
    else                            /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint:  in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%s\n", p->word);
        treeprint(p->right);
    }
}