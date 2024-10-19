#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

// Функция, которую мы хотим интегрировать
double f(double x) {
    // Вычисление значения функции f(x) = 0.05x^3 + 0.5x^2 - 5x + 150
    return (0.05 * pow(x,3)) + (0.5 * pow(x,2)) - 5 * x + 150;
}

// Структура для передачи параметров в поток
typedef struct {
    double a;
    double b;
    double h;
    int start;
    int end;
    double* sum;
} thread_params;

// Функция, выполняемая потоком
void* thread_func(void* arg) {
    thread_params* params = (thread_params*) arg;
    double sum_local = 0.0;
    for (int i = params->start; i < params->end; i++) {
        double x = params->a + i * params->h;
        sum_local += f(x);
    }
    *(params->sum) += sum_local;
    return NULL;
}

int main(int argc, char **argv) {
    // Проверка количества аргументов командной строки
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    // Чтение значения n из аргумента командной строки
    double n;
    if (sscanf(argv[1], "%lf", &n) != 1) {
        printf("Invalid number of intervals\n");
        return 1;
    }

    // Определение границ интервала интегрирования
    double a = -20.0; // начало интервала
    double b = 20.0; // конец интервала

    // Вычисление ширины отрезка
    double h = (b - a) / n;

    // Инициализация суммы функций в начале и конце интервала
    double sum = 0.5 * (f(a) + f(b));

    // Создание массива для хранения сумм функций в потоках
    double* thread_sums;
    thread_sums = (double*) calloc(8, sizeof(double));

    // Создание массива для хранения параметров потоков
    thread_params* thread_params_array;
    thread_params_array = (thread_params*) calloc(8, sizeof(thread_params));

    // Создание массива для хранения идентификаторов потоков
    pthread_t* threads;
    threads = (pthread_t*) calloc(8, sizeof(pthread_t));

    // Разделение интервала на 8 частей
    int intervals_per_thread = n / 8;

    // Запуск таймера для измерения времени выполнения
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Создание и запуск потоков
    for (int i = 0; i < 8; i++) {
        thread_params_array[i].a = a;
        thread_params_array[i].b = b;
        thread_params_array[i].h = h;
        thread_params_array[i].start = i * intervals_per_thread;
        thread_params_array[i].end = (i == 7) ? n : (i + 1) * intervals_per_thread;
        thread_params_array[i].sum = &thread_sums[i];
        pthread_create(&threads[i], NULL, thread_func, &thread_params_array[i]);
    }

    // Ожидание завершения потоков
    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }

    // Вычисление суммы функций
    for (int i = 0; i < 8; i++) {
        sum += thread_sums[i];
    }

    // Вычисление интеграла
    double integral = h * sum;

    // Остановка таймера и вычисление времени выполнения
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    // Вывод результатов: количество интервалов, значение интеграла и время выполнения
    printf("%10.0f, ",n);
    printf("%f, ", integral);
    printf("%5.10f\n",execution_time);

    return 1;
}
    