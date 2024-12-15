/*
 * sdate.c
 *      Scan date info from terminal/keyboard.
 *
 * Description:
 *      Demonstrates the use of scanf. Excrpt from Section 7.4.
 *
 * Input:
 *      Supports different types of date input.
 *
 * Output:
 *      Valid date input or invalid message.
 *
 * Build:
 *      $ gcc -o sdate sdate.c
 *
 * Run:
 *      $ echo "14 Jan 2024" | ./sdate
 *
 */

#include <stdio.h>

int sec1_9_getline(char [], int );

/* sdate:  read lines that might contain date data in different formats */
int main(int argc, char *argv[])
{

    int day, month, year;
    char monthname[20];
    char line[40];
    
    while (sec1_9_getline(line, sizeof(line)) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line); /* 25 Dec 1998 form */
        else if(sscanf(line, "%d/%d/%d", &month, &day, &year ) == 3)
            printf("valid: %s\n", line); /* mm/dd/yy form */
        else
            printf("invalid: %s\n", line);
    }
    
    return 0;
}

/* sec1_9_getline:  get a line from standard input. from Section 1.9 */
int sec1_9_getline(char s[], int lim)
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

