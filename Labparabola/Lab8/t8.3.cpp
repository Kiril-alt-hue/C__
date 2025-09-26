#include <iostream>
using namespace std;

static const int N = 20;
static const int M = 20;


void InputMatrix(double Matr[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> Matr[i][j];
        }
    }
}


void OutputMatrix(double Matr[N][M], int n, int m) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << Matr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    double Matr[N][M];

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    InputMatrix(Matr, n, m);
    OutputMatrix(Matr, n, m);

    return 0;
}
