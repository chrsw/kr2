/*
 * ex1-6.c
 *      Verify that the expression getchar() != EOF is 0 or 1.
 *
 * Description:
 *
 *
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int c;

    while ( c = (getchar() != EOF)) {       /* print the result of */
        printf("%d", c);                  /* the comparison every read */
    }                                       
    printf("%d\n", c);

    return 0;
}
