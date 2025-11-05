#include <iostream>]
#include <string>

using namespace std;

template <class T1, class T2>

class Arrays {
    private:
        T2 len;
        T1 *arr;
    public:
        Arrays(T1* arr, T2 len) {
            this->len = len;
            this->arr = new T1[len];
            for (int i = 0; i < len; i++) {
                *(this->arr + i) = *(arr + i);
            }
        }

    void get(){
            for (int i = 0; i < len; i++) {
                cout << *(this->arr + i) << " ";
            }
            cout << endl;
        }

    ~Arrays() {
            delete[] arr;
        }
};

int main() {

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Arrays<int, int> obj1(arr1, 10);
    obj1.get();

    short arr2[] = {8, 9, 10};
    Arrays<short, int> obj2(arr2, 3);
    obj2.get();

    return 0;
}