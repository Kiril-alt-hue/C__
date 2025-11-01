#include <iostream>
#include <string>

using namespace std;

class Person;

class Dog {
    private:
        int health = 100;
    public:
        friend class Person;
};

class Person {
    public:
        void Damage(Dog& dog) {
            dog.health -= 20;
            cout << "Health of the dog: " << dog.health << endl;
        }

        void Heal(Dog& dog) {
            dog.health += 10;
            cout << "Health of the dog: " << dog.health << endl;
        }


        void Kill(Dog& dog) {
            dog.health = 0;
            cout << "Health of the dog: " << dog.health << endl;
        }
};


int main() {
    Dog skubby;
    Person alex;
    alex.Damage(skubby);
    alex.Damage(skubby);
    alex.Heal(skubby);
    alex.Damage(skubby);
    alex.Kill(skubby);

    return 0;
}