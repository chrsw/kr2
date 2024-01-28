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
 *      See minscanf.txt for examples.
 *
 *
 * TODO:
 *      Many improvements can be made here. For example, no static arrays
 *      in case input is malformed.
 *      Don't use string length to drive conversion.
 *      Try reusing functions from earlier chapters, getword()?
 *      Describe how this works in better detail.
 *      Implement some more scanf() features, for example:
 *      - s matches a string of non-white-space characters
 *      - c matches a character
 *      - o matches an octal number
 *      - x matches an unsigned hexadecimal integer
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "minscanf.h"


/* minscanf:  formatted input, exercise 7-4 version */
int minscanf(char *format, ...)
{
    va_list ap;                                 /* variadic arg pointer */
    double *pdval;                              /* conversion pointers */
    int *pival;
    long *plval;
    int cnt = 0;                                /* conversion count */
    char args[80];                              /* argument string */
   
    va_start(ap, format);
    
    /* check if any chars are '%', for the length of the input */
    for (int i = 0; i < (int)strlen(format); i++) {
        int c = getchar();

        if (c != format[i] && format[i] != '%')
            break;                              /* input did not match format */

        if (format[i] == '%') {                 /* conversion specifier */
            int j;                              /* find conversion type */
            switch (format[++i]) {              /* and convert */
            case 'd':                           /* decimal number */
            case 'i':
                j = 0;
                args[j++] = c;
                while ((c = getchar()) != ' ')
                    args[j++] = c;
                args[j] = '\0';
                pival = va_arg(ap, int *);
                *pival = atoi(args);
                cnt++;
                break;
            case 'u':                           /* unsigned number */
                j = 0;
                args[j++] = c;
                while ((c = getchar()) != ' ')
                    args[j++] = c;
                args[j] = '\0';
                pival = va_arg(ap, int *);
                *pival = (unsigned int)atoi(args);
                cnt++;
                break;
            case 'f':                           /* floating point number */
            case 'g':
                j = 0;
                args[j++] = c;
                while ((c = getchar()) != ' ')
                    args[j++] = c;
                args[j] = '\0';
                pdval = va_arg(ap, double *);
                *pdval = atof(args);
                cnt++;
                break;
            case 'l':
                j = 0;
                args[j++] = c;
                while ((c = getchar()) != ' ')
                    args[j++] = c;
                args[j] = '\0';
                plval = va_arg(ap, long *);
                *plval = atol(args);
                cnt++;
                break;
            case '%':                 /* do nothing, found a literal '%' */
                break;
            default:
                fprintf(stderr, "minscanf: spec error: c = %c\n", c);
                break;
            }
        }
    }

    va_end(ap);
    return cnt;
}


int main(int argc, char *argv[])
{
    int count = 0;
    int pn;
    double pd;
    long pl;

    (void)argc;
    (void)argv;

    printf("input: testf%%ff%%ddlong%%l l\n");
    count = minscanf("testf%ffd%ddllong%l l", &pd, &pn, &pl);
    printf("float scanned = %f, int scanned = %d,\
            long scanned = %li, args converted = %d\n",
            pd, pn, pl, count); 
    return 0;
}
