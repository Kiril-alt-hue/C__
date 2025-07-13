#include <iostream>
#include <string>

using namespace std;

//Скелети функції/прототипи. Описані мною функції знаходяться нижче main
//Використовуються для "гарного та чистого програмування"
void print(string word);
int summa (int a, int b);



// void print(string word) {//void - спеціальний тип даних який вказує що функіція нічого не повертає
//     cout<<word<<endl;
// }
//
// int summa(int a, int b) {
//     int res = a + b;
//     cout<<res<<endl;
//
//     return res;
// }

int main() {

    print("Hi");

    string words = "";
    cin >> words;
    print(words);

    int res1 = summa(3, 4);
    int res2 = summa(2, 4);

    if (res1 > res2) {
        cout<<res1<<endl;
    }
    else
        cout<<res2<<endl;

    return 0;
}

void print(string word) {//void - спеціальний тип даних який вказує що функіція нічого не повертає
    cout<<word<<endl;
}

int summa(int a, int b) {
    int res = a + b;
    cout<<res<<endl;

    return res;
}