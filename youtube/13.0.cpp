#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main() {

    // ofstream file("test.txt", ios_base::out); //для запису у файл
    // if (file.is_open()) {
    //     file<<"Some info";
    //     file.close();
    // }

    ifstream file("test.txt"); //зчитування даних
    if (file.is_open()) {
        // string temp;
        // file >> temp;

        char temp[100];
        file.getline(temp, 100);

        cout << temp << endl;

        file.close();
    }

    return 0;
}