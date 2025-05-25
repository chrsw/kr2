/*
 * ex4-14.c
 *		Define a macro swap(t,x,y) that interchanges two arguments of
 * 		type t. (Block structure will help.)
 *
 */

#include <stdio.h>
#include <limits.h>

#define swap(t,x,y) do { \
					t temp;\
					temp = x;\
					x = y;\
					y = temp;\
				} while (0);

int main(void) {

	int x = INT_MAX;
	int y = 0;
	printf("x = %d\ny = %d\n", x, y);
	printf("swapping...\n");
	swap(int, x, y);
	printf("x = %d\ny = %d\n", x, y);
	return 0;
}
