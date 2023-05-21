/*  nombre: Cliente
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#include "cliente.h"
#include <string>
#include <vector>
#include "ticket.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Cliente :: objectCount = 0;

Cliente :: Cliente (string pswd) {
    cash = 0;
    password = pswd;
    setID(++objectCount);
}

Cliente :: ~Cliente () {
    inventario.clear();
    // cout << "Cliente con ID " << ID << " eliminado." << endl;

}

void Cliente :: setID (int x) {
    ID = x;
}

void Cliente :: setCash (float x) {
    cash = x;
}

void Cliente :: setPassword (string x) {
    if (x.size() < 8 || x.size() > 30) {
        cout << "ERROR | PASSWORD MUST BE 8 TO 30 CHARACTERS LONG";
        return;
    }
    password = x;
}

int Cliente :: getID () const {
    return ID;
}

float Cliente :: getCash () const {
    return cash;
}

void Cliente :: displayCash () const {
    cout << "[ $" << fixed << setprecision(2) << getCash() << " ]" << endl;
}

string Cliente :: getPassword () const {
    return password;
}

void Cliente :: useTicket (int x) {
    if (x < 1 || x > inventario.size()) {
        cout << "ERROR | OUT OF INVENTORY RANGE (1 TO " << inventario.size() << ")" << endl;
        return;
    }
    inventario[x-1].use();
    deleteTicket(x);
}

void Cliente::displayInventario () {
    if (inventario.size() < 1) {
        cout << "No tienes boletos. [Enter para regresar]" << endl;
        getchar();
        return;
    }
    Holder::display();
    int boleto;
    cout << "Especifica el ID de boleto a usar [0 para ninguno]: ";
    cin >> boleto;
    getchar();
    if (boleto < 1 || boleto > inventario.size()) {
        return;
    }
    useTicket(boleto);
}