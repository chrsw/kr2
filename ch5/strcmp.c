/* vim:ts=4:sw=4:et:so=10:
 *
 * strcmp.c
 *      Compare strings s, t. Return -1 if s less than t, 0 if s equal to t
 *      and 1 if s greater than t.
 *
 * Input:
 *      Describe the expected input.
 *
 * Build:
 *      $ gcc -c strcmp.c
 *
 * Run:
 *      An example of how this program should be run.
 *
 */


int ch5_strcmp(char *s, char *t);

int ch5_strcmp(char *s, char *t) {

    int ret = 0;
    char *s2 = s;
    char *t2 = t;

    
    while (*s != '\0') {
        if (*s > *t)
            return 1;
        else if (*s < *t)
            return -1;
        else {
            s++;
            t++;
        }
    }

    if (strlen(t2) > strlen(s2))
       return -1; 

    return ret;
}
