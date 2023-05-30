/* vim:ts=4:sw=4:et:so=10:
 *
 * stack.c
 *      Simple stack used with RPN calculator from section 4.3
 *
 * Description:
 *
 * Input:
 *
 * Other info:
 *
 */

#include <stdio.h>

void push(double f);
double pop(void);

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int main(int argc, char *argv[]) {


    return 0;
}


/* push f onto value stack */
void push(double f) {

    if (sp < MAXVAL)
        val[sp++];
    else
        printf("push: error: stack full, can't push %g\n", f);
}

/* pop top value from stack */
double pop(void) {
    
    if (sp > 0)
        return val[--sp];
    else {
        printf("pop: error: stack empty\n");
        return 0.0;
    }
}
