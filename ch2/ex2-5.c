/* vim:ts=4:sw=4:et:
 *
 * ex2-5.c
 *      Main driver for any().
 *
 * Description:
 *
 * Input:
 *
 */

#include <stdio.h>

int any(char *s1, char *s2);

int main(int argc, char *argv[])
{

    char s1[] = "look for characters in this string, please.";
    char s2[] = "zyxwvuts";
    int n;

    n = any(s1, s2);    
    printf("n = %d\ts1[n] = %c\n", n, s1[n]);
    return 0;
}
