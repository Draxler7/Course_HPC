#include <float.h>
#include <stdio.h>

int main() {
    float f_min = FLT_MIN;
    float f_max = FLT_MAX;

    printf("Float min: %e\n", f_min);
    printf("Float max: %e\n", f_max);

    // Underflow test
    float f_underflow = f_min / 2.0f;
    printf("Float underflow: %e\n", f_underflow);

    // Overflow test
    float f_overflow = f_max * 2.0f;
    printf("Float overflow: %e\n", f_overflow);
    
    printf("\n");

    double d_min = DBL_MIN;
    double d_max = DBL_MAX;

    printf("Double min: %e\n", d_min);
    printf("Double max: %e\n", d_max);

    // Underflow test
    double d_underflow = d_min / 2.0;
    printf("Double underflow: %e\n", d_underflow);

    // Overflow test
    double d_overflow = d_max * 2.0;
    printf("Double overflow: %e\n", d_overflow);

    return 0;
}