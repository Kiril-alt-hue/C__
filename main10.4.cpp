#include "rational10.4.h"

int main() {
    Rational r1 = {1, 3};
    Rational r2 = {2, 5};

    printf("r1 = ");
    printRational(r1);
    printf("r2 = ");
    printRational(r2);

    Rational sum = add(r1, r2);
    printf("Sum = ");
    printRational(sum);

    Rational product = multiply(r1, r2);
    printf("Product = ");
    printRational(product);

    int cmp = compare(r1, r2);
    if (cmp == 0) printf("r1 and r2 are equal.\n");
    else if (cmp > 0) printf("r1 > r2\n");
    else printf("r1 < r2\n");

    return 0;
}
