/*
 * tree.c
 *      Create or add to a tree.
 *
 * Description:
 *      Section 6.5.
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
#include "ch6_strdup.h"
#include "cow.h"
#include "talloc.h"
#include "tnode.h"
#include "tree.h"

/* addtree:  add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{

    int cond;
    
    if (p == NULL){                 /* a new word has arrived */
        p = talloc();               /* make a new node */
        p->word = ch6_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;                 /* repeated word */
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
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}