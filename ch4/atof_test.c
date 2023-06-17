/* vim:ts=4:sw=4:et:so=10:
 *
 * atof_test.c
 *      Test function cpl_atof().
 *
 * Build:
 *      $ gcc -o atof_test cpl_atof.c atof_test.c
 *
 */

#include <stdio.h>

double cpl_atof(char s[]);

int main(int argc, char *argv[]) {

    char s[] = "3.146";

    printf("%f\n", cpl_atof(s));

    return 0;
}
