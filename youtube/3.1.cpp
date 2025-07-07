#include <iostream>

int main() {
    short num1 = 5; //майже те саме що і int, але діапазон введення приблизно
    // від -32 000 до 32 000 (2 byte)
    // !!!!потрібен для збереження пам'яті!!!!
    int num2 = 10; // від - 2 мільярдів до 2 мальярдів (4 byte)
    long num3 = 100; // більший діапазон (8 byte)
    unsigned short num4 = 200; //unsigned - робить діапазон від 0 і до подвоєного стандарту даного типу
    std::cout << num1 << std::endl;

    float num5 = 3.14f;
    double num6 = 3.14f; //double дає можливість використовуівти дуже багато чисел після крапки

    char sym = '8'; //лише одинарні лапки!!!
    bool isHappy = true;
    return 0;
}