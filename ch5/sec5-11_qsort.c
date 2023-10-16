/* vim:ts=4:sw=4:et:so=10:
 *
 * sec5-11_qsort.c
 *      Sort array into increasing order.
 *
 * Description:
 *      From section 5.11.
 *
 * Input:
 *      v[]         unsorted array of any type
 *      left        bounds of sort space
 *      right
 *      (*comp)()   comparison function
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.      
 *
 * Build:
 *      $ gcc -c sec5-11_qsort.c
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */


/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, 
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
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);

}
