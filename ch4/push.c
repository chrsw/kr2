/* vim:ts=4:sw=4:et:so=10:
 *
 * psuh.c
 *      push/pop stack operations.
 *
 * Description:
 *      Excerpt from section 4.3 part of Reverse Polish Notation (RPN)
 *      calculator application.
 *
 * Build:
 *      See rpn.c
 *
 */


#include <stdio.h>

#define MAXVAL 100                      /* maximum depth of val stack */

int sp = 0;                             /* next free stack position */
double val[MAXVAL];                     /* value stack */

/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
int pop() {
    
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
        
    return 0;
}
