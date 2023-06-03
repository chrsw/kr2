#include <stdio.h>

/* nc.c: count characters in input; 1st version */

int main(void) {

    long nc;
    nc = 0;

    /* read a character from input and count it */
    while (getchar() != EOF)
        ++nc;
    /* end of file, show all characters counted */
    printf("%ld\n", nc);

    return 0;
}
