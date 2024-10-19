#include <stdio.h>
#include <math.h>
#include <time.h>

// Функция, которую мы хотим интегрировать
float f(float x) {
    return (0.05 * pow(x,3)) + (0.5 * pow(x,2)) - 5 * x + 150; // функция
}

int main() {
    float n = 300000000; // количество отрезков
    float a = -20.0; // начало интервала
    float b = 20.0; // конец интервала
    float h = (b - a) / n; // ширина отрезка
    float sum = 0.5 * (f(a) + f(b)); // сумма функций в начале и конце интервала
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Вычисление суммы функций в середине отрезков
    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        sum += f(x);
    }

    // Вычисление интеграла
    float integral = h * sum;

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Интеграл функции от %f до %f равен %f\n", a, b, integral);
    printf("Time = %5.10f\n,",execution_time);

    return 0;
}