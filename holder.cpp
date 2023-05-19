/*  nombre: Holder (abstracta)
    contribuidores: David Emmanuel Santana Romero
    fecha: 9 de mayo de 2023
*/

#include "holder.h"
#include <string>
#include <vector>
#include "ticket.h"
#include <iostream>
using namespace std;

Holder :: ~Holder () {
    inventario.clear();
}

void Holder :: setInventario (vector <Ticket> & x) {
    inventario = x;
}

int Holder :: getInventario()const{
    return inventario.size();
}

void Holder :: addTicket (Ticket & x) {
    inventario.push_back(x);
    inventario.back().setID(inventario.size());
}

void Holder :: deleteTicket (int x) {
    if (x < 1 || x > inventario.size()) {
        cout << "ERROR | OUT OF INVENTORY RANGE (1 TO " << inventario.size() << ")" << endl;
        return;
    }
    inventario.erase(inventario.begin() + (x-1));
    for (int i = (x-1); i < inventario.size(); i++) {
        inventario[i].setID(i+1);
    }
}

void Holder :: display () {
    for (int i = 0; i < inventario.size(); i++) {
        inventario[i].display();
    }
}