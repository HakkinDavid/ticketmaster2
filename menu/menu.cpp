/*  nombre: Menú
    autor: David Emmanuel Santana Romero
    fecha: 9 de marzo de 2023
*/

#include "menu.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
using namespace std;

// initialize menu object with a vector consisting of a char to press, option name and function to execute; optionally add a menu header
Menu :: Menu (vector<pair<char, pair<string, function<void()>>>> options, string header = "") {
    this -> options = options;
    this -> header = header;
}

// display the menu
// callPress (should press function be called?)
// loop (should loop? requires callPress to be true)
void Menu :: display (bool callPress = false, bool loop = false) {
    if (header.size() > 0) cout << header << endl;
    for (const auto &i : options) {
        cout << "[" << i.first << "] " << i.second.first << endl;
    }
    cout << "[-] Salir" << endl;
    if (callPress) press (loop);
}

// prompt user for selecting an option
// loop (whether or not to display menu recursively once each action is finished)
void Menu :: press (bool loop = false) {
    char key = 0;
    bool found = false;
    cout << ">> ";
    key = _getch();
    system ("cls");
    if (key == 45) {
        return;
    }
    for (const auto &i : options) {
        if (i.first == key) {
            found = true;
            i.second.second();
            break;
        }
    }
    if (!found) {
        display();
        press (true);
    }
    else if (loop) {
        display();
        press(true);
    }
}