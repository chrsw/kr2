/* vim:ts=4:sw=4:et:so=10:
 *
 * binsearch2.c
 *      Binary search, exercise 3-1 version.
 *
 * Description:
 *      Write a version of binary search with only one test inside the loop
 *      and measure the difference in run-time.
 *
 * Input:
 *      Sorted array, value to search for, length of array.
 *
 * Output:
 *      Index of matching element in array, -1 if no match.
 *
 */

#include <stdio.h>

/* binsearch: find x in v, where v: v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, volatile int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 2;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
   
    if (x == v[mid-1])
        return mid-1;
    else if (x == v[mid])
        return mid;
    else if (x == v[mid+1])
        return mid+1;
    else 
        return -1;      /* no match */
}
