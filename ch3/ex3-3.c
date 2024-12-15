/*
 * ex3-3.c
 *      Expand shorthand notations like 'a-f' into 'abcdef'.
 *
 * Description:
 *      Write a function expand(s1,s2) that expands shorthand notations like
 *      a-z in the string s1 into the equivalent complete list abc...xyz in
 *      s2. Allow for letters of either case and digits and bre prepared
 *      to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading
 *      or training - is taken literally.
 *
 *      For simplicity, this exercise can be done in multiple parts.
 *      See history of expand.c for various solutions.
 *
 * Input:
 *      A string s1 in compact notation using the range symbol '-'.
 *      An empty string s2 in which to put the expanded s1.
 *
 */

#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    (void)argc;         /* get rid of warnings about */
    (void)argv;         /* unused args */

    char s1[10] = "a-z";       /* test strings */
    char s2[100];

  
    s2[0] = '\0';
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);


    /* run tests with different input strings */
    printf("\nexpand(%s,s2)\n",s1);
    expand(s1,s2);
    if (s2[0] == '\0')
        printf("s1: %s\n", s1); 
    else
        printf("s2: %s\n", s2); 
   
     
    printf("\nexpand(\"a-h-\",s2)\n");
    //expand("-a-h", s2);
    expand("a-h-", s2);
    if (s2[0] == '\0')
        printf("s1: %s\n", s1); 
    else
        printf("s2: %s\n", s2);

    printf("\nexpand(\"already expanded\",s2)\n");
    expand("already expanded", s2);
    if (s2[0] == '\0')
        printf("s1: %s\n", "already expanded"); 
    else
        printf("s2: %s\n", s2); 
    return 0;
}

