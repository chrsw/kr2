#include <stdio.h>

/* nc.c: count characters in input; 1st version */

int main(void) {

    long nc;
    nc = 0;

    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);

    return 0;
}
