#include <stdio.h>

union my_data {
    int i;
    float f;
    char str[20];
};

int main() {
    union my_data object1;
    printf("Size of my_data union: %lu\n", sizeof(object1));
    return 0;
}