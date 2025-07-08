#include <iostream>

using namespace std;
int main() {
    short num;
    //cout << "Enter number: ";
    //cout << endl;
    cin >> num;

    short num1, num2;

    num1 = num / 10;
    num2 = num % 10;

    short result = num1 + num2;

    //cout << "Sum of numbers: " << result <<  endl;
    cout <<  result << endl;
    return 0;

}