/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * main.c
 *      Main entry point for fsize app.
 *
 * Description:
 *      Print file sizes recursively.
 *
 * Input:
 *      Optional directory name.
 *
 * Output:
 *      File names and sizes on standard output.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o fsize main.c fsize.c dirwalk.c
 *
 * Run:
 *      $ ./fsize
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */


void fsize(char *name);


/* print file sizes */
int main(int argc, char *argv[])
{
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}
