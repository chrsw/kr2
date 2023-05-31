#include <stdio.h>

/* nc2.c: count characters in input; 2nd version */

int main(void) {

    double nc;
    nc = 0;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%0.f\n", nc);

    return 0;
}
