/*  nombre: Cliente
    contribuidores: David Emmanuel Santana Romero
    fecha: 9 de mayo de 2023
*/

#include "tienda.h"
#include <string>
#include <vector>
#include "ticket.h"
#include "cliente.h"
#include "evento.h"
#include <iostream>
#include <iomanip>
using namespace std;

Tienda :: Tienda (vector<Evento> &eventos) {
    this -> eventos = eventos;
}

Tienda :: ~Tienda () {
    for (Evento &evento: eventos) {
        delete &evento;
    }
    eventos.clear();
}

void Tienda :: display (Cliente & C) {
    for (int i = 0; i < eventos.size(); i++) {
        float precio = eventos[i].getPrecio();
        eventos[i].display();
        cout << "Precio: " << (C.getCash() >= precio ? "[$" + to_string(precio) + "]" : "<<$" + to_string(precio) + ">>") << endl;
        cout << "ID: " << i + 1 << endl;
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
        bool vip;
        cout << "Quisieras que fuera VIP? (+200) (Ingresa 1 para VIP)" << endl;
        cin >> vip;
        getchar();
        if (vip) {
            precio += 200;
        }

        if (precio > C.getCash()) {
            cout << "A chambear, Buddy. Necesitas $" << fixed << setprecision (2) << (precio - C.getCash()) << " más." << endl;
            return;
        }
        C.setCash(C.getCash() - precio);

        Ticket ticket(vip, eventos[boleto-1]);
        C.addTicket(ticket);
        cout << "Transacción completada" << endl << endl;
    } while (boleto != 0);
}