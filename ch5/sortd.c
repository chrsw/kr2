/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * sortd.c
 *      Solution 5-16. Sort input lines, with a "dictionary order" option.
 *
 * Description:
 *      Add the -d ("dictionary order") option, which makes comparisons only
 *      on letters, numbers and blanks. Make sure it works in conjunction
 *      with -f.
 *
 * Input:
 *      Lines of plain text.
 *
 * Output:
 *      Sorted input.
 *
 * Design:
 *      TBD
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.      
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o ex5-16 sortf.c strcscmp.c
 *
 * Run:
 *      $ ./ex5-16 -r < sec5-11_sort_dict_test.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000                   /* max #lines to be sorted */
char *lineptr[MAXLINES];                /* pointers to next lines */

/* function declarations */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
int strcscmp(char *s, char *t);
void dict(char *src, char *dest);

void sec5_11_qsort(void *v[], int left, int right, int fold,
            int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {

    int nlines;             /* number of input lines to read */
    int numeric = 0;        /* 1 if numeric sort */
    const int reverse = 0;        /* 1 if reverse sort */
    int dictionary = 0;        /* 1 if dictionary sort */
    int fold = 0;           /* 1 if folding */
    
    if (argc > 1 && strcmp(argv[1], "-d") == 0)
        dictionary  = 1;
    if (argc > 2 && strcmp(argv[2], "-f") == 0)
        fold = 1;
    if (argc > 1 && strcmp(argv[1], "-f") == 0)
        fold = 1;
    if (argc > 2 && strcmp(argv[2], "-d") == 0)
        dictionary = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (dictionary) {
            sec5_11_qsort((void **) lineptr, 0, nlines-1, fold,
            (int (*)(void*,void*))(numeric ? (int (*)(void*,void*))numcmp : 
                                            (int (*)(void*,void*))strcmp));
        }
        else {
            sec5_11_qsort((void **) lineptr, 0, nlines-1, fold,
            (int (*)(void*,void*))(numeric ? (int (*)(void*,void*))numcmp : 
                                             (int (*)(void*,void*))strcmp));
        }
        writelines(lineptr,nlines,reverse);
        return 0;
    } else {
        printf("input too big to sort\n");
        return -1;
    }
    return 0;
}


#define MAXLEN 1000                     /* max length of any input line */
int sec1_9_getline(char *, int);        /* from section 1.9 */
char *alloc(int);                       /* from section 5.4 */

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines) {

    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = sec1_9_getline(line, MAXLEN))> 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';         /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}


/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines, int reverse) {

    int i = nlines;
    if (reverse)
        while (nlines-- > 0)
            printf("%s\n", lineptr[--i]);
    else
        while (nlines-- > 0)
            printf("%s\n", *lineptr++);
}


/* sec5_11_qsort:  sort v[left]...v[right] into increasing order */
void sec5_11_qsort(void *v[], int left, int right, int fold, 
            int (*comp)(void *, void *)) {

    char t1[80];
    char t2[80];

    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)              /* do nothing if the array contains */
        return;                         /* fewer than two elements */
    swap(v, left, (left +right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        /* copy strings to sort into temp strings */
        /* strip out all non-dictionary chars from temp strings */
        dict(v[i],t1);
        dict(v[left],t2);
        /* compare temp strings, use return value to move real strings */
        if ((*comp)(t1, t2) < 0)
            swap(v, ++last, i);
    }
    swap(v,  left, last);
    sec5_11_qsort(v, left, last-1, fold, comp);
    sec5_11_qsort(v, last+1, right, fold, comp);

}


/* swap:  exchange two pointers */
void swap(void *v[], int i, int j) {

    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* numcmp:  cmpare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {

    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2 )
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}


#define ALLOCSIZE 10000                         /* size of available space */

static char allocbuf[ALLOCSIZE];                /* storage for alloc */
static char *allocp = allocbuf;                 /* next free position */

/* alloc: return pointer to n characters */
char *alloc(int n) {

    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;                       /* old p */
    }
    else {
        return NULL;                            /* not enough room */
    }
}


/* getline: read a line into s, return length */
int sec1_9_getline(char s[], int lim) {

    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* dict:  strip out non-dict chars */
void dict(char *src, char *dest) {

    while (*src != '\0') {
        if (isalnum(*src) || isblank(*src))
            *dest++ = *src;
        src++;
    }

}
