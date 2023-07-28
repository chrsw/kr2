/* vim:ts=4:sw=4:et:so=10:
 *
 * ch5_atoi_test.c
 *      Test function ch5_atoi().
 *
 * Build:
 *      $ gcc -o ch5_atoi_test ch5_atoi.c ch5_atoi_test.c
 *
 */

#include <stdio.h>

int ch5_atoi(char s[]);

int main(int argc, char *argv[]) {

    char s[] = "3146";

    printf("%d\n", ch5_atoi(s));

    return 0;
}
