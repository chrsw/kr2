/* vim:ts=4:sw=4:et:so=10:
 *
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
 *
 * Input:
 *      A string s1 in compact notation using the range symbol '-'.
 *      An empty string s2 in which to put the expanded s1.
 *
 *
 */

#include <stdio.h>
#include <string.h>

void expand1(char s1[], char s2[]);
void expand2(char s1[], char s2[]);


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char s1_1[] = "already expanded";
    char s1_2[] = "a-z";
    char s2[100];
   

    expand1(s1_1,s2);
    if (*s2)
        printf("%s\n", s2); 
    else
        printf("s1: %s\n", s1_1); 

    expand1(s1_2,s2);
    if (*s2)
        printf("%s\n", s2); 
    else
        printf("s1: %s\n", s1_1); 

    expand2("a-h", s2);
    printf("expand(\"a-f\",s2)");
    printf("\ns2: %s\n", s2);
    return 0;
}



/*
 * This function will take a string s1 which must contain the compact range
 * operator '-'. (TODO: find the actual name for this symbol in this conext).
 * This will be exercise will be completed in parts, starting with this
 * function expand1() which will only return silently if the string s1
 * contains the '-' character in s1. If there is no '-' character in s1,
 * s2 will be set to NULL. s1 cannot be NULL.
 */
void expand1(char s1[], char s2[]) {

    if (strchr((const char *)s1, '-'))
        strcpy(s2,"compacted");
    else
        s2 = NULL;

}

/* expand the simple case of '.-.' where . is any letter */
void expand2(char s1[], char s2[]) {

    char start;
    char end;
    char c;
    int i = 0;
    
    start = s1[0];
    end = s1[2];

    for (c = start; c <= end; c++)
       s2[i++] = c;
   s2[i] = '\0';
}


