/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ex6_3_tree.c
 *      Create or add to a tree.
 *
 * Description:
 *      This version is to support exercise 6-3.
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
#include "ex6_3_tree.h"

/* addtree:  add a node with w, at or below p */
struct tnode *addtree(struct tnode **pp, char *w)
{
    int cond;
    struct tnode *p = *pp;

    if (p == NULL){                 /* a new word has arrived */
        p = talloc();               /* make a new node */
        p->word = ch6_strdup(w);
        p->count = 1;
        p->linen = linen;
        p->linel = malloc(sizeof(int)*2);
        *(p->linel+1) = linen;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        *(p->linel+p->count+1) = linen;
        p->count++;
        p->linen = linen;
        p->linel = realloc(p->linel, sizeof(int)*(p->count+1));
    }
    else if (cond < 0)              /* less than into left subtree */
        p->left = addtree(&p->left, w);
    else                            /* greater than into right subtree */
        p->right = addtree(&p->right, w);
    return p;
}

/* treeprint:  in-order print of tree p */
void treeprint(struct tnode *p)
{
    int i;
    if (p != NULL) {
        treeprint(p->left);
        printf("%-14s\t%d\t", p->word, p->count);
        for (i = 0; i < p->count; i++)
            printf("%d  ", *(p->linel+i+1));
        printf("\n");
        treeprint(p->right);
    }
}
