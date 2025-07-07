#include <iostream>

int main() {
    short num1 = 5; //майже те саме що і int, але діапазон введення приблизно
    // від -32 000 до 32 000 (2 byte)
    // !!!!потрібен для збереження пам'яті!!!!
    std::cout << num1 << std::endl;

    return 0;
}