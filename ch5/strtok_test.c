/* vim:ts=4:sw=4:et:so=10:ls=2:
 * 
 *  strtok_test.c
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *s = "five six seven eight";


int main(int argc, char *argv[]) {

    char *tok;
    char *k;
    int field = 0;
    int i = 0;
    const char *ct = " ";

    if (argc != 2) {
        printf("strtok_test: error: wrong number of args\n");
        return -1;
    }
    else {
        field = atoi(argv[1]);
    }

    tok = (char *)malloc(sizeof(s)+1);
    if (!tok) {
        printf("strtok_test: error: can't allocate memory\n");
    }
        
    strcpy(tok, s);
    printf("tok = %s\n", tok);
    printf("field = %d\n", field);
    k = strtok(tok, ct);
    printf("after %d strtok(), k = %s, tok = %s\n", i+1, k, tok);
    for (i = 0; i < field; i++) {
        k = strtok(NULL, ct);
        printf("after %d strtok(), k = %s, tok = %s\n", i+1, k, tok);
    }
        
    return 0;
}
