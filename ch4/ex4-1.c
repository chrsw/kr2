/*
 * ex4-1.c
 *      Write the function strrindex(s,t), which returns the position
 *      of the _rightmost_ occurance of t in s or -1 if there is none. 
 *
 * Description:
 *
 * Input:
 *
 */

#include <stdio.h>

int strrindex(const char s[], char t);

int main(int argc, char *argv[])
{
    const char *s = "the test string!";
    printf("%s\n", s);
    printf("index: %d\n", strrindex(s, 't'));
	return 0;
}


int strrindex(const char s[], char t) {

    int i = 0, index = 0;
    if (!s) return -1;

    while (s[i] != '\0') {
        if (s[i++] == t)
            index = i;
    }
    return index ? index : -1;

}
