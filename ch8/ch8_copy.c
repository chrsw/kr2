/*      Vim modeline for consistent editor settings across files.
 *
 * ch8_copy.c
 *      Copy input to output. Chapter 8 version.
 *
 * Input:
 *      Standard input.
 *
 * Build:
 *      $ gcc -o ch8_copy ch8_copy.c
 *      $ gcc -o copy ch8_copy.c
 *
 * Run:
 *      $ ./ch8_copy < test_input.txt > test_output.txt
 *      $ ./copy < test_input.txt > test_output.txt
 *
 */

#include "syscalls.h"

/* copy input to output */
int main(int argc, char *argv[]) {

    char buf[BUFSIZ];
    int n;
    
    while ((n = read(0, buf, BUFSIZ)) > 0)
        write(1, buf, n);
    return 0;
}
