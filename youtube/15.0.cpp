#include <iostream>
#include <string>

using namespace std;

enum Options {
    open = 4,
    close = 1,
    wait,
    del = 10
};

struct File {
    float weight;
    string name;
    Options options;
};
int main() {
    //Enum (перерахування)
    File my_file;
    my_file.weight = 12.3;
    my_file.name = "test01.txt";
    my_file.options = Options::close;

    if (my_file.options == Options::close)
        cout <<"File is closed";

    return 0;
}