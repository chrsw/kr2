/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * minscanf.c
 *      Private version of scanf.c. Solution for Exercise 7.4.
 *
 * Description:
 *      Exercise 7-4 says: "Write a private version of scanf() analogous to
 *      minprintf() from the previous section."
 *      See minprintf.c in this directory for what that entails.
 *      This implementation only supports a few scanf() features as it
 *      for exercise only.
 *      
 *      scanf() is described in Section 7.4. Here are the key points:
 *      - converts stdin input according to 'format'
 *      - stops when the input fails to match 'format'
 *      - stops on EOF
 *      - all arguments after 'format' must be pointers
 *      - returns number of arguments successfully converted
 *      - only a subset of functionality is expected for this exercise
 *      - blanks and tabs are ignored
 *      + conversion specifications:
 *          - start with '%'
 *          - an optional suppression character '*'
 *          - an optional max field width number
 *          - an optional h, l or L
 *          - a conversion character
 *      - literal characters in format string must match input
 *
 *      This file includes the minscanf() main driver.
 *
 * Input:
 *      Format string and pointers to place data.
 *      For example, the format string can be something like:
 *      "n = %d"
 *      But the actual input that corresponds to this format string
 *      can be something like:
 *      "n = 1"
 *
 * Output:
 *      Data specified by format string and input from stdin.
 *
 * Returns:
 *      Number of objects successfully converted.
 *
 * Design:
 *      This function will need to get input and compare the input
 *      to the first argument 'format'. The first time the input
 *      stream doesn't match the 'format' parameter, the function
 *      should return with a count of how many conversions have happened
 *      so far. The conversion specifier in the 'format' string is '%'.
 *      In the simplest sense, this tells the function that the next
 *      sequence of characters on the input should be converted into 
 *      the specified data type.
 *      The data type specifier should be the character after the '%'.
 *      Initially this solution will only support 'd' and 'f' format
 *      conversion specifiers like the text example minprintf().
 * 
 * Implementation:
 *      TBD
 *
 * Build:
 *      $ gcc -o minscanf minscanf.c
 *      - or -
 *      $ make minscanf
 *
 * Run:
 *      $ ./minscanf
 *      Then type the input using the displayed format followed by enter.
 *      See minscanf.txt for examples. The program will run, print the 
 *      converted values then exit.
 *
 *
 * TODO:
 *      Many improvements can be made. Here are some ideas:
 *      No static arrays in case input is malformed.
 *      Don't use string length to drive conversion.
 *      Try reusing functions from earlier chapters, getword()?
 *      Describe how this works in better detail.
 *      Implement some more scanf() features, for example:
 *      - c matches a character
 *      - o matches an octal number
 *      - x matches an unsigned hexadecimal integer
 *      Write functions to do the conversion instead of 
 *      growing the main switch statement.
 *      Get test input string from command line.
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "minscanf.h"

void get_arg(char *, int);

/* minscanf:  formatted input, exercise 7-4 version */
int minscanf(char *format, ...)
{
    va_list ap;                                 /* variadic arg pointer */
    double *pdval;                              /* conversion pointers */
    int *pival;
    long *plval;
    char *pstr;
    int cnt = 0;                                /* conversion count */
    char args[80];                              /* argument string to convert */
                                                /* TODO: use dynamic memory */
                                                /* instead of static array */
   
    va_start(ap, format);                       /* set arg list pointer ap */
                                                /* to the first function arg */

    printf("format = %s\nformat length = %lu\n", format, strlen(format));
    
    /* check if any chars are '%', for the length of the input */
    for (size_t i = 0; i < strlen(format); i++) {
        int c = getchar();

        if (c != format[i] && format[i] != '%') {
            fprintf(stderr, "minscanf: expected: '%c', found: '%c'\n", format[i], c);
            break;                              /* input did not match format */
        }

        if (format[i] == '%') {                 /* conversion specifier */
            switch (format[++i]) {              /* and convert */
            case 'd':                           /* decimal number */
            case 'i':
                get_arg(args, c);                 /* value */
                pival = va_arg(ap, int *);
                *pival = atoi(args);
                cnt++;
                break;
            case 'u':                           /* unsigned number */
                get_arg(args, c);
                pival = va_arg(ap, int *);
                *pival = (unsigned int)atoi(args);
                cnt++;
                break;
            case 'f':                           /* floating point number */
            case 'g':
                get_arg(args, c);
                pdval = va_arg(ap, double *);
                *pdval = atof(args);
                cnt++;
                break;
            case 'l':
                get_arg(args, c);
                plval = va_arg(ap, long *);
                *plval = atol(args);
                cnt++;
                break;
            case 's':
                get_arg(args, c);
                pstr = va_arg(ap, char *);
                strcpy(pstr,args);
                cnt++;
                break;
            case '%':                 /* do nothing, found a literal '%' */
                break;
            default:
                break;
            }
        }
    }

    va_end(ap);
    return cnt;
}


/* minscanf:  driver/test */
int main(int argc, char *argv[])
{
    int count = 0;
    int n;
    double d;
    long l;
    char str[40];

    (void)argc;
    (void)argv;

    count = minscanf("test d%d f%g l%l s%s end", &n, &d, &l, str);
    printf("scan results:\n");
    printf("float = %f, int = %d, long = %li, string = %s, count = %d\n",
           d, n, l, str, count); 

    return 0;
}


/* get_arg get the data for the next arg from standard input */
void get_arg(char *args, int c)
{
    int j = 0;
    args[j++] = c;
    while((c = getchar()) != ' ')
        args[j++] = c;
    ungetc(c, stdin);
    args[j] = '\0';
}