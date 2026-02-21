/*
 * ex2-1.c
 *      Determine ranges of various types.
 *
 * Description:
 *      See ex2-1.txt
 *
 * Build:
 *      $ gcc -o ex2-1 ex2-1.c
 *
 * Run:
 *      $ ./ex2-1
 *
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[])
{
    /* these are all signed by default */
    char ch = 0;
    short sh = 0; 
    int i = 0;
    long l = 0;

    /* for the unsigned values */ 
    unsigned char uch = 0;
    unsigned short ush = 0;
    unsigned int ui = 0;
    unsigned long ul = 0;

    /* show ranges of various types by computation */
    for (ch = 0; ch + 1 > 0; ch++)
        ;
    printf("min char = %hhd\n", ch);  
    printf("max char = %hhd\n\n", --ch);  

    for (sh = 0; sh + 1 > 0; sh++)
        ;
    printf("min short = %hd\n", sh);  
    printf("max short = %hd\n\n", --sh);  

    for (i = 0; i + 1 > 0; i++)
        ;
    printf("min int = %d\n", i);  
    printf("max int = %d\n\n", --i);  

    /* long is 64-bit on the test machine, takes a while to compute like this */ 
    /*for (l = (long)((long)INT_MAX*2); l + 1 > 0; l++)
        ;
    printf("min long = %ld\n", l);  
    printf("max long = %ld\n\n", --l);
    */ 

    /* unsigned types */
    //for (uch = 0; uch + 1 > 0; uch++)
    //    ;
    printf("min unsigned char = %hhu\n", uch = 0);  
    printf("max unsigned char = %hhu\n\n", --uch);  
    printf("min unsigned short = %hu\n", ush = 0);  
    printf("max unsigned short = %hu\n\n", --ush);  
    printf("min unsigned int = %u\n", ui = 0);  
    printf("max unsigned int = %u\n\n", --ui);  
    printf("min unsigned long = %lu\n", ul = 0UL);  
    printf("max unsigned long = %lu\n\n", --ul);  

    
    /* show ranges by header defines */
    printf("min char = %hhd\n", SCHAR_MIN);  
    printf("max char = %hhd\n\n", SCHAR_MAX);  
    printf("min char = %hhd\n", SCHAR_MIN);  
    printf("max char = %hhd\n\n", SCHAR_MAX);  
    printf("min char = %hhd\n", SCHAR_MIN);  
    printf("max char = %hhd\n\n", SCHAR_MAX);  
    printf("min char = %hhd\n", SCHAR_MIN);  
    printf("max char = %hhd\n\n", SCHAR_MAX);  
    
    /* float */
    printf("min float = %g\n",-FLT_MAX); 
    printf("max float = %g\n",FLT_MAX); 

    return 0;
}
