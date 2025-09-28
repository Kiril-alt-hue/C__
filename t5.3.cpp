#include <iostream>
using namespace std;

int find_steps(int n) {
    if (n <= 0) return 0;
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    int max_steps = 0;
    int num = 0;

    for (int n = 1; n < 1000; n++) {
        int steps = find_steps(n);
        if (steps > max_steps) {
            max_steps = steps;
            num = n;
        }
    }

    cout << "Number: " << num << ", Steps: " << max_steps << endl;
    return 0;
}