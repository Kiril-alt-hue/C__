#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
int main() {
    //Вбудовані функції
    string str1 = "Hello";
    string str2 = "World";

    str1.append(str2);
    //str1 += str2
    str1.pop_back(); //видаляє останній символ

    str1.push_back('!'); //приймає лише символи. додає до кінця заданий символ
    str1.resize(5); // перші 5 символів


    cout << str1 << endl;
    cout << str1.length() << endl;

    cout << pow(2,3) << endl;
    cout << abs(-3) << endl;
    cout << sin(2) << endl;
    cout << sqrt(16) << endl;

    cout << ceil(2.89) << endl; //округлення до більшого
    cout << floor(2.89) << endl; //округлення до меншого
    cout << round(2.89) << endl; //стандартне округлення


    return 0;
}