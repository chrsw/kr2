/* vim:ts=4:sw=4:et:so=10:
 *
 * ex3-1.c
 *      Solution for chapter 3, exercise 1 that includes benchmarking.
 *
 * Description:
 *      Two different versions of the binary search function binsearch()
 *      are benchmarked in this solution. One version, binsearch() comes
 *      straight from the text, the other version binsearch2() has been
 *      optimized to remove one conditional in the main loop. This
 *      solution includes a example for benchmarking the two functions.
 *
 *      Test data can be automatically generated with the gensar()
 *      function.
 *
 * Input:
 *      Describe the expected input.
 *
 * Other info:
 *      Returns, build, notes, etc. 
 *
 */

//#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include "gensar.h"
#include "binsearch.h"

int main(int argc, char *argv[]) {

    gensar(false);      /* fill a randomly generated array */    

    int key, pos;

    key = 22;
    pos = binsearch(key,a,ARR_LEN);

    printf("pos = %d\n", pos);
  
    return 0;
}



