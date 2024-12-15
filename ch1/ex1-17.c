/*
 * ex1-17.c
 *      Write a program to print all input lines that are longer than 80
 *      characters.
 */

#include <stdio.h>
#define MAXLINE 1000

int getlin(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {

    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */

    max = 0;
    while ((len = getlin(line, MAXLINE)) > 0 )
        if (len > 80) {
            printf("%s", line);
        }

    return 0;
}

/* getlin: read a line into s, return length
 * getline() is now a C Standard Library function declared in
 * stdio.h
 */
int getlin(char s[], int lim) {

    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
