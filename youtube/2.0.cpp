#include <iostream> //використовується для можливості введення та виведення
#include <locale> //бібліотека для setlocale
#include <windows.h>

// кодування для різних мов

int uk() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, ""); // можливість виводу іншими мовами/символами

    std::cout << "Привіт світе!" << std::endl;
    return 0;
}


int main() {
    std::cout << "Hello World!" << std::endl; // endl - початок з нового рядка (закінчення даного рядка)
    /* для новога рядка можна використати \n */
    //звертання std::cout - використовується як звертання до поля
    //а cout - це вивід у консоль
    std::cout << "How are you?" << std::endl;

    uk();


    return 0;
}