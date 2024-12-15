/*      Vim modeline for consistent editor settings across files.
 *
 * rcalc.c
 *      Rudimentary calculator.
 *
 * Description:
 *      Excerpt from Section 7.4
 *
 * Build:
 *      $ gcc -o rcalc rcalc.c
 *
 * Run:
 *      $ ./rcalc
 *
 *      Crtl-D to exit
 *
 */

#include <stdio.h>

/* rudimentary calculator */
int main(int argc, char *argv[])
{

    double sum, v;
    
    sum = 0;
    while (scanf("%lf", &v) == 1)
        printf("\t%.2f\n", sum += v);
    return 0;
}
