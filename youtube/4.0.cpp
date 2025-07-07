#include <iostream>

int main() {
    std::cout<<"Enter a number: " <<std::endl;
    int userInput = 0;
    std::cin>>userInput;

    bool isHappy = true;

    if (userInput >= 5 && isHappy == true) { //&& - логічне "і"
        // || - логічне "або"
        std::cout << "Yes" << std::endl;
    }

        if (userInput > 100) {
            std::cout << "Number > 100" << std::endl;
        }
    else if (userInput < 0) {
        std::cout << "Number < 0" << std::endl;
    }
    else {
        std::cout<<"Else" << std::endl;
    }
    return 0;
}