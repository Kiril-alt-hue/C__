#include <iostream>

using namespace std;
int main() {
    short num;
    //cout << "Enter a number: ";
    cin >> num;

    short first = num / 100;
    short last = num % 10;

    if (first == last) {
        cout<< "=";
    }
        else if (first > last) {
            cout << first;
        }

    else {
        cout << last;
    }

    return 0;
}