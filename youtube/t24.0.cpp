#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2> // Шаблон функції. Приймає тип даних

void print_arr(T1* arr, T2 len) {
    for (T2 i = 0; i < len; i++) {
        cout << *(arr + i) << " " << endl;
    }
}

// void print_arr(float* arr, int len) {
//     for (int i = 0; i < len; i++) {
//         cout << *(arr + i) << " " << endl;
//     }
// }

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_arr<int, int>(arr1, 10);

    float arr2[] = {1.0, 2.0, 3.0, 4.0};
    print_arr<float, int>(arr2, 4);

    return 0;
}