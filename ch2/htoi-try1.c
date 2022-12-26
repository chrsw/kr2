/* vim:ts=4:sw=4:et:
 *
 * ex2-2.c
 *      Write the function htoi(s), which converst a string of hexa-
 *      decimal digits (including an optional 0x or 0X) into its
 *      equivalent inteiger value. The allowable digits are 0 through
 *      9, a through f, and A through F.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(const char *s);

int main() {

    const char *s = "def789";

    if (htoi(s) > 0) printf("%s: valid!\n", s);

    return 0;
}

/*
 * Convert a string of hexadecimal digits to its equivalent integer value.
 * From Section 2.7, atoi():
 * int i, n;
 * 
 * n = 0;
 * for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
 *     n = 10 * n + (s[i] - '0');
 */
int htoi(const char *s) {

    int i = 0;
    int valid = 1;
    int len = 0;
    int value = 0;

    if (!s) return -1;

    len = strlen(s);

    if ((len > 2) && (s[0] != '0') && (tolower(s[1]) == 'x'))
        return -1;

    if ((len > 2) && (s[0] == '0') && (tolower(s[1]) == 'x')) {
        len -= 2;
        i = 2;
    }

    while ( i++ < len) {
        if (!isxdigit(s[i])) 
            return -1;
        i++;
    }


    // make sure every digit is a hex digit
    while (s[i] != '\0') {
        if (!isxdigit(s[i])) 
            valid = 0;
        i++;
    }

    // Now start at the "end" of the string s and work back to the 0th
    // position, calculating the integer value at every position.
    --i;
    while (i-- >= 0) {
        
    }

    return valid;
}
