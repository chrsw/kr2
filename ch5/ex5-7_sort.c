/*
 * ex5-7_sort.c
 *      Sorting program for exercise 5-7. Use array instead of allocation.
 *
 * Description:
 *      Rewrite readlines() to store lines in an array supplied by main(),
 *      rather than calling alloc() to maintain storage. How much faster 
 *      is the program?
 *
 * Input:
 *      Plain text of unsorted lines. See ex5-7_test_input.txt
 *
 * Build:
 *      $ gcc -o ex5-7_sort ex5-7_sort.c
 *
 * Test:
 *      $ ./ex5-7_sort < ex5-7_test_input.txt > ex5-7_test_output.txt
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000                   /* max #lines to be sorted */
#define MAXLEN 1000                     /* max length of any input line */
//char *lineptr[MAXLINES];                /* pointers to next lines */
char *staticptr[MAXLINES];                /* pointers to next lines */
char input[MAXLINES][MAXLEN];           /* static storage for input data */

/* function declarations */
int readlines(/*char *lineptr[],*/ char* staticptr[], char input[MAXLINES][MAXLEN], int nlines);
void writelines(char *lineptr[], int nlines);

/* qsort() is defined in C standard lib (stdlib.h) so we'll have to rename
 * this version.
 */
void sec5_6_qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void) {

    int nlines;
    
    if ((nlines = readlines(/*lineptr, */staticptr, input, MAXLINES)) >= 0) {
        sec5_6_qsort(staticptr, 0, nlines-1);
        //sec5_6_qsort(input, 0, nlines-1);
        writelines(staticptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
    return 0;
}

int sec1_9_getline(char *, int);        /* from section 1.9 */
char *alloc(int);                       /* from section 5.4 */


/* readlines: read input lines */
int readlines(/*char *lineptr[],*/ char *staticptr[], char input[MAXLINES][MAXLEN], int maxlines) {

    int len, nlines;
    char *p, line[MAXLEN];
    int i = 0;
    
    nlines = 0;
    while ((len = sec1_9_getline(line, MAXLEN))> 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            printf("nlines = %d\n", nlines);
            return -1;
        }
        else {
            line[len-1] = '\0';         /* delete newline */
            strcpy(p, line);
            strcpy(input[nlines], line);
            //lineptr[nlines] = p;
            staticptr[nlines] = input[nlines];
            nlines++;
        }
    return nlines;
}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {

    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


/* sec5_6_qsort: sort v[left]...v[right] into increasing order */
/* Section 5.6 version */
void sec5_6_qsort(char *v[], int left, int right) {

    int i, last;
    void swap(char *v[], int i, int j);
    
    if (left >= right) {                        /* do nothing if array */
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


/* interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {

    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


#define ALLOCSIZE 50000                         /* size of available space */

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
