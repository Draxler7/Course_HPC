#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "-100000000000000000000";
    long long num = atoll(str);
    printf("The string value is: ");
    printf(str);
    printf("\n");
    printf("The integer value is: %lld\n", num);
    return 0;
}
