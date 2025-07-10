#include <iostream>

using namespace std;
int main() {
    // Оператори в циклах
    for (int i = 1; i <= 10; i++) {
        if (i == 8) {
            break;
        }

        if (i % 2 == 0) {
            continue;
        }
         cout << "Element: " << i << endl;
    }

    return 0;
}
