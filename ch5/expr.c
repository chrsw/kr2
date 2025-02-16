/*
 * expr.c
 *      Solution for exercise 5-10.
 *      RPN calculator using command line instead of standard input.
 *
 * Description:
 *      Write the program 'expr', which evaluates a reverse Polish expression
 *      from the command line, where each operator or operand is a separate
 *      argument. For example,
 *      expr 2 3 4 + *
 *      evaluates 2 * (3+4).
 *      Use an array built from the command line instead of standard input.
 *
 * Build:
 *      $ gcc -o expr expr.c
 *      -or-
 *      $ gcc -o ex5-10 expr.c
 * 
 * Test:
 *     $ ./expr 1 2 +
 *
 * Output:
 *      Result of command line input, e.g.:
 *              3
 *
 */

/* includes */
#include <stdio.h>                      /* includes EOF */
#include <stdlib.h>                     /* for atof() */
#include <ctype.h>                      /* isdigit(), etc */
#include <string.h>

/* defines */
#define MAXOP 100                       /* max size of operand or operator */
#define NUMBER '0'                      /* signal that a number was found */
#define MAXVAL 100                      /* maximum depth of stack */
#define BUFSIZE 100                     /* BUFSIZ defined in stdio */

/* function definitions for main, getop */
int getch(void);
void ungetch(int c);
int getop(char s[]);
void push(double);
double pop(void);

/* external variables for getch() and ungetch() */
char buf[BUFSIZE];                              /* buffer for ungetch() */
int bufp = 0;                                   /* next free position in buf */
char *gp;


/* reverse polish calculator program entry here */
int main(int argc, char *argv[]) {

    int type;
    double op2;
    char s[MAXOP];
    int i = 0;

    char *p = (char *)malloc(BUFSIZE);
    p[0] = '\0';

    ++argv;                                 /* ignore the command name */

    while (--argc > 0) {                    /* copy each command line arg */
        strcat(p, *argv++);                 /* to the end of array */
        strcat(p, " ");
    }
    p[strlen(p)-1] = '\n';
    gp = p;
    while ((type = getop(s)) != '\0' ){
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
                    fprintf(stderr, "error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                fprintf(stderr, "error: unknown command %s\n", s);
                break;
        }

    }

    return 0;
}

/* parse operators and operands */
int getop(char s[]) {

    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;                               /* not a number */
    i = 0;
    if (isdigit(c))                             /* collect integer part */
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
        fprintf(stderr, "error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop() {
    
    if (sp > 0)
        return val[--sp];
    else {
        fprintf(stderr, "error: stack empty\n");
        return 0.0;
    }
        
    return 0;
}


/* get a (possibly pushed back) character */
int getch(void) {

    return (bufp > 0) ? buf[--bufp] : *gp++;
}


/* push character back on input */
void ungetch(int c) {

    if (bufp >= BUFSIZE)
        fprintf(stderr, "ungetch: too many characters\n");
    else
        buf[bufp++] = c; 
}
