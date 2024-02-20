/* vim:ts=4:sw=4:et:so=10:
 *
 * fseek_main.c
 *      Test fseek() and fflush() from stardard library.
 *      
 * Description:
 *      Read some data from a large file.
 *
 * Build:
 *      $ gcc -o fseek_main ch8_fread_main.c
 *
 * Run:
 *      $ ./fseek_main
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

    if (fseek(fp, 4*RD_BUF_SIZE, SEEK_CUR) == 0)
        ;
    else {
        fclose(fp);
        return -1;
    }

    rd = fread(buf, rd, RD_BUF_SIZE, fp);
    printf("rd = %zu\n", rd);

    for(i = 0; i < RD_BUF_SIZE; i++)
        putchar(buf[i]);
    
    printf("\n"); 

    fclose(fp);

    return 0;
}
