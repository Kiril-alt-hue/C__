#include <iostream>
#include <string>

using namespace std;

class Building {
    private:
        int year;
        string type;

    public:
        void set_data(int y, string t) {
            if (y < 0) year = 1000;
            else year = y;
            type = t;
        }

        void get_info() {
            cout << "Type: " << type << ". Year: " << year << endl;
        }
};

int main() {
    Building school;
    // school.type = "School";
    // school.year = 1900;
    // school.get_info();
    school.set_data(2001, "School");
    school.get_info();

    Building house;
    // school.type = "House";
    // school.year = 1488;
    // school.get_info();
    house.set_data(1488, "House");
    house.get_info();

    return 0;
}