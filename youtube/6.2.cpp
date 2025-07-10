#include <iostream>

using namespace std;
int main() {
    int rand_num = 1 + rand() % 10;
    bool isstop = false;
    int user_num;

    do {
        cout << "Enter a number: ";
        cin >> user_num;
        if (user_num != rand_num) {
            cout << "Wrong input!" << endl;
        }
        else
            isstop = true;
    } while (!isstop);

    cout << "Correct!" << endl;

    return 0;
}