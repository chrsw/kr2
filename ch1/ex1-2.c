/*
 * ex1-2.c	
 *      Experiment to find out what happens when printf()'s argument
 *      string contains \c, where c is some character not listed above.
 *
 */

#include <stdio.h>

int main(void)
{
    printf("test 1: \c\n");
    printf("test 2: \e\n");
    printf("test 3: \s\n");

    return 0;
}
