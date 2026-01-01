/* 
 * table.c Code for table lookup internals from Section 6.6 Table Lookup
 * This code can be used for simple applications that need to replace
 * strings.
 *
 * Build:
 *   gcc -c table.c
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "table.h"

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */


/* hash:  form hash value for string s */
unsigned hash(char *s) {

    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}


/* lookup:  look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    }
    return NULL; /* not found */
}


/* install:  install (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
        printf("install: added %s to hashtab\n", name);
    } else { /* already there */
        free((void *) np->defn); /* free previous definition */
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}
