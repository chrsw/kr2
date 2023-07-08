/* vim:ts=4:sw=4:et:so=10:
 *
 * getint_test.c
 *      Test driver for getint().
 *
 * Description:
 *
 * Input:
 *      Describe the expected input.
 *
 * Build:
 *      $ gcc -o getint_test getint_test.c getint.c getch.c
 *
 */

#include <stdio.h>

int getint(int *);

int main(int argc, char *argv[]) {

    int i = 0;
    int c = 0;
   
    for (c = getint(&i); i <= 20; i++)
        printf("%d ", i);
    printf("\n");
    return 0;
}



