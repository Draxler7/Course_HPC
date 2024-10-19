#include <float.h>
#include <stdio.h>

int main() {
    printf("Float min: %e, max: %e, precision: %d\n", FLT_MIN, FLT_MAX, FLT_DIG);
    printf("Double min: %e, max: %e, precision: %d\n", DBL_MIN, DBL_MAX, DBL_DIG);
    return 0;
}