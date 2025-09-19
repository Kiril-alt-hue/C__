#include <stdio.h>

int main() {
    double temperature_celcius;
    double temperature_fahrenheit;
    printf("Enter a temperature in Celcius: ");
    scanf_s("%lf",&temperature_celcius); //format %lf for double
    temperature_fahrenheit = (temperature_celcius * 1.8) + 32;
    printf("%gC is equal to %gF\n",//format %g for better out
        temperature_celcius, temperature_fahrenheit);
    return 0;
}