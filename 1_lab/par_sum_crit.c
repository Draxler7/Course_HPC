#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define NTh 20
#define Ns 2000000000
double S = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* my_thread_function(void* arg) {
    int sum = 0;
    for (int i = 0; i < Ns; i++) {
        sum += 1;
    }
    pthread_mutex_lock(&mutex);
    S += sum;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NTh];
    int thread_ids[NTh];
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    for (int i = 0; i<NTh; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, my_thread_function, &thread_ids[i]);
        if (rc) {
            printf("Error creating thread %d: %d\n", i, rc);
        }
    }

    for (int i = 0; i<NTh; i++) {
        void* retval;
        pthread_join(threads[i], &retval);
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    
    printf("%5.0f,", S);
    printf("%d,",Ns);
    printf("%5.10f,",execution_time);
    printf("%5.0f\n",(double) Ns*NTh-S);

}