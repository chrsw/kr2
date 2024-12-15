/*
 * itoa.c
 *     Convert n to characters in s. Pad to lenght of 3rd argument.
 *
 * Description:
 *      Details
 *
 */

#include <string.h>
#include <stdio.h>

void itoa(int n, char s[], int len);
void reverse(char s[]);

int main(int argc, char *argv[])
{
    int n = 123456;
    int len = 9;
    char s[10];

    printf("input:  %d\n", n);
    itoa(n,s,len);
    printf("string: %s\n", s);
	return 0;
}


void itoa(int n, char s[], int len) {

    int i, sign;
    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = 0;
    do {                        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0 );    /* delete it */
    if (sign < 0){
        s[i++] = '-';
        while (i < (len-1))
            s[i++] = ' ';
    } else {
    while (i < len)
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
