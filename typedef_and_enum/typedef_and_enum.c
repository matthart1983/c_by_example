#include <stdio.h>
enum day_of_week {
    mon,
    tue,
    wed,
    thurs,
    fri,
    sat,
    sun
};

typedef unsigned char byte;

int main(){
    byte b1 = 'c';
    printf("byte is set to: %c", b1);
      for(int i = mon; i <= sun; i ++) {
        printf("%d\n", i);
    }
    return 0;
}