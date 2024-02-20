/* vim:ts=4:sw=4:et:so=10:
 *
 * fread_main.c
 *      Test fread() and fflush() from stardard library.
 *      
 * Description:
 *      Read some data from a large file.
 *
 * Build:
 *      $ gcc -o fread_main ch8_fread_main.c
 *
 * Run:
 *      $ ./fread_main
 *
 */

#include <string.h>
#include <stdio.h>

#define RD_BUF_SIZE 400

char buf[RD_BUF_SIZE];

int main(void) {
    
    int i = 0;
    FILE *fp;
    size_t rd = 1;

    fp = fopen("../extras/millerstale.txt", "r");
    if (fp == NULL)
        return -1;

    rd = fread(buf, rd, RD_BUF_SIZE, fp);
    printf("rd = %zu\n", rd);

    for(i = 0; i < RD_BUF_SIZE; i++)
        putchar(buf[i]);
    
    printf("\n"); 

    fclose(fp);

    return 0;
}
