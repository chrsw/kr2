/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * lower.c
 *      Covert input to lower case.
 *
 * Description:
 *      K&R2 section 7.1 excerpt.
 *
 * Build:
 *      $ gcc -o lower lower.c
 *
 * Run:
 *      $ ./lower < test_input_lower.txt
 *      - or - 
 *      $ make lower.c
 *
 */

#include <stdio.h>
#include <ctype.h>


/* lower:  convert input to lower case. */
int main(int argc, char *argv[])
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}
