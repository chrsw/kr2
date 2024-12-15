/*
 * ex5-3.c
 *      Write a pointer version of the fuction strcat(). strcat(s,t) copies
 *      the string t to the end of s.
 *
 * Description:
 *      Renamed to strcatp() to avoid conflict with the standard library
 *      function strcat() defined in string.h.
 *
 * Build:
 *      strcatp() is implemented in strcatp.c. To compile this exercise
 *      solution:
 *          gcc -Wall -Wextra -o ex5-3 strcatp.c ex5.3.c
 *
 * Input:
 *
 */

#include <stdio.h>

void strcatp(char s[], char t[]);

int main(int argc, char *argv[])
{
    (void)argc;         /* supress warnings about unused vars */
    (void)argv;

    /* test input strings */
    char s[40] = {'s', 't', 'a', 'r', 't', ' ', '\0'};
    char t[40] = {'e', 'n', 'd', '\0'};

    printf("%s\n", s);
    printf("%s\n", t);
    strcatp(s,t);
    printf("%s\n", s);

	return 0;
}

