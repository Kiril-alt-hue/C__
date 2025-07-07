#include <iostream>

using namespace std; //це - простір імен і після цього не потрібно всюди писати std

int main() {
    srand(time(NULL));//кожен раз генерує нове число, дуже важливо!!
    int result = 1 + rand() % 5; //rand() - рандомайзер, діапазон від 1 до 5
    cout << result << endl;

    float num1, num2;

    std::cout << "Enter number 1: ";
    std::cin >> num1;

    std::cout << "Enter number 2: ";
    std::cin >> num2;

    char math;
    std::cout << "Enter math symbol: ";
    std::cin >> math;

    // if (math == '+') {
    //     std::cout << num1 + num2 << std::endl;
    // }
    //
    // else if (math == '-') {
    //     std::cout << num1 - num2 << std::endl;
    // }
    //
    // else if (math == '*') {
    //     std::cout << num1 * num2 << std::endl;
    // }
    //
    // else if (math == '/') {
    //     if (num2 == 0) {
    //         std::cout << "Erorr" << std::endl;
    //     }
    //     else {
    //         std::cout << num1 / num2 << std::endl;
    //     }
    // }
    switch (math) {
        case '+': std::cout << num1 + num2; break;
            case '-': std::cout << num1 - num2; break;
            case '*': std::cout << num1 * num2; break;
            case '/': if (num2 == 0.0f) {
                std::cout << "Division by 0" << std::endl;
            }
            else {
                std::cout << num1 / num2;
            }
            break;
            default: std::cout << "Invalid math symbol" << std::endl;
    }
    return 0;
}