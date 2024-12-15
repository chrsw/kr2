/*
 * sortr.c
 *      Solution 5-14. Sort input lines, with a reverse option.
 *
 * Description:
 *      TBD
 *
 * Input:
 *      Lines of plain text.
 *
 * Output:
 *      Sorted input in reverse.
 *
 * Design:
 *      Reverse support added to writelines() for simplicity.
 * 
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o ex5-14 sortr.c
 *
 * Run:
 *      $ ./ex5-14 -r < sec5-11_sort_test.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000                   /* max #lines to be sorted */
char *lineptr[MAXLINES];                /* pointers to next lines */

/* function declarations */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

/* avoid collision with Standard C library routine qsort() */
void sec5_11_qsort(void *v[], int left, int right, 
            int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {

    int nlines;             /* number of input lines to read */
    int numeric = 0;        /* 1 if numeric sort */
    int reverse = 0;        /* 1 if reverse sort */
    
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if (argc > 2 && strcmp(argv[2], "-r") == 0)
        reverse = 1;
    if (argc > 1 && strcmp(argv[1], "-r") == 0)
        reverse = 1;
    if (argc > 2 && strcmp(argv[2], "-n") == 0)
        numeric = 1;
    /* read all lines into memory, sort and print.
     * cast function pointer types in conditional expression to avoid 
     * GCC warnings. */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        sec5_11_qsort((void **) lineptr, 0, nlines-1,
            (int (*)(void*,void*))(numeric ? (int (*)(void*,void*))numcmp : 
                                             (int (*)(void*,void*))strcmp));
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


/* writelines:  write output lines in standard or reverse order */
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
void sec5_11_qsort(void *v[], int left, int right, 
            int (*comp)(void *, void *)) {

    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)                  /* do nothing if the array contains */
        return;                         /* fewer than two elements */
    swap(v, left, (left +right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v,  left, last);
    sec5_11_qsort(v, left, last-1, comp);
    sec5_11_qsort(v, last+1, right, comp);

}


/* swap:  exchange two pointers */
void swap(void *v[], int i, int j) {

    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* numcmp:  compare s1 and s2 numerically */
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
        return allocp - n;                       /* old p */
    }
    else {
        return NULL;                            /* not enough room */
    }
}


/* sec1_9_getline:  read a line into s, return length */
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

