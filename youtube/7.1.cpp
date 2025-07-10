#include <iostream>

using namespace std;
int main() {
    int nums[4];

    for (int i = 0; i < 4; i++) {
        cout <<"Enter numbers: ";
        cin >> nums[i];
    }

    int sum = 0;
    int min = nums[0];
    for (int i = 0; i < 4; i++) {
        sum += nums[i];
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    cout << "Sum: " << sum << endl;
    cout << "Min: " << min << endl;


    for (int i = 0; i < 4; i++) {
        cout << "El: " << nums[i] << endl;
    }
    return 0;
}