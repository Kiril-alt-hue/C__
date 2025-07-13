#include <iostream>
#include <string>

using namespace std;

struct  Point {
    int x, y;
};

struct Tree {
    string name;
    int age;
    bool is_alive;
    float height;
    Point place;

    void get_info() {
        cout << name << " " << age << " " << is_alive << " " << height << endl;
    }
};

int main() {

    //Структури
    Tree dub;
    dub.name = "Dub";
    dub.age = 18;
    dub.is_alive = true;
    dub.height = 1.5;
    dub.place.x = 0;
    dub.place.y = -1;
    dub.get_info();

    //cout << dub.name <<". Height: " << dub.height << endl;

    Tree yalinka;
    yalinka.name = "Yalinka";
    yalinka.age = 4;
    yalinka.is_alive = true;
    yalinka.height = 2;
    yalinka.get_info();

    //cout << yalinka.name <<". Height: " << yalinka.height << endl;

    return 0;
}