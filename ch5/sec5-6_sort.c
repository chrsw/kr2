/* vim:ts=4:sw=4:et:so=10:
 *
 * exCH-#.c
 *      Sorting program from section 5.6.
 
 * Description:
 *      Mostly copied from the text with some minor changes. Avoid conflict
 *      with Standard Library functions. More modern style. More comments.
 *
 * Input:
 *      Describe the expected input.
 *
 * Other info:
 *      Returns, build, notes, etc. 
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000                   /* max #lines to be sorted */
char *lineptr[MAXLINES];                /* pointers to next lines */


/* function declarations */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

/* qsort() is defined in C standard lib, so we'll have to rename
 * this version.
 */
void sec5_6_qsort(char *lineptr[], int left, int right);

/* sort input lines */
main(void) {

    int nlines;
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
    return 0;
}


#define MAXLEN 1000                     /* max length of any input line */
int sec1_9_getline(char *, int);        /* from section 1.9 */
char *alloc(int);                       /* from section 5.4 */
void afree(char *p);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {

    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    while ((len = sec1_9_getline(line, MAXLEN))> 0)
        if (nlines >= maxlines || (p = alloc(len) == NULL))
            return -1;
        else {
            line[len-1] = '\0';         /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {

    int i;
    
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr);
}

/* sec5_6_qsort: sort v[left]...v[right] into increasing order */
/* Section 5.6 version */
void sec5_6_qsort(char *v[], int left, int right) {

    int i, last;
    void swap(char *v[], int i, int j);
    
    if (left >= right) {                         /* do nothing if array */
        return;                                 /* contains fewer than */
    }                                           /* two elements. */
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    sec5_6_qsort(v, left, last-1);
    sec5_6_qsort(v, last+1, right);
    
}

/* interchangae v[i] and v[j] */
void swap(char *v[], int i, int j) {

    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000                         /* size of available space */

static char allocbuf[ALLOCSIZE];                /* storage for alloc */
static char *allocp = allocbuf;                 /* next free position */

/* alloc: return pointer to n characters */
char *alloc(int n) {
    
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp -n;                       /* old p */
    }
    else {
        return NULL;                            /* not enough room */
    }
}

/* free storage pointed to by p */
void afree(char *p) {
    
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
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
