/*
 * word_freq_cnt.c
 *      Count the frequency of words on standard input.
 *      Excerpt from section 6.5 Self-referential structures.
 *
 * Input:
 *      Plain text with words.
 *
 * Output:
 *
 *
 * Build:
 *      $ gcc -o word-freq-cnt word_freq_cnt.c bgetword.c getch.c
 *
 * Run:
 *      $ ./word-freq-cnt < test_input.txt
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct tnode {                  /* the tree node:  */
    char *word;                 /* points to the text  */
    int count;                  /* number of occurrences */
    struct tnode *left;         /*  left child */
    struct tnode *right;        /*  right child */
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int bgetword(char *, int);

/* word frequency count */
int main(int argc, char *argv[]) {

    struct tnode *root;
    char word[MAXWORD];
    
    root = NULL;
    while (bgetword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *ch6_strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {

    int cond;
    
    if (p == NULL) {                    /* a new word has arrived */
        p = talloc();                   /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w,p->word)) == 0)
        p->count++;                     /* repeated word */
    else if (cond < 0)                  /* less than into left subtree */
        p->left = addtree(p->left, w);
    else                                /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {

    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void) {

    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s */   
char *ch6_strdup(char *s) {

    char *p;
    p = (char *) malloc(strlen(s)+1);       /* +1 for '\0' */
    if (p != NULL)
        strcpy(p,s);
    return p;
}

