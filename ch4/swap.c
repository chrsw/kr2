/*      
 * swap.c
 *      Swap two elements in an array.
 *
 * Description:
 *      From Section 4.10 Recursion
 *
 * Input:
 *      Integer array.
 *
 * Output:
 *      Same as import array except two swapped elements.
 *
 */


void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
