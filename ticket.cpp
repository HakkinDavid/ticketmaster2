/*  nombre: Ticket
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#include "ticket.h"
#include <iostream>
using namespace std;

// contabilizar objetos Ticket existentes
int Ticket :: objectCount = 0;

// crear objeto Ticket con su modalidad y su referencia al evento
Ticket :: Ticket (bool VIP, Evento &evento) : evento(&evento), VIP(VIP) {
    setID(++objectCount); // establecer el ID
}

// crear un Ticket simple, referenciando al evento
Ticket::Ticket (Evento &evento): evento(&evento), VIP(false) {
    setID(++objectCount); // establecer el ID
}

// eliminar el Ticket
Ticket :: ~Ticket () {
    VIP = false;
    ID = 0;
}

// establecer el ID
void Ticket :: setID (int x) {
    ID = x;
}

// establecer la modalidad VIP
void Ticket :: setVIP (bool x) {
    VIP = x;
}

// establecer la referencia al Evento
void Ticket :: setEvento(Evento &x) {
    evento = &x;
}

// obtener el ID
int Ticket :: getID () const {
    return ID;
}

// obtener la modalidad VIP
bool Ticket :: getVIP () const {
    return VIP;
}

// obtener el Evento referenciado
Evento Ticket :: getEvento () const {
    return *evento;
}

// utilizar el Ticket y desplegar la frase icónica
void Ticket :: use () {
    cout << evento->getCatchphrase () << endl;
    cout << "BOLETO CON ID " << ID << " UTILIZADO." << endl;
}

// desplegar los datos del boleto
void Ticket :: display () {
    cout << "[BOLETO] ID: " << getID () << ", VIP: " << (getVIP () ? "Sí" : "No") << endl;
    getEvento().display();
    cout << endl;
}