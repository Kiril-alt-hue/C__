#include "Polynomial15.3.h"
#include <fstream>
#include <iostream>


const std::string BINARY_FILENAME = "polynomial_data.bin";


int main() {
    std::cout << "=================================================" << std::endl;
    std::cout << "TESTING THE POLYNOMIAL CLASS" << std::endl;
    std::cout << "=================================================" << std::endl;

    std::cout << "\n--- 1. Size Constructor and setCoefficients Method ---" << std::endl;

    // Створюємо поліном степеня 2 (3 коефіцієнти: x^0, x^1, x^2)
    Polynomial p1(3);
    double initial_coeffs[] = {5.0, -1.0, 3.0}; // 3x^2 - 1x + 5
    p1.setCoefficients(initial_coeffs);

    std::cout << "Polynomial p1 (3x^2 - x + 5): ";
    p1.print();

    std::cout << "\n--- 2. Copy Constructor Test ---" << std::endl;
    Polynomial p2 = p1;
    std::cout << "Polynomial p2 (Copy of p1): ";
    p2.print();

    p2.setCoefficient(2, 7.7); // Змінюємо 3.0x^2 на 7.7x^2
    std::cout << "Polynomial p2 after change (7.7x^2 - x + 5): ";
    p2.print();

    std::cout << "Original p1 remains: ";
    p1.print(); // p1 має залишитися без змін

    std::cout << "\n--- 3. Assignment Operator Test ---" << std::endl;
    Polynomial p3(5);
    p3 = p1; // Присвоюємо p1 до p3 (p3 змінить розмір і скопіює дані)
    std::cout << "Polynomial p3 (assigned p1): ";
    p3.print();

    std::cout << "\n--- 4. Friendly Functions (I/O) Test ---" << std::endl;
    Polynomial p4(2); // Поліном з 2 коефіцієнтами (x^0, x^1)

    std::cout << "Enter coefficients for p4 (4x + 8 expected):" << std::endl;
    std::cin >> p4;

    std::cout << "Polynomial p4 (using operator <<): " << p4 << std::endl;

    std::cout << "\n--- 5. Binary File Write Test ---" << std::endl;
    std::ofstream ofs(BINARY_FILENAME, std::ios::binary);

    if (ofs.is_open()) {
        writeToBinaryFile(ofs, p4);
        ofs.close();
        std::cout << "Polynomial p4 successfully written to " << BINARY_FILENAME << std::endl;
    } else {
        std::cerr << "Error: Could not open file for binary write." << std::endl;
    }

    std::cout << "\n--- Additional Desired Operator ---" << std::endl;
    std::cout << "The assignment operator ('=') is the most important operator to overload besides the copy constructor." << std::endl;
    std::cout << "It ensures correct deep copying and memory management when assigning objects (e.g., p3 = p1)." << std::endl;


    return 0;
}