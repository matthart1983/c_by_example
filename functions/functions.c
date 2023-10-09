#include <stdio.h>

int double_number(int x) {
    return x * 2;
}

void double_number_b(int* x) {
    *x *= 2;
}

int main() {
    int num = 5;
    printf("%d\n", double_number(num));
    printf("%d\n", num);
    double_number_b(&num);
    printf("%d\n",num);
}