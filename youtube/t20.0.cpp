#include <iostream>
#include <string>

using namespace std;

class Building {
private:
    int year;
    string type;

public:
    Building(int y, string t) {    //конструктор; його назва повинна бути така сама (!!!) як і назва класу
        // year = y;
        // type = t;
        set_data(y, t);
    }
    Building(string t) {
        type = t;
    }

    Building() {} //конструктор для house
    void set_data(int year, string type) {
        if (year < 0) this -> year = 1000;
        else this -> year = year;

        this -> type = type;
    }

    void get_info() {
        cout << "Type: " << type << ". Year: " << year << endl;
    }

    ~Building() {//деструктор; якщо конструктор викорситовується під час створення об'єкта, то деструктор - під час знищення
        cout << "Deleting Building" << endl;
    }

};

int main() {
    Building school(2001, "School");
    // school.type = "School";
    // school.year = 1900;
    // school.get_info();

    //school.set_data(2001, "School");
    school.get_info();

    // Building house(1488, "House");
    // school.type = "House";
    // school.year = 1488;
    // school.get_info();
    Building house("House");
    house.set_data(1488, "House");
    house.get_info();

    return 0;
}