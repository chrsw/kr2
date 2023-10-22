/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * sortk.c
 *      Solution 5-17. Sort on fields.
 *
 * Description:
 *      Add a field-handling capability, so sorting may be done on fields
 *      within lines, each field sorted according to an independent set
 *      of options.
 *
 * Input:
 *      Lines of plain text.
 *
 * Output:
 *      Sorted input based on specified field.
 *
 * Design:
 *      For now the field separator will be the space character only.
 *      Fields are zero indexed.
 *      Folding is off, despite the support seeming like it remains.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.      
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o ex5-17 sortk.c strcscmp.c
 *
 * Run:
 *      $ ./ex5-17 <-field> < sec5-11_sort_field_test.txt
 *      $ ./ex5-17 -2 < sec5-11_sort_field_test.txt
 *
 * TODO:
 *      Combine with support from previous exercises.
 *      Use Standard C strtok() instead of strtok_r().
 *      Use better command line argument handling.
 *
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAXLINES 5000                   /* max #lines to be sorted */
#define MAXLEN 1000                     /* max length of any input line */
char *lineptr[MAXLINES];                /* pointers to next lines */
char gstr_left[MAXLEN];
char gstr_right[MAXLEN];

/* function declarations */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
int strcscmp(char *s, char *t);

void sec5_11_qsort(void *v[], int left, int right, int fold,
            int (*comp)(void *, void *), int field);
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {

    int nlines;             /* number of input lines to read */
    int numeric = 0;        /* 1 if numeric sort */
    const int reverse = 0;        /* 1 if reverse sort */
    int fold = 0;           /* 1 if folding */
    int field = 0;
    
    if (argc > 1 && strcmp(argv[1], "-1") == 0)
        field = 1;
    if (argc > 1 && strcmp(argv[1], "-2") == 0)
        field = 2;
    if (argc > 1 && strcmp(argv[1], "-3") == 0)
        field = 3;
    if (argc > 1 && strcmp(argv[1], "-4") == 0)
        field = 4;
    printf("field: %d\n", field);
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (field) {
            sec5_11_qsort((void **) lineptr, 0, nlines-1, fold,
            (int (*)(void*,void*))(numeric ? (int (*)(void*,void*))numcmp : 
                                            (int (*)(void*,void*))strcscmp),
                                            field);
        }
        else {
            sec5_11_qsort((void **) lineptr, 0, nlines-1, fold,
            (int (*)(void*,void*))(numeric ? (int (*)(void*,void*))numcmp : 
                                             (int (*)(void*,void*))strcmp),0);
        }
        writelines(lineptr,nlines,reverse);
        return 0;
    } else {
        printf("input too big to sort\n");
        return -1;
    }
    return 0;
}


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


/* sec5_11_qsort:  sort v[left]...v[right] into increasing order,
 * field version
 */
void sec5_11_qsort(void *v[], int left, int right, int fold, 
            int (*comp)(void *, void *), int field) {

    int i, last, fi;
    void swap(void *v[], int, int);
    char *f1;
    char *f2;
    char *tok1;
    char *tok2;

    if (left >= right)                  /* do nothing if the array contains */
        return;                         /* fewer than two elements */
    swap(v, left, (left +right)/2);
    last = left;


    for (i = left+1; i <= right; i++) {
        /* extract the field from v[i] and v[left] then do the comparison */
        strncpy(gstr_right,v[i], MAXLEN);
        strncpy(gstr_left,v[left], MAXLEN);
        f1 = strtok_r(gstr_right, " ", &tok1);
        f2 = strtok_r(gstr_left, " ", &tok2);
        for (fi = 0; fi < field; fi++) {
            f1 = strtok_r(NULL, " ", &tok1);
            f2 = strtok_r(NULL, " ", &tok2);
        }
        if ((*comp)(f1, f2) < 0)
                swap(v, ++last, i);
    }
    swap(v,  left, last);
    sec5_11_qsort(v, left, last-1, fold, comp, field);
    sec5_11_qsort(v, last+1, right, fold, comp, field);

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

/* alloc:  return pointer to n characters */
char *alloc(int n) {

    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;                      /* old p */
    }
    else {
        return NULL;                            /* not enough room */
    }
}


/* getline:  read a line into s, return length */
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

