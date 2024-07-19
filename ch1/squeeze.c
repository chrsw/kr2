/* $ gcc -c squeeze.c */

/* squeeze:  delete all c from s */
void squeeze( char c, char *s) {

    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
