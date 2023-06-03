/* vim:ts=4:sw=4:et:so=10:
 *
 * trim_test.c
 *      Test the code in the trim.c.
 *
 * Build:
 *      $ gcc -o trim_test trim.c trim_test.c
 * 
 * Run:
 *      $ ./trim_test
 *
 */

#include <stdio.h>
#include "trim.h"

int main(int argc, char *argv[]) {

    int n = 0;

    char s[200] = "This string has extra spaces at the end. "
                  "This is to test the trim()."
                  "                                    ";

    printf("string before:\n%s\n", s);
    n = trim(s);
    printf("\n%d characters trimmed\n", n);
    printf("string after:\n%s\n", s);

    return 0;
}
