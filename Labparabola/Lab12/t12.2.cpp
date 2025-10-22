#include <iostream>
#include <vector> // We use a vector for a dynamic array

int main() {
    int n;

    std::cout << "Enter the number of items (n): ";
    std::cin >> n;

    std::vector<unsigned long long> numbers(n);

    unsigned long long total_sum = 0;

    std::cout << "Please enter " << n << " (10-digit) numbers, separated by spaces or newlines:" << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];

        total_sum += numbers[i];
    }

    std::cout << "The total sum is: " << total_sum << std::endl;

    return 0;
}