#include <stdio.h>
#include <stdlib.h>

int main() {
    int* x = (int*) malloc(sizeof(int));
    *x=1;
    printf("x has been allocated and set to : %d \n", *x );
    if (x) {
        free(x);
        printf("x has been freed");
    }
    return 0;
}