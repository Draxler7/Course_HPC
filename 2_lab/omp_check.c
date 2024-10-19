#include <stdio.h>

void main(){
#ifdef _OPENMP
    printf("OpenMP Date: %d\n", _OPENMP);
#else
    printf("Sorry, No OpenMP\n");
#endif
}