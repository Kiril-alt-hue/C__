#include <stdio.h>

int main() {
    int m, k, r;
    printf("m = ");
    scanf("%d", &m);
    if (m<1) {
        printf("m=1 \n");
    }
    k = 0;
    r = 1;
    while (r<=m) {
        r*=4; k++;
    }
    k--;
    printf("k=%d \n", k);
}