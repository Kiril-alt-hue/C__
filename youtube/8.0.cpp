#include <iostream>

using namespace std;
int main() {
    //Використання динамічної пам'яті ДЛЯ МАСИВІВ

    int* nums = new int[3] {6, 3, 9}; //12 byte + синтаксис при використанні динамічної пам'яті
    nums[0] = 45;
    cout << "Res: " << nums[0] << endl;

    delete[] nums; //видалення масиву

    cout << "Res: " << nums[0] << endl;

    //Використання для звичайних зміних
    int* numbers = new int;

    delete numbers;

    return 0;
}