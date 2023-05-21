/* vim:ts=4:sw=4:et:so=10:
 *      Vim modeline for consistent editor settings across files.
 *
 * gensar.c
 *      Generate a sorted array of random numbers.
 *
 * Description:
 *      Genrate an array of 1000 integers in increasing order.
 *
 * Input:
 *      p for printing the generated array or not.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "gensar.h"

volatile int a[ARR_LEN];

void gensar(bool p) {

    /* use current time as seed for psuedo RNG */
    srand(time(0));
   
    a[0] = 0;       /* start with a known value */

    /* fill array with random #s */
    for (int i = 1; i < ARR_LEN; i++) 
        a[i] = a[i-1] + (rand() & 9) + 1;
    
    /* print array */
    for (int i = 0; (i < ARR_LEN) && p; i++) 
        printf("%d ", a[i]);
    if (p) printf("\n");
}
