#include <iostream>
#include <string>

using namespace std;

void print_str(string word)
{
    cout << word << endl;
}

void print_int(int word)
{
    cout << word << endl;
}


void mult (int a, int b) {
    int res = a * b;
    print_int(res);
}

int main() {

    print_str("hello");
    mult (1, 2);

    return 0;
}