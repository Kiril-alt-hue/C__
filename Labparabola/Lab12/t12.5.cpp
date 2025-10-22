#include <iostream>
#include <fstream>    // For file I/O (std::ifstream)
#include <vector>     // To store the numbers
#include <string>     // For the filename
#include <cmath>      // For std::sqrt (square root)
#include <iomanip>    // For output formatting (std::fixed, std::setprecision)

const std::string INPUT_FILENAME = "input.txt";

int main() {
    std::ifstream infile(INPUT_FILENAME);

    if (!infile.is_open()) {
        std::cerr << "Error: Could not open input file '" << INPUT_FILENAME << "'." << std::endl;
        return 1;
    }

    std::vector<unsigned long long> numbers;

    unsigned long long current_number;

    while (infile >> current_number) {
        numbers.push_back(current_number);
    }

    infile.close();

    std::cout << std::fixed << std::setprecision(3);


    for (int i = static_cast<int>(numbers.size()) - 1; i >= 0; --i) {

        unsigned long long num = numbers[i];

        double root = std::sqrt(static_cast<double>(num));

        std::cout << root << std::endl;
    }

    return 0;
}