/*
 * ch2_strlen.c
 *      Return the length of s.
 *
 */


int ch2_strlen(char s[])
{
    int i;
    while (s[i] != '\0')
        ++i;
    return i;
}
