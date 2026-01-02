/* 
 * binstest.c
 *      Test driver for binsearch.c.
 *
 * Description:
 *      Create a sorted array and pass to binsearch() to find a key.
 * Input:
 *      Describe the expected input.
 *
 * Other info:
 *      Returns, build, notes, etc. 
 *
 */

#include "binsearch.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    int v[] = {0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
    unsigned int n = sizeof(v)/sizeof(v[0]);
    int key, pos; 
    
    key = 22;
    pos = binsearch(key,v,(int)n);

    printf("pos = %d\n", pos);

    key = 21;
    pos = binsearch(key,v,(int)n);

    printf("pos = %d\n", pos);

    return 0;
}
