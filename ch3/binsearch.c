/* vim:ts=4:sw=4:et:
 *
 * binsearch.c
 *      Find an element in an array using binary search.
 *
 * Description:
 *      An example form K&R 2 section 3.3.
 *
 * Input:
 *      Sorted array, value to search for, length of array.
 *
 * Output:
 *      Index of matching element in array, -1 if no match.
 *
 */

/* binsearch: find x in v, where v: v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int volatile v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else        /* found match */
            return mid;
    }
    
    return -1;      /* no match */
}
