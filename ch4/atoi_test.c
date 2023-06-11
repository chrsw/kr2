/* vim:ts=4:sw=4:et:so=10:
 *
 * atoi_test.c
 *      Test function cpl_atoi().
 *
 * Description:
 *
 * Input:
 *      Describe the expected input.
 *
 * Build:
 *      $ gcc -o atoi_test cpl_atof.c cpl_atoi.c atoi_test.c
 *
 */

#include <stdio.h>
int cpl_atoi(char s[]);

int main(int argc, char *argv[]) {

    char s[] = "3.146";

    printf("%d\n", cpl_atoi(s) );

    return 0;
}
