/*
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


