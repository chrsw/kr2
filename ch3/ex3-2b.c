/*
 * ex3-2b.c
 *	   Converts escape sequences '\n' and '\t' into real characters.
 *
 * Description:
 *	    Details
 *
 * Input:
 *
 */

#include <stdio.h>

void unescape(char s[], const char t[]);

int main(int argc, char *argv[])
{
    const char t[] = {'a', 'b', '\\', 't', '1', '2', '\\', 'n', '\0'};
    char s[80];
    printf("t = %s\n", t);
    unescape(s,t);
    printf("s = %s\n", s);
	return 0;
}
/*
 * Replaces the escape sequences with real characaters.
 */
void unescape(char s[], const char t[]) {

    int i = 0;
    int j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':          // Start of escame sequence
                i++;
                if (t[i++] == 't')
                    s[j++] = '\t';
                else
                    s[j++] = '\n';
                break;
            default:
                s[j++] = t[i++];
                break;
        }
    }
    s[j] = '\0';
}
