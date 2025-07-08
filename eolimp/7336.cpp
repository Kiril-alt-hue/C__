#include <iostream>

using namespace std;

int main() {
    short gryvni, kopiyky, quantity;
    cin >> gryvni >> kopiyky >> quantity;


    int total_kopiyky = (gryvni * 100 + kopiyky) * quantity;


    short result_gryvni = total_kopiyky / 100;
    short result_kopiyky = total_kopiyky % 100;

    cout << result_gryvni << " " << result_kopiyky;
    return 0;
}