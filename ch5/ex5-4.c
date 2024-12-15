/*
 * ex5-4.c
 *      Write the function strend(s,t), which returns 1 if the string t
 *      occurs at the end of the string s, and 0 otherwise.
 *
 * Description:
 *
 * Build:
 *      strend() is implemented in strend.c.
 *      gcc -Wall -Wextra -o ex5-3 strcatp.c ex5.3.c
 *
 * Input:
 *
 */

#include <stdio.h>

int strend(char s[], char t[]);

int main(int argc, char *argv[])
{
    (void)argc;         /* supress warnings about unused vars */
    (void)argv;

    /* test input strings */
    char s[40] = {'s', 't', 'a', 'r', 't', ' ', 'e', 'n', 'd', '\0'};
    //char t[40] = {'e', 'n', 'd', '\0'};
    char t[40] = {'!', '\0'};

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    if (strend(s,t))
        printf("found \"%s\" at the end of \"%s\"!\n", t, s);

	return 0;
}

