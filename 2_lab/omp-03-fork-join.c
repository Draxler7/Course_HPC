#include <stdio.h>

void main(){
printf("1\n");

#pragma omp parallel
    printf("2\n");

printf("3\n");
}