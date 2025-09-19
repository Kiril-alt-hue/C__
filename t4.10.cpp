#include <stdio.h>

int main() {
    double a = 1.0;
    do{a/=2;} while (1!=a+1);
    printf("a = %e\n", a);
    return 0;
}
