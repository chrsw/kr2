/* vim:ts=4:sw=4:et:
 *
 * ex3-2.c
 *	   Converts newline and tab into '\n' and '\t'.
 *
 * Description:
 *	    Details
 *
 * Input:
 *
 */

#include <stdio.h>

void escape(char s[], const char t[]);

int main(int argc, char *argv[])
{
    const char t[] = {'a', 'b', '\t', '1', '2', '\n', '\0'};
    //const char t[] = {'a', 'b', 'd', '1', '2', '4', '\0'};
    char s[80];
    printf("t = %s\n", t);
    escape(s,t);
    printf("s = %s\n", s);
	return 0;
}

void escape(char s[], const char t[]) {

    int i = 0;
    int j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't'; 
                t++;
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n'; 
                t++;
                break;
            default:
                s[j++] = t[i++];
                break;
        }
    }
    s[j] = '\0';
}
