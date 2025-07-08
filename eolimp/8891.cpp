#include <iostream>

using namespace std;
int main() {
    short n;
    cin >> n;

    if ((n % 2 == 0||n < 0 && n % 3 == 0) && !(n % 2 == 0&&n < 0 && n % 3 == 0)){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}