/* vim:ts=4:sw=4:et:so=10:
 *
 * getint_test.c
 *      Test driver for getint().
 *
 * Input:
 *      ASCII integer on standard input.
 *
 * Build:
 *      $ gcc -o getint_test getint_test.c getint.c getch.c
 *
 */

#include <stdio.h>

int getint(int *);

int main(int argc, char *argv[]) {

    int i = 19;
    int c = 0;
    
    (void)argc;
    (void)argv;

    c = getint(&i);

    printf("c = %d\n", c);

    for (; i <= 20; i++)
        printf("%d ", i);
    printf("\n");

    return 0;
}



