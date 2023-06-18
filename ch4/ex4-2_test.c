/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-2_test.c
 *      Test solution to ex4-2().
 *
 * Build:
 *      $ gcc -o ex4-2_test ex4-2.c ex4-2_test.c -lm
 *
 */

#include <stdio.h>

double ex4_2_atof(char s[]);

int main(int argc, char *argv[]) {

    char s[] = "123.456e3";

    printf("%f\n", ex4_2_atof(s));

    return 0;
}
