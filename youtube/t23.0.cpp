#include <iostream>
#include <string>

using namespace std;

class Computer {
    protected:
        int diagonal;
        string os;
    public:
        Computer(int diagonal, string os) {
            this->diagonal = diagonal;
            this->os = os;
        }

        void get_data() {
            cout << "OS: " << os << " Diagonal: " << diagonal << endl;
        }
};

class Laptop: public Computer {
    private:
        float weight;
    public:
        Laptop(int diagonal, string os, float weight): Computer(diagonal, os) {
            this->weight = weight;
        }

        void get_data() {
            Computer::get_data();
            cout << "Weight: " << weight << endl;
        }
};

int main() {
    Laptop mac(16, "Mac", 1.5f);
    mac.get_data();


    return 0;
}