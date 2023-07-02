/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-14.c
 *      Write a program to print a histogram of the frequencies of different
 *      characters on its input.
 *
 * Description:
 *
 * Input:
 *      Plain text data on standard input.
 *
 */

#include <stdio.h>
#include <ctype.h>

/* the value at each position in the array will be the count 
 * for that value (character).
 */
int gia_chars[128] = {0};

int main(void) {

    int c;
    int i, j;

    /* read a character from input and count it */
    while ((c = getchar()) != EOF)
        if (c < 128)
            gia_chars[c]++;

    /* horizontal histogram */
    for (i = 0; i < 128; i++) {
        /* only print graph for letters and numbers */
        if (isalpha((char)i) || isdigit((char)i)) {
            /* start the first column with the character itself */
            printf("%c : ", i);
            /* frequencies more than 10 will wrap */
            /* TODO: scale depending on ammount of data */
            for (j = 0; j < gia_chars[i]; j++)
                printf("-");
            printf("\n");
        }
    }

    return 0;
}
