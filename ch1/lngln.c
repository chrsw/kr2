/*
 * lngln.c
 *      Print the longest input line.
 *      From section 1.9.
 *      Used as the start of exercise 1-16.
 *      Static line lengths.
 *
 * Input:
 *      Plain text lines.
 *
 * Output:
 *      Longest line from input.
 *
 * Build:
 *      $ gcc -o lngln lngln.c
 *
 * Run:
 *      $ ./lngln < lngln.c
 *
 */

#include <stdio.h>
#define MAXLINE 1000            /* maximum input line size */

/* Standard Library (stdio.h) already defines getline() */
int sec_1_9_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void) {

    int len;                    /* current line length */
    int max;                    /* maximum length seen so far */
    char line[MAXLINE];         /* current inpu8t line */
    char longest[MAXLINE];      /* longest line saved here */

    max = 0;
    while ((len = sec_1_9_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest,line);
        }

    if (max > 0)                /* there was a line */
        printf("%s", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {

    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;

}

