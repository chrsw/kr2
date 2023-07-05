/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-5.c
 *      Add access to library functions like sin(), exp() and pow().
 *
 * Description:
 *      func(arg) - (RPN command)
 *      sin(a) - sine of a (s)
 *      exp(a) - base e exponential (e)
 *      pow(a,b) - raise a to the power of b (^)
 *      All of these are defined in math.h
 *
 * Build:
 *      $ gcc -o rpn_ex4-5 ex4-5.c -lm
 * 
 * Input:
 *      One RPN calculation per line, e.g. sine(pi/2):
 *      3.14159265 2 / s
 *
 * Output:
 *      Result of each line-based calculator input, e.g.:
 *              1
 * Tests:
 *     $ ./rpn_ex4-5 < rpn_sine_test.txt
 *     $ ./rpn_ex4-5 < rpn_exp_test.txt
 *     $ ./rpn_ex4-5 < rpn_pow_test.txt
 *
 */

/* includes */
#include <stdio.h>                      /* includes EOF */
#include <stdlib.h>                     /* for atof() */
#include <ctype.h>
#include <math.h>

/* defines */
#define MAXOP 100                       /* max size of operator or operator */
#define NUMBER '0'                      /* signal that a number was found */
#define MAXVAL 100                      /* maximum depth of val stack */
#define BUFSIZE 100                     /* BUFSIZ already defined */

/* function definitions for main */
int getch(void);
void ungetch(int c);
int getop(char []);
void push(double);
double pop(void);

/* external variables for push() and pop() */
int sp = 0;                                     /* next free stack position */
double val[MAXVAL];                             /* value stack */


/* reverse polish calculator program entry here */
int main(void) {

    int type;
    double op1, op2, temp;              /* op1, temp added for swapping */
    char s[MAXOP];

    while ((type = getop(s)) != EOF ){
        switch (type) {
            case NUMBER:
                push(atof(s));          /* atof() supports signed strings */
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
                op2 = (int)pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = (int)pop();       /* mod does not work on doubles */
                if (op2 != 0.0)         /* or floats */
                    push((int)pop() % (int)op2);
                break;
            case 'p':
                if (sp > 0)
                                        /* print top value without popping */
                    printf("\t%.8g\n", val[sp-1]);
                break;
            case 'd':
                if (sp > 0 ){           /* assuming top is number */
                    op2 = pop();        /* duplicate top value */
                    push(op2);
                    push(op2);
                }
               break;
            case '$':
                if (sp > 1) {
                    op2 = pop();        /* use a temporary value to */
                    op1 = pop();        /* swap */
                    temp = op2;
                    op2 = op1;
                    op1 = temp;
                    push(op1);          
                    push(op2);
            }
                break;
            case '#':
                do {                    /* clear stack */
                   pop();               /* pop values until sp is zero */
                } while (--sp > 0);
                break;
            case 's':                   /* sinusoidal: sine(top) */
                push(sin(pop()));
                break; 
            case 'e':                   /* exponential: e ^ top */
                push(exp(pop()));
                break;
            case '^':                   /* power: 2nd top ^ top */
                op2 = pop();
                op1 = pop();
                push(pow(op1,op2));
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

/* get next operator or put numeric operand in s */
int getop(char s[]) {

    int i, c;

    /* skip leading white space */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')    /* accept sign as input */
        return c;                               /* not a number */
    i = 0;
    if (isdigit(c) || c == '-' )                /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                               /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop() {
    
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
        
    return 0;
}

/* external variables for getch() and ungetch() */
char buf[BUFSIZE];                              /* buffer for ungetch() */
int bufp = 0;                                   /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {

    return (bufp > 0) ? buf[--bufp]: getchar();
}

/* push character back on input */
void ungetch(int c) {

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c; 
}
