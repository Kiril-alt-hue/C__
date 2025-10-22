#include <iostream>
#include <cmath>
#include <iomanip> // Потрібно для маніпуляторів виводу, таких як fixed та scientific

int main() {
    double x, y;

    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;

    double result = std::pow(x, y);

    // Встановлюємо точність виведення (наприклад, 6 знаків після коми)
    std::cout << std::setprecision(6);

    std::cout << "Result (decimal representation): " << std::fixed << result << std::endl;

    std::cout << "Result (scientific presentation): " << std::scientific << result << std::endl;

    return 0;
}