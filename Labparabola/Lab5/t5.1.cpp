#include <iostream>

using namespace std;

double sum (double a) {
    int n = 1;
    double count = 1;
    while (count < a) {
        count += 1.0/n;
        n++;

    }
    return count;
}

int main() {
    double a;
    cin >> a;
    cout << sum(a) << endl;
    return 0;
}