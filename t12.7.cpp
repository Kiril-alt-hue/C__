#include <iostream>  // Для std::cout, std::cerr, std::endl
#include <fstream>   // Для std::ifstream (читання) та std::ofstream (запис)
#include <sstream>   // Для std::stringstream (парсинг рядка)
#include <string>    // Для std::string
#include <vector>    // Для std::vector (динамічний масив)
#include <cmath>     // Для std::asin (arcsin)
#include <iomanip>   // Для std::scientific (наукова нотація)

const char* INPUT_FILENAME = "data.txt";
const char* OUTPUT_FILENAME = "results.txt";
const char DELIMITER = ';';

void create_test_file() {
    std::ofstream file(INPUT_FILENAME);

    if (!file.is_open()) {
        std::cerr << "Error creating test file: " << INPUT_FILENAME << std::endl;
        return;
    }

    file << "0.5; -1.0; 1.5; 0.0; -0.8; 3.14; 0.707; -2.5";

    file.close();
    std::cout << "Created test file: " << INPUT_FILENAME << std::endl;
}

std::vector<double> read_numbers_from_file() {
    std::ifstream file(INPUT_FILENAME);
    std::vector<double> numbers;

    if (!file.is_open()) {
        std::cerr << "Error opening input file: " << INPUT_FILENAME << std::endl;
        return numbers;
    }

    std::string line;
    while (std::getline(file, line)) {
        // std::stringstream дозволяє "розбирати" рядок, ніби це потік
        std::stringstream ss(line);
        std::string token;

        // Ділимо рядок 'line' за роздільником 'DELIMITER'
        while (std::getline(ss, token, DELIMITER)) {
            try {
                // std::stod (string to double) конвертує рядок у double
                double value = std::stod(token);
                // Додаємо значення в кінець вектора
                numbers.push_back(value);
            } catch (const std::invalid_argument& e) {
                // Обробка помилки, якщо токен не є числом (напр., "abc")
                std::cerr << "Warning: Skipping invalid token '" << token << "'" << std::endl;
            } catch (const std::out_of_range& e) {
                // Обробка помилки, якщо число занадто велике
                 std::cerr << "Warning: Skipping out-of-range token '" << token << "'" << std::endl;
            }
        }
    }

    file.close();
    std::cout << "Read " << numbers.size() << " numbers from " << INPUT_FILENAME << "." << std::endl;
    return numbers;
}

std::vector<double> process_arcsin(const std::vector<double>& numbers) {
    std::vector<double> results;
    int ignored_count = 0;

    // Проходимо по кожному числу у вхідному векторі
    // (використовуємо range-based for loop)
    for (double val : numbers) {
        if (val >= -1.0 && val <= 1.0) {
            double arc_val = std::asin(val);
            results.push_back(arc_val);
        } else {
            ignored_count++;
        }
    }

    std::cout << "Processed numbers. Calculated " << results.size()
              << " arcsin values. Ignored " << ignored_count << " values." << std::endl;

    return results;
}

bool write_results_to_file(const std::vector<double>& results) {
    std::ofstream file(OUTPUT_FILENAME);
    if (!file.is_open()) {
        std::cerr << "Error opening output file: " << OUTPUT_FILENAME << std::endl;
        return false;
    }

    std::cout << "Writing " << results.size() << " results to " << OUTPUT_FILENAME << "..." << std::endl;

    // Встановлюємо формат виводу для файлового потоку 'file'
    // std::scientific - наукова нотація
    // std::setprecision(6) - 6 знаків після коми
    file << std::scientific << std::setprecision(6);

    for (double res : results) {
        file << res << std::endl;
    }

    file.close();
    return true;
}

void print_vector(const std::vector<double>& arr, const std::string& title) {
    std::cout << "--- " << title << " (Size: " << arr.size() << ") ---" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "[" << i << "] = " << arr[i] << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}



int main() {
    create_test_file();

    std::vector<double> numbers = read_numbers_from_file();
    if (numbers.empty()) {
        std::cerr << "Main: No numbers were read. Exiting." << std::endl;
        return 1;
    }

    print_vector(numbers, "Initial Numbers");

    std::vector<double> results = process_arcsin(numbers);
    if (results.empty()) {
        std::cout << "Main: No valid results to write." << std::endl;
        return 0;
    }

    print_vector(results, "Arcsin Results (Radians)");

    if (write_results_to_file(results)) {
        std::cout << "Successfully wrote results to " << OUTPUT_FILENAME << "." << std::endl;
    } else {
         std::cerr << "Main: Failed to write results. Exiting." << std::endl;
         return 1;
    }

    return 0;
}