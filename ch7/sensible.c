/*
 * sensible.c
 *      Print arbitrary input in a sensible way.
 *
 * Description:
 *      Solution to Chapter 7, exercise 2.
 *      Exercise text: Write a program that will print arbitrary input in a
 *      sensible way. As a minimum, it should print non-graphic characters
 *      in octal or hexadecimal according to local custom, and break long
 *      text lines.
 *
 * Build:
 *      $ gcc -o sensible sensible.c
 *
 * Run:
 *      $ ./sensible < ex7_2_test_input.txt
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int c, cc;
    int len = 0;
    while((c = getchar()) != EOF) {
         
        if (isprint(c))             /* print a char if it's readable */
            putchar(c);
        else if (isspace(c)) {
            putchar(c);
            if (c == '\n')
                len = 0;
        }
        else
            printf("0%o", c);       /* otherwise print the octal value */

        if (len++ > 80) {           /* break long lines */ 

            printf("\n");
            len = 0;
        }
        cc = c;
    }
    
    if (cc != '\n') printf("\n");   /* end on one new line */ 
    return 0;
}
