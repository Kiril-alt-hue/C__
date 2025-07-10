#include <iostream>

using namespace std;
int main() {
    int matrix[3][2] = {
        {4, 6},
        {2, -45},
        {5, 6}
    };

    // cout << matrix[0][0] << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << endl;
        }
    }
    return 0;
}