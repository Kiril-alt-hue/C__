#include <stdio.h>
#include <math.h> // Для функції pow() (середнє геометричне)

int main() {
    double input_number;
    double sum = 0.0;
    double product = 1.0;
    int count = 0;

    printf("Enter a sequence of non-zero numbers. Enter 0 to finish.\n");

    while (1) {
        printf("a[%d] = ", count);
        scanf("%lf", &input_number);


        if (input_number == 0.0) {
            break;
        }

        sum += input_number;
        product *= input_number;
        count++;
    }


    if (count > 0) {
        double arithmetic_mean = sum / count;
        double geometric_mean = pow(product, 1.0 / count);

        printf("Number of elements entered: %d\n", count);
        printf("Arithmetic mean: %.5f\n", arithmetic_mean);
        printf("Geometric mean: %.5f\n", geometric_mean);
    } else {
        printf("No numbers were entered.\n");
    }

    return 0;
}