/* vim:ts=4:sw=4:et:
 *
 * ex2-3.c
 *      Convert hex string to number.
 *
 * Description:
 *      Write the function htoi(s), which converts a string of hexa-
 *      decimal digits (including an optional 0x or 0X) into its
 *      equivalent integer value. The allowable digits are 0 through
 *      9, a through f, and A through F.
 *
 * Returns:
 *      Integer representation of ASCII hex string.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char s[]);

int main(void) {

    char *s = "0x2dd1";
    printf("%s = %d\n", s, htoi(s));
    return 0;
}

/* convert hex string to integer */
int htoi(char s[]) {

    int i = 0, n = 0, len = 0;

    len = strlen(s);

    /* test for correct hex string formatting */
    if ((len > 2) && (s[0] != '0') && (toupper(s[1]) == 'X'))
        return -1;

    /* skip the first two characters if the hex string
       starts with "0x" or "0X" */
     
    if ((len > 2) && (s[0] == '0') && (toupper(s[1]) == 'X')) {
        len -= 2;
        i = 2;
    }

    for (i; (s[i] >= '0' && s[i] <= '9') || 
        (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'F' ); i++) {
        if (s[i] <= '9')
            n = 16 * n + (s[i] - '0');
        else
            n = 16 * n + (toupper(s[i]) - '7');
    }

	return n;
}
