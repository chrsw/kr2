/* vim:ts=4:sw=4:et:
 *
 * colors.c
 *      Print a short table of numbers sweeping through colors.
 *      
 * Description:
 *      Uses terminal control strings to change the foreground
 *      and background colors.
 *      Sweeps through a list of numbers and colors.
 *
 * Input:
 *      None.
 *
 */


#include <stdio.h>

int main(void)
{
    int i, j, n;

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 10; j++) {
            n = 10 * i + j;
            if (n > 108) break;
            printf("\033[%dm %3d\033[m", n, n);
        }
        printf("\n");
    }
    return 0;
}
