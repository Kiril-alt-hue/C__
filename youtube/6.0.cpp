#include <iostream>

using namespace std;
int main() {
    // Цикл for


    // for (int i = 0; i < 10; i++) {
    //     cout<<"Element: "<< i<<endl;
    // }

    // for (int i = 100; i >= 25; i -= 15) {
    //     cout<<"Element: "<< i<<endl;
    // }


    //Цикл while


    // int j = 0;
    // while (j < 10) {
    //     cout << "Element: " << j << endl;
    //     j++;
    // }

    // float j = 100;
    // while (j >= 10) {
    //     cout << "Element: " << j << endl;
    //     j /= 2;
    // }


    //Цикл do while (!)
    //різниця з while те, що завжди робимо умову в тілі цикла do один раз
    //а далі вже перевірка умови у while


    int i = 100;
    do {
        cout << "Element: " << i << endl;
        i++;
    } while (i < 10);

    return 0;
}