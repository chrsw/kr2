/* vim:ts=4:sw=4:et:
 *
 * ex7-1.c
 *      Write a program that converts upper case to lower or lower case 
 *      to upper depending on the name it is invoked with.
 *
 * Description:
 *      Uses standard library functions in string.h once the direction
 *      of case conversion has been determined.
 *
 * Input:
 *      Executable name.
 *
 * Returns:
 *      -1 Bad input
 *       1 lower -> upper conversion
 *       2 upper -> lower conversion
 *
 * Build:
 *      Compile and create a binary named "ex7-1".
 *      gcc -Wall -Wextra -o ex7-1 ex7-1.c
 *
 * Setup:
 *      Create hard links with different names pointing to the same
 *      binary.
 *      ln ex7-1 upper && ln ex7-1 lower
 *
 * Run:
 *      Run either hard link with the name of the conversion you want.
 *      ./upper < test.txt      # for lower to upper conversion
 *      ./lower < test.txt      # for upper to lower conversion
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int conv_type = 0;
    int c;

    if (argc != 1)
        return -1;
    
    if (!strcmp(argv[0], "./upper"))        /* Find the program name  */
        conv_type = 1;                      /* or quit if missing/bad */
    else if (!strcmp(argv[0], "./lower"))
        conv_type = 2;
    else
        return -1;

    while ((c = getchar()) != EOF) {        /* Convert case based on */
        if (conv_type == 1)                 /* program name. */
            putchar(toupper(c));
        else if (conv_type == 2)
            putchar(tolower(c));
        else
            putchar(c);
    }
    
    return conv_type;
}
