/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ex8-5.c
 *      Main entry point for finfo app.
 *
 * Description:
 *      Print file information recursively.
 *
 * Input:
 *      Optional directory name.
 *
 * Output:
 *      File names and other info on standard output.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o finfo ex8-5.c finfo.c dirwalk.c
 *      - or -
 *      $ make finfo
 *
 * Run:
 *      $ ./finfo
 *
 */


void finfo(char *name);


/* print file times */
int main(int argc, char *argv[])
{
    if (argc == 1)
        finfo(".");
    else
        while (--argc > 0)
            finfo(*++argv);
    return 0;
}
