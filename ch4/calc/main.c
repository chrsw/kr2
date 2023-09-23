/* vim:ts=4:sw=4:et:so=10:
 *
 * main.c
 *      main() for Reverse Polish Notation (RPN) calculator.
 *
 * Description:
 *      Excerpt from section 4.3, part of Reverse Polish Notation (RPN)
 *      calculator application. Split into multiple source/header files.
 *      Additions from the exercises related to the RPM calculator.
 *
 * Build:
 *      $ make
 *
 */


#include <stdio.h>
#include <stdlib.h>                             /* atof() */
#include <math.h>
#include <stdbool.h>
#include "calc.h"                               /* getop(), pop(), etc */

static bool used_vars[MAXVARS] = {false};
static double vars[MAXVARS] = {0.f};

int main(void) {

    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF ){
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = (int)pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                break;
            case 's':
                push(sin(pop()));
                break; 
            case 'e':
                push(exp(pop()));
                break;
            case '^':
                op2 = pop();
                op1 = pop();
                push(pow(op1,op2));
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                if (!used_vars[type-'W']) {
                    vars[type-'W'] = pop();
                    used_vars[type-'W'] = true;
                    push(vars[type-'W']);
                } else {
                    push(vars[type-'W']);
                }
                break;
            case 'p':
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case '$':
                op2 = pop();
                op1 = pop();
                push(op1);
                push(op2);
                break;
            case '#':
                while (gp() > 0) pop();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

    }

    return 0;
}
