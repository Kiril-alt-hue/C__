#include <iostream>

int main() {
    int a;
    std::cin >> a;

    switch (a) {
        case 5: std::cout << "Number is 5" << std::endl; break;
        case 8: std::cout << "Number is 8" << std::endl; break;
        default: std::cout << "Number is default" << std::endl;
    }
}