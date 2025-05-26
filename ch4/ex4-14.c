/*
 * ex4-14.c
 *		Define a macro swap(t,x,y) that interchanges two arguments of
 * 		type t. (Block structure will help.)
 *
 * Build:
 * 		$ gcc -o ex4-14 ex4-14.c
 */

#include <stdio.h>

#undef swap
#define swap(t,x,y) do {     \
					t temp;  \
					temp = x;\
					x = y;   \
					y = temp;\
				} while (0);

int main(void) {

	int x = 111;
	int y = 0;
	printf("orignal values:\n");
	printf("x = %d\ty = %d\n", x, y);
	printf("after swapping with swap(t,x,y) macro:\n");
	swap(int, x, y);
	printf("x = %d\ty = %d\n", x, y);
	return 0;
}
