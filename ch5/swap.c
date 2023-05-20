/* vim:ts=4:sw=4:et:so=10:
 *
 * swap.c
 *      Interchange 2 values.
 *
 */

void swap(int *px, int *py) {

    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}


