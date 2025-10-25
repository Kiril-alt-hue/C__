#include <iostream>
#include <vector>     // For std::vector (dynamic arrays)
#include <fstream>    // For std::ifstream (reading) and std::ofstream (writing)
#include <string>     // For std::string (filenames)
#include <cmath>      // For std::pow (power function)
#include <iomanip>    // For std::setprecision (output formatting)


const std::string INPUT_FILENAME = "input.txt";
const std::string OUTPUT_FILENAME = "output.txt";

int main() {
    int n;

    std::cout << "Enter a natural number n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Error: n must be a natural number (greater than 0)." << std::endl;
        return 1; // Exit the program with an error code
    }

    std::vector<int> m_array(n);

    std::cout << "Enter " << n << " integers (the exponents {m_i}), separated by spaces:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> m_array[i];
    }


    std::vector<double> x_array(n);

    std::ifstream infile(INPUT_FILENAME);

    if (!infile.is_open()) {
        std::cerr << "Error: Could not open input file '" << INPUT_FILENAME << "'." << std::endl;
        return 1;
    }

    std::cout << "Reading " << n << " real numbers from file '" << INPUT_FILENAME << "'..." << std::endl;

    for (int i = 0; i < n; ++i) {
        if (!(infile >> x_array[i])) {
            std::cerr << "Error: Problem reading data from file." << std::endl;
            if (infile.eof()) {
                std::cerr << "File contains fewer than " << n << " numbers." << std::endl;
            } else {
                std::cerr << "File contains invalid data (not real numbers)." << std::endl;
            }
            infile.close();
            return 1;
        }
    }

    infile.close();
    std::cout << "Successfully read file '" << INPUT_FILENAME << "'." << std::endl;


    std::vector<double> results(n);

    for (int i = 0; i < n; ++i) {
        results[i] = std::pow(x_array[i], m_array[i]);
    }


    std::ofstream outfile(OUTPUT_FILENAME);


    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create/open output file '" << OUTPUT_FILENAME << "'." << std::endl;
        return 1;
    }

    std::cout << "Writing results to file '" << OUTPUT_FILENAME << "'..." << std::endl;

    outfile << std::fixed << std::setprecision(6);

    for (int i = 0; i < n; ++i) {
        outfile << results[i] << std::endl;
    }

    outfile.close();

    std::cout << "Process finished successfully. Check file '" << OUTPUT_FILENAME << "'." << std::endl;

    return 0;
}