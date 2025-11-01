#include <iostream>
#include <string>

using namespace std;

class Car;

class Person {
    private:
        int age;
        string name;
    public:
        Person(string name) {
            this->name = name;
        }
        friend void info_car(Car& car, Person& person);

};


class Car {
    private:
        string name;
    public:
        Car(string name) {
            this->name = name;
        }
        friend void info_car(Car& car, Person& person);
};



void info_car(Car& car, Person& person) {
    cout << "Person name: " << person.name <<". Car name: " << car.name <<endl;
}




int main() {
    Car bmw("BMW");
    Person john("John");
    info_car(bmw, john);

    return 0;
}