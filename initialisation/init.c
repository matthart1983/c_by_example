#include <stdio.h>

int main() {
    int a = 0;
    char greeting_a[8] = {'1', 'e','l','l','o','\n','\0'};
    char greeting_b[] = "2Hello\n\0";
    char* greeting_c = "3Hello\n\0";
    printf("%s", greeting_a);
    printf("%s", greeting_b);
    printf("%s", greeting_c);
    return 0;
}

