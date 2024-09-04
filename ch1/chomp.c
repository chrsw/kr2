/* chomp:  remove trailing blanks and blank lines
 * Exercise 1-18
 * 
 * $ gcc -Wall -Wextra -Wpedantic -o chomp chomp.c
 * $ cat blank_test.txt | ./chomp
 *
 * TODO:  remove blanks and blank lines in one construct
 * in chomp() instead of main(). 
 */

#include <stdio.h>
#define MAXLINE 4096        /* max line length (man termios) */

int ch1_getline(char line[], int maxline);
int chomp(char from[], int len);

/* remove trailing blanks and blank lines */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = ch1_getline(line, MAXLINE)) > 0) {
        len = chomp(line, len);
        if (line[0] != '\n') printf("%s", line);
    }
    return 0;
}


/* read a line into s, return length */
int ch1_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


/* chomp:  chomp 's'; skip ending blanks and newlines */
int chomp(char s[], int len)
{
    int j = len - 2;            /* skip newline and NULL */

    /* look for first non-blank char */
    while (s[j] == '\t' || s[j] == ' ')
        j--;

    s[++j] = '\n'; 
    s[++j] = '\0'; 
    return j;
}
