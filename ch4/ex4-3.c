/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-3.c
 *      Add the modulus (%) operator and signed support to the
 *      RPN calculator.
 *
 * Description:
 *      The % (or modulo) operator returns the remainder of a
 *      dividend divided by a divisor. Integer support only.
 *
 * Build:
 *      $ gcc -o rpn_ex4-3 ex4-3.c
 * 
 * Input:
 *      One RPN calculation per line, e.g.:
 *      20 % 3
 *      11 * -1
 *
 * Output:
 *      Result of each line-based calculator input, e.g.:
 *              2
 *            -22
 * Test:
 *     $ ./rpn_ex4-3 < rpn_modulo_test.txt
 *     $ ./rpn_ex4-3 < rpn_neg_test.txt
 *
 */

/* includes */
#include <stdio.h>                      /* includes EOF */
#include <stdlib.h>                     /* for atof() */
#include <ctype.h>

/* defines */
#define MAXOP 100                       /* max size of operator or operator */
#define NUMBER '0'                      /* signal that a number was found */
#define MAXVAL 100                      /* maximum depth of val stack */
#define BUFSIZE     100                 /* BUFSIZ already defined */

/* function definitions for main */
int getch(void);
void ungetch(int c);
int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator program entry here */
int main(void) {

    int type;
    double op2;
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
                op2 = (int)pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
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

int getop(char s[]) {

    int i, c;
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

/* external variables for push() and pop() */
int sp = 0;                                     /* next free stack position */
double val[MAXVAL];                             /* value stack */

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
