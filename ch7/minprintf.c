/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * minprintf.c
 *      Minimal printf with variable argument list.
 *      Excerpt from section 7.3 with additions for Exercise 7-3.
 *
 * Design:
 *      Converts input to specified data types using a format string
 *      Uses an integer return value and pointer arguments to store
 *      converted values.
 *
 * Build:
 *      See main() driver.
 *
 * Run:
 *      See main() driver.
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include "minprintf.h"

/* minprintf:  minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{

    va_list ap;                     /* points to each unnamed arg in turn */   
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);              /* make ap point 1 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p)  {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival); /* try without printf()? */
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'g'
            default:
                putchar(*p);
                break;              /* default break is defensive programming */
        }
    }
    va_end(ap);                     /* clean up when done */
}
