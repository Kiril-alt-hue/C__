#include <iostream>
#include <string>

using namespace std;

void minimal(int* arr, int len) { //40 byte + 4 byte
    int min = *arr;
    for (int i = 0; i < len; i++) {
        if (min > *(arr + i))
            min = *(arr + i);
    }
    cout << "Minimal: " << min << endl;
}
int main() {
    //Практичний приклад використання посилань та вказівників
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //40 byte
    minimal(nums, 10);
    return 0;
}