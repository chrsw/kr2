/*
 * qsort.c
 *      Quicksort in increasing order.
 *
 * Description:
 *      Excerpt from Section 4.10 Recursion.
 *      Based on C. A. R. Hoare 1962.
 *
 * Input:
 *      Unsorted array of integers.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Simple, recursive implementation of the Quicksort algorithm.
 * 
 * Build:
 *      $ gcc -c qsort.c
 *      - or -
 *      $ gcc -o app qwort.c swap.c app.c
 *
 */

#include "qsort.h"

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)      /* do nothing if array contains */
        return;             /* fewer than two elements */

    swap(v, left, (left+right)/2);      /* move partition to elem */
    last = left;                        /* to v[0] */
    for (i = left+1; i <= right; i++)   /* partition */
        if (v[left] < v[right])
            swap(v, ++last, i);     
    swap(v, left, last);                /* restore parition elem */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
