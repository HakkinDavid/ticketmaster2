/*  nombre: Cliente
    contribuidores: David Emmanuel Santana Romero
    fecha: 9 de mayo de 2023
*/

#include "tienda.h"
#include <string>
#include <vector>
#include "ticket.h"
#include "cliente.h"
#include <iostream>
#include <iomanip>
using namespace std;

Tienda :: Tienda (vector<Evento> &eventos) {
    for (Evento &evento: eventos) {
        this -> eventos.push_back(evento);
    }
}

Tienda :: ~Tienda () {
    for (Evento &evento: eventos) {
        delete &evento;
    }
    eventos.clear();
}

void Tienda :: display (Cliente & C) {
    for (int i = 0; i < eventos.size(); i++) {
        eventos[i].display();
        float precio = eventos[i].getPrecio();
        cout << "\tPrecio: " << (C.getCash() >= precio ? "[$" + to_string(precio) + "]" : "<<$" + to_string(precio) + ">>") << endl;
    }
    int boleto;
    do {
        boleto = 0;
        C.displayCash();
        cout << "Especifica el ID de boleto a comprar [0 para regresar]: ";
        cin >> boleto;
        getchar();
        if (boleto < 1 || boleto > eventos.size()) {
            cout << "Regresando ..." << endl;
            break;
        }

        float precio = eventos[boleto-1].getPrecio();
        if (precio > C.getCash()) {
            cout << "A chambear, Buddy. Necesitas $" << fixed << setprecision (2) << (precio - C.getCash()) << " más." << endl;
            return;
        }
        C.setCash(C.getCash() - precio);

        Ticket ticket;
        ticket.setEvento(eventos[boleto-1]);
        C.addTicket(ticket);
        cout << "Transacción completada" << endl << endl;
    } while (boleto != 0);
}