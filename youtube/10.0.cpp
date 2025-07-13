#include <iostream>
#include <string>

using namespace std;

void print(string word) {//void - спеціальний тип даних який вказує що функіція нічого не повертає
    cout<<word<<endl;
}

int summa(int a, int b) {
    int res = a + b;
    cout<<res<<endl;

    return res;
}

int main() {

    print("Hi");

    string words = "";
    cin >> words;
    print(words);

    int res1 = summa(3, 4);
    int res2 = summa(2, 4);

    if (res1 > res2) {
        cout<<res1<<endl;
    }
    else
         cout<<res2<<endl;

    return 0;
}