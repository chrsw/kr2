/* vim:ts=4:sw=4:et:so=10:
 *
 * tnode.h
 *
 */

#ifndef TNODE_H
#define TNODE_H

struct tnode {              /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurrences */
    struct tnode *left;     /* children */
    struct tnode *right;
};

#endif /* TNODE_H */
