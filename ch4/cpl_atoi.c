/*
 * cpl_atoi.c
 *      Convert string s to integer using cpl_atof.
 *
 * Description:
 *      Excerpt from section 4.2.
 *
 * Input:
 *      String s.
 *
 * Build:
 *      $ gcc -c cpl_atoi.c
 *
 */

int cpl_atoi(char s[]) {

    double cpl_atof(char s[]);

    return (int) cpl_atof(s);
}
