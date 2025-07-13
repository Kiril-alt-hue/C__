#include <iostream>
#include <string>

using namespace std;
int main() {

    // Посилання
    int num = 10; // 4 byte
    int &a = num; // 4 byte. & - посилання і займає менше пам'яті (1-2 byte)


    a = 15; //змінюється і в а, і в num
    cout << &num << " - " << num << endl;
    cout << &a << " - " << a << endl;


    // Вказівники
    int val = 12;
    int *ptr = &val;
    ptr = &val;

    *ptr = 20;
    //ptr = nullptr;

    cout << &val << " - " << val << endl;
    cout << ptr << " - " << *ptr << endl;
    return 0;
}