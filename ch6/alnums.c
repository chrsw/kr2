// vim:ts=4:sw=4:et:so=10:ls=2:

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {

    printf("isalnum(\") = %d\n", isalnum('"'));
    printf("isalnum(\\) = %d\n", isalnum('\\'));
    printf("isalnum(\') = %d\n", isalnum('\''));
    printf("isalnum(*) = %d\n", isalnum('*'));
    printf("isalnum(/) = %d\n", isalnum('/'));
    printf("isalnum(a) = %d\n", isalnum('a'));
    printf("isalnum(b) = %d\n", isalnum('b'));
    printf("isalnum(_) = %d\n", isalnum('_'));
    printf("isalnum(.) = %d\n", isalnum('.'));
    printf("isalnum(\\n) = %d\n", isalnum('\n'));

    return 0;
}
