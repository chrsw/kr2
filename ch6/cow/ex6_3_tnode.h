/* vim:ts=4:sw=4:et:so=10:
 *
 * ex6_3_tnode.h
 *
 */

#ifndef EX6_3_TNODE_H
#define EX6_3_TNODE_H

struct tnode {              /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurrences */
    int linen;
    struct tnode *left;     /* children */
    struct tnode *right;
    int *linel;
};

#endif /* EX6_3_TNODE_H */
