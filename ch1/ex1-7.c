/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-7.c
 *      Write a program to print the value of EOF.
 *
 */

#include <stdio.h>

int main(void) {

    printf("EOF = %#x (unsigned)\n", EOF);
    printf("EOF = %d (signed)\n", EOF);
    return 0;
}
