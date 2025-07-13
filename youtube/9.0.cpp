#include <iostream>

#include <string> //дуже важливо!!!

using namespace std;
int main() {
    // char word[2] = {'H', 'i'}; // як задавався рядок у мові С
    //cin.getline(word, 4) // отримуємо дані від користувача. 4 - це невключно
    // for (int i = 0; i < 2; i++) {
    //     cout << word[i];
    // }

    string words = "Hello";

    cin >> words;
    words[0] = 'h';
    cout << words ;

    return 0;
}