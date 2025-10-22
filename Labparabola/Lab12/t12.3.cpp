#include <iostream>
#include <cmath>     // For std::sqrt
#include <iomanip>   // For std::setw, std::setprecision, std::fixed

const int COLUMN_WIDTH = 7;


void printSeparator(int n) {
    // Print n * COLUMN_WIDTH number of '+' symbols
    for (int i = 0; i < n * COLUMN_WIDTH; ++i) {
        std::cout << "+";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter a natural number n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Error: n must be a natural number (greater than 0)." << std::endl;
        return 1;
    }

    // Set right-alignment for std::setw
    std::cout << std::right;

    printSeparator(n);

    for (int i = 1; i <= n; ++i) {
        std::cout << std::setw(COLUMN_WIDTH) << i;
    }
    std::cout << std::endl; // Move to the next line

    printSeparator(n);

    for (int i = 1; i <= n; ++i) {
        double root = std::sqrt(i);

        long long root_rounded = static_cast<long long>(root + 0.5);

        std::cout << std::setw(COLUMN_WIDTH);

        if (root_rounded * root_rounded == i) {
            std::cout.unsetf(std::ios_base::floatfield);
            std::cout << std::setprecision(0) << root;
        } else {
            std::cout << std::fixed << std::setprecision(2) << root;
        }
    }
    std::cout << std::endl;

    printSeparator(n);

    return 0;
}