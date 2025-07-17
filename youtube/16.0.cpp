#include <iostream>
#include <string>

using namespace std;

void divide(float a, float b) {
    if (b == 0.0) throw (0);
    cout << (a / b);
}
int main() {
    //Exceptions
    float num;
    cin >> num;

    try {
        divide(5.6, num);
    }
    catch (int e) {
        if (e == 0) {
            cout << "Divide by 0";
        }
    }


    return 0;
}