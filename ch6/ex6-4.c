/* vim:ts=4:sw=4:et:so=10:
 *
 * ex6-4.c
 *      Write a program that prints the distinct words in its input sorted
 *      into decreasing order of frequency of occurrence. Precede each word by
 *      its count.
 *
 * Input:
 *      Plain text with words.
 *
 * Output:
 *      List of words sorted by frequency in reverse order.
 *
 * Build:
 *      $ gcc -o ex6-4 ex6-4.c bgetword.c getch.c
 *
 * Run:
 *      $ ./ex6-4 < test_input.txt
 *
 * TODO:
 *      Improve the timing of the sort, use a real sording algorithm?
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
void sortprint(struct tnode *p);
void seltreeprint(struct tnode *p, int sel);
int bgetword(char *, int);

int gmax_count = 0;             /* holds the largets count seen so far */

/* word frequency count */
int main(int argc, char *argv[]) {

    struct tnode *root;
    char word[MAXWORD];
    
    root = NULL;                /* build tree of all the input words */
    while (bgetword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    sortprint(root);            /* print the tree in reverse frequency */
    printf("%d\n", gmax_count);
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
    } else if ((cond = strcmp(w,p->word)) == 0) {
        p->count++;                     /* repeated word */
        gmax_count = p->count > gmax_count ? p->count : gmax_count;
    }
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

/* treeprint: in-order selected print of tree p */
void seltreeprint(struct tnode *p, int sel) {

    if (p != NULL) {
        seltreeprint(p->left, sel);
        if (p->count == sel) printf("%4d %s\n", p->count, p->word);
        seltreeprint(p->right, sel);
    }
}

/* sortprint: print all words found with each frequency */
void sortprint(struct tnode *p) {

    int i = gmax_count;

    if (p == NULL) return;

    for (; i > 0; i--) {
        seltreeprint(p, i);   
    }

}
