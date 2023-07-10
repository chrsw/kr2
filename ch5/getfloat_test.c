/* vim:ts=4:sw=4:et:so=10:
 *
 * getfloat_test.c
 *      Test driver for getint().
 *
 * Input:
 *      ASCII integer on standard input.
 *
 * Build:
 *      $ gcc -o getfloat_test getfloat_test.c ex5-2.c getch.c
 *
 */

#include <stdio.h>

int getfloat(double *);

int main(int argc, char *argv[]) {

    double d = 19;
    int c = 0;
    
    (void)argc;
    (void)argv;

    c = getfloat(&d);

    printf("d = %.6g\n", d);

    return 0;
}



