#include <iostream>

int main() {
    int number1 = 5;
    std::cout << "Result: " << number1 << std::endl;

    number1 = -10;
    std::cout << "Result: " << number1 << std::endl;

    int a, b;
    std::cout << "Enter a number a: ";
    std::cin >> a;  //cin - ввід інформації з консолі
    std::cout << "Enter a number b: ";
    std::cin >> b;

    std::cout<<"Result: " << a << ", " << b << std::endl;

    return 0;
}
