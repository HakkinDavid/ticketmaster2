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

// contabilizar cuántos objetos Cliente se han creado
int Cliente :: objectCount = 0;

// crear el Cliente con su contraseña y establecer el ID
Cliente :: Cliente (string pswd) {
    cash = 0;
    password = pswd;
    setID(++objectCount);
}

// eliminar el objeto
Cliente :: ~Cliente () {
    inventario.clear();
}

// establecer el ID
void Cliente :: setID (int x) {
    ID = x;
}

// establecer los fondos de la cuenta
void Cliente :: setCash (float x) {
    cash = x;
}

// establecer una nueva contraseña
void Cliente :: setPassword (string x) {
    if (x.size() < 8 || x.size() > 30) {
        cout << "ERROR | PASSWORD MUST BE 8 TO 30 CHARACTERS LONG";
        return;
    }
    password = x;
}

// obtener el ID
int Cliente :: getID () const {
    return ID;
}

// obtener los fondos actuales
float Cliente :: getCash () const {
    return cash;
}

// desplegar los fondos de la cuenta
void Cliente :: displayCash () const {
    cout << "[ $" << fixed << setprecision(2) << getCash() << " ]" << endl;
}

// obtener la contraseña
string Cliente :: getPassword () const {
    return password;
}

void Cliente :: addTicket (bool VIP, Evento & evento) {
    inventario.emplace_back(VIP, evento);
    inventario.back().setID(inventario.size());
}

// utilizar un ticket
void Cliente :: useTicket (int x) {
    if (x < 1 || x > inventario.size()) {
        cout << "ERROR | OUT OF INVENTORY RANGE (1 TO " << inventario.size() << ")" << endl;
        return;
    }
    // utilizar el ticket especificado
    inventario[x-1].use();
    // eliminar el ticket del inventario
    deleteTicket(x);
}

// desplegar los elementos del inventario de la cuenta
void Cliente::display () {
    if (inventario.size() < 1) {
        cout << "No tienes boletos. [Enter para regresar]" << endl;
        getchar();
        return;
    }
    Holder::display();
    // permitir que el usuario utilice un ticket
    int boleto;
    cout << "Especifica el ID de boleto a usar [0 para ninguno]: ";
    cin >> boleto;
    getchar();
    if (boleto < 1 || boleto > inventario.size()) {
        return;
    }
    // usar el ticket
    useTicket(boleto);
}

// desplegar la información esencial del cliente en pantalla
ostream & operator << (ostream & o, const Cliente & c) {
    o << "[ID: " << c.getID() << " | ";
    o << "Cantidad de boletos: " << c.getInventarioSize() << " | ";
    o << "Saldo actual: $" << c.getCash() << "]" << endl;
    return o;
}