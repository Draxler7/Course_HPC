#include <pthread.h>
#include <stdio.h>

void* my_thread_function() {
    printf("Thread Two\n");
    while (1);
}



void main() {
    pthread_t thread;

    int rc = pthread_create(&thread, NULL, my_thread_function, NULL);
    if (rc) {
        printf("Error creating thread: %d\n", rc);
    }

    printf("Main - Thread One\n");
    getchar();
}