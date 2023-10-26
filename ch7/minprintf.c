/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * minprintf.c
 *      Minimal printf with variable argument list.
 *      Excerpt from section 7.3.
 *
 * Description:
 *      Template for code and solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.      
 *
 * Build:
 *      How to build this program or a build example (incl make targets).
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdarg.h>
#include <stdio.h>

/* minprintf:  minimal printf with variable argument list */
void minprintf(char *fmt, ...) {

    va_list ap;                 /* points to each unnamed arg in turn */   
    char *p, *sval;
    int ival;
    double dval;
    
    va_start(ap, fmt);          /* make ap point 1 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '&') {
            putchar(*p);
            continue;
        }
        switch (*++p)  {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;          /* why does the 'default' need a 'break'? */
        }
    }
    va_end(ap);     /* clean up when done */
}
