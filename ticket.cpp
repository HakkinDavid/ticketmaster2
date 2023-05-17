/*  nombre: Ticket
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#include "ticket.h"
#include <iostream>
using namespace std;

int Ticket :: objectCount = 0;

Ticket :: Ticket (bool VIP) {
    this -> VIP = VIP;

    setID(++objectCount);
}

Ticket::Ticket () {
    
}

Ticket :: ~Ticket () {
    VIP = false;
    evento = nullptr; // Se usa nullptr en vez de NULL porque según CPP, nullptr es más seguro.
    ID = 0;
}

void Ticket :: setID (int x) {
    ID = x;
}
void Ticket :: setVIP (bool x) {
    VIP = x;
}
void Ticket :: setEvento(Evento x) {
    evento = &x;
}

int Ticket :: getID () const {
    return ID;
}
bool Ticket :: getVIP () const {
    return VIP;
}
Evento Ticket :: getEvento () const {
    return *evento;
}

void Ticket :: use () {
    cout << "BOLETO CON ID " << ID << " UTILIZADO." << endl;
}

void Ticket :: display () {
    cout << "[BOLETO] ID: " << getID () << ", VIP: " << (getVIP () ? "Sí" : "No") << endl;
    getEvento().display();
    cout << endl;
}