#include <stdio.h>
#include "polynomal11.5.h"

void printMenu() {
    printf("\n--- POLYNOMIAL MANAGER MENU ---\n");
    printf("1. Add a polynomial to the file\n");
    printf("2. Print a polynomial from the file by index\n");
    printf("3. Calculate and print the derivative\n");
    printf("4. Delete a polynomial from the file by index\n");
    printf("5. Replace a coefficient by polynomial index and degree\n");
    printf("0. Exit the program\n");
    printf("Your choice: ");
}

int main() {
    const char* FILENAME = "polynomials.dat";
    int choice;
    int polyIndex, deg;
    double newCoef;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPolynomialToFile(FILENAME);
                break;
            case 2:
                printf("Enter the polynomial index to print: ");
                scanf("%d", &polyIndex);
                printPolynomialFromFile(FILENAME, polyIndex);
                break;
            case 3:
                printf("Enter the polynomial index to find the derivative: ");
                scanf("%d", &polyIndex);
                calculateAndPrintDerivative(FILENAME, polyIndex);
                break;
            case 4:
                printf("Enter the polynomial index to delete: ");
                scanf("%d", &polyIndex);
                deletePolynomialFromFile(FILENAME, polyIndex);
                break;
            case 5:
                printf("Enter the polynomial index: ");
                scanf("%d", &polyIndex);
                printf("Enter the degree of the term to change: ");
                scanf("%d", &deg);
                printf("Enter the new coefficient: ");
                scanf("%lf", &newCoef);
                replaceCoefficient(FILENAME, polyIndex, deg, newCoef);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}