/* vim:ts=4:sw=4:et:so=10:
 *
 * stack.c
 *      Simple stack used with RPN calculator from section 4.3
 *
 */

#include <stdio.h>
#include "calc.h"

int sp = 0;
double val[MAXVAL];


/* push: a floating point number onto value stack */
void push(double f) {

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("push: error: stack full, can't push %g\n", f);
}


/* pop: top floating point value from stack */
double pop(void) {
    
    if (sp > 0)
        return val[--sp];
    else {
        printf("pop: error: stack empty\n");
        return 0.0;
    }
}
