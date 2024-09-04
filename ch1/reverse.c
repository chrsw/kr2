/*
 * reverse:  Reverse input lines.
 *           Exercise 1-19.
 *
 * Input:
 *      Plain text lines.
 *
 * Output:
 *      Input lines reversed.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o reverse reverse.c
 *
 * Run:
 *      $ ./reverse < numbers.txt
 *
 */

#include <stdio.h>
#define MAXLINE 4906          /* Linux max line length (man termios) */

/* Standard Library (stdio.h) already defines getline() */
int sec_1_9_getline(char line[], int maxline);
void reverse(char b[], char f[]);

/* reverse input lines */
int main(void) {

    int len;                    /* current line length */
    char line[MAXLINE];         /* current inpu8t line */
    char reversed[MAXLINE];     /* reversed line saved here */

    while ((len = sec_1_9_getline(line, MAXLINE)) > 0) {
            reverse(reversed,line);
            printf("%s", reversed);
    }
    return 0;
}


/* getline: read a line into s, return length */
int sec_1_9_getline(char s[], int lim) {

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


/* reverse: reverse 'f' into 'b', forward into backward */
void reverse(char b[], char f[]) {

    int i = 0;
    int len;

    while (f[len++])        /* find length of string to reverse */
        ;
    len -= 2;               /* 1 too far, skip newline and null */
    while (len--)
        b[i++] = f[len];
    b[i++] = '\n';
    b[i] = '\0';
}

