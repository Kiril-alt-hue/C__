#include <iostream>
#include <string>

using namespace std;
//Перевантаження функцій. Тобто ми маємо однакову назву але перезевантажуємо її тип або кількість параметрів
void print(string word)
{
    cout << word << endl;
}

void print(int word)
{
    cout << word << endl;
}

void print(float word)
{
    cout << word << endl;
}

void mult (int a, int b) {
    int res = a * b;
    print(res);
}

void mult (float a, float b, float c) {
    float res = a * b * c;
    print(res);
}

int main() {

    print("hello");
    mult (1, 2);
    mult (2.4, 3.6, 4);

    return 0;
}