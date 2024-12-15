/*
 * ckeywords_sec6-4.c
 *      Count C keywords.
 *
 * Description:
 *      Count the occurrence of each Standard C keyboard in a C source file.
 *      Version from Section 6.4 Pointers to Structures.
 *
 * Input:
 *      A valid C file on standard input.
 *
 * Build:
 *     $ gcc -Wall -Wextra -Wpedantic -o ckeywords_sec6-4 ckeywords_sec6-4.c 
 *     binsearch.c bgetword.c getch.c
 *       
 *
 * Run:
 *      ./ckeywords < file.c
 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ckeywords.h"

#define MAXWORD 100                     /* max word length to look for */

int getword(char *, int);
int bgetword(char *, int);
struct key *binsearch(char *, struct key *, int);

/* keyword list from Section A2.4 Keywords, page 192 */
struct key keytab[] = {

    {"auto",        0},
    {"break",       0},
    {"case",        0},
    {"char",        0},
    {"const",       0},
    {"continue",    0},
    {"default",     0},
    {"do",          0},
    {"double",      0},
    {"else",        0},
    {"enum",        0},
    {"extern",      0},
    {"float",       0},
    {"for",         0},
    {"goto",        0},
    {"if",          0},
    {"int",         0},
    {"long",        0},
    {"register",    0},
    {"return",      0},
    {"short",       0},
    {"signed",      0},
    {"sizeof",      0},
    {"static",      0},
    {"struct",      0},
    {"switch",      0},
    {"typedef",     0},
    {"union",       0},
    {"unsigned",    0},
    {"void",        0},
    {"volatile",    0},
    {"while",       0}
};

/* Get size of list with a programmatic solution */ 
#define NKEYS (sizeof(keytab)/sizeof(struct key))

/* count C keywords: pointer version */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char word[MAXWORD];
    struct key *p;

    while (bgetword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            /* look for word found by getword() in keyword list */
            if ((p=binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    
    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    }
	return 0;
}

