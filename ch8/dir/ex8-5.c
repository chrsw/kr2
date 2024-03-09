/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ex8-5.c
 *      Main entry point for ftime app.
 *
 * Description:
 *      Print file modification times recursively.
 *
 * Input:
 *      Optional directory name.
 *
 * Output:
 *      File names and modification time on standard output.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o ftime ex8-5.c ftime.c dirwalk.c
 *
 * Run:
 *      $ ./ftime
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */


void ftime(char *name);


/* print file times */
int main(int argc, char *argv[])
{
    if (argc == 1)
        ftime(".");
    else
        while (--argc > 0)
            ftime(*++argv);
    return 0;
}
