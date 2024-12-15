/*
 * ex2-4.c
 *      Delete each character in s1 that matches any character in s2.
 *
 * Description:
 *
 * Build:
 *      cc -o ex2-4 ex2-4.c squeeze2.c squeeze.c
 * Input:
 *
 */

#include <stdio.h>

void squeeze2(char s1[], const char s2[]);

int main(int argc, char *argv[]) {

	char s1[20] = {'w', 'h', 'a', 't', 'e', 'v', 'e', 'r', '\0' };
	const char s2[] = "aeiou";
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("squeeze2ing...\n");
	squeeze2(s1, s2);	
	printf("s1: %s\n", s1);
	return 0;
}
