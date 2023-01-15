/* vim:ts=4:sw=4:et:
 *
 * squeeze2.c
 *      Delete each character in s1 that matches any character in s2.
 *
 * Description:
 *
 * Input:
 *
 */

void squeeze(char s1[], int c);

void squeeze2(char s1[], const char s2[]) {

    int i;

    for (i = 0; s2[i] != '\0'; i++)
        squeeze(s1, s2[i]);
}
