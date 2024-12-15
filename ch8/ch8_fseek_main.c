/*
 * ch8_fseek_main.c
 *      Main driver for ch8_fseek(), Exercise 8-4.
 *
 * Description:
 *      Demonstrate the use of Exercise 8-4 by using ch8_fseek() on a test
 *      file.
 *
 * Input:
 *      
 *
 * Output:
 *      Test data added to output file.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 *      To run fseek() without any Standard Library functions we will need
 *      local versions of:
 *      fopen()
 *      fread()
 *      fflush()
 *      fclose()
 *      putchar()
 *      And system calls.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -o ch8_fseek_main ch8_fseek_main.c ch8_fseek.c\
 *      ch8_fopen.c fclose.c ch8_fflush.c
 *
 * Run:
 *      $ ./ch8_fseek_main
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include "syscalls.h"           // system calls
#include "ch8_stdio.h"          // putchar()
#include "ch8_fseek.h"          // fseek()
#include "ch8_fopen.h"          // fopen()
#include "ch8_fflush.h"         // fflush()
#include "ch8_fclose.h"         // fclose()
#include "ch8_fread.h"          // fread()


/* Three files available by default 
 * stdout, stdin, stderr 
 */
FILE _iob[OPEN_MAX] = {
    {0, (char *)0, (char *)0, _READ, 0 },               /* stdin */
    {0, (char *)0, (char *)0, _WRITE, 1 },              /* stdout */
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 }      /* stderr */
};

#define RD_BUF_SIZE 400

char buf[RD_BUF_SIZE];

/* ch8_fseek_main */
int main(int argc, char *argv[])
{
    int i = 0;
    FILE *fp;
    size_t rd = 1;

    fp = ch8_fopen("../extras/millerstale.txt", "r");
    if (fp == NULL)
        return -1;

    rd = ch8_fread(buf, rd, RD_BUF_SIZE, fp);
    //printf("rd = %zu\n", rd);

    for(i = 0; i < RD_BUF_SIZE; i++)
        putchar(buf[i]);
    
    putchar('\n');
    ch8_fflush(stdout);

    if (ch8_fseek(fp, 4*RD_BUF_SIZE, SEEK_CUR) == 0)
        ;
    else {
        ch8_fclose(fp);
        return -1;
    }

    rd = ch8_fread(buf, rd, RD_BUF_SIZE, fp);
    //printf("rd = %zu\n", rd);

    for(i = 0; i < RD_BUF_SIZE; i++)
        putchar(buf[i]);
    
    putchar('\n'); 
    ch8_fflush(stdout);

    ch8_fclose(fp);

    return 0;
}
