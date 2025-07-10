#include <iostream>

using namespace std;
int main() {
    int nums[3];//масив з 3 елементів
    nums[0] = 5;
    nums[1] = 15;
    nums[2] = 25;

    //cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;

    // nums[0] = 45;
    // nums[1] += 10;

    //cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;



    float nums2[3] = {1.1, 2.2, 3.3};
    //cout << nums2[0] << " " << nums2[1] << " " << nums2[2] << endl;

    for (int i = 0; i < 3; i++) {
        cout << nums[i] << endl;
    }
    return 0;
}