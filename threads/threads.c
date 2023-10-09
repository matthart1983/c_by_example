#include <stdio.h>
#include <threads.h>

int thread_func(void* arg){
    printf("Printing from thread");
    return 0;
}

int main() {
    thrd_t thread_id;
    thrd_create(&thread_id, thread_func, NULL);
    thrd_join(thread_id, NULL);
    printf("Thread returned\n");
    return 0;
}