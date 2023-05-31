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

// crear el objeto tipo Tienda con la referencia al vector de objetos Evento
Tienda :: Tienda (vector<Evento> &e) {
    fondos = 0;
    eventos = &e;
}

// eliminar la tienda y borrar el vector, así como limpiar su puntero
Tienda :: ~Tienda () {
    eventos->clear();
    eventos = nullptr;
}

// desplegar la tienda y permitirle al cliente referenciado adquirir un boleto
void Tienda :: display (Cliente & C) {
    // iterar y desplegar todos los eventos
    for (int i = 0; i < eventos->size(); i++) {
        float precio = (*eventos)[i].getPrecio();
        cout << "ID: " << i + 1 << endl;
        cout << "Precio: $" << fixed << setprecision (2) << precio << endl;
        (*eventos)[i].display();
    }
    // comprar un boleto
    int boleto;
    do {
        boleto = 0;

        C.displayCash();

        cout << "Especifica el ID de boleto a comprar [Otra tecla para regresar]: ";
        cin >> boleto;
        getchar();

        if (boleto < 1 || boleto > eventos->size()) {
            system("cls");
            cout << "Regresando ..." << endl;
            break;
        }

        float precio = (*eventos)[boleto-1].getPrecio();
        bool vip;
        cout << "¿Desea comprar la modalidad VIP? El costo total sería de $" << fixed << setprecision (2) << (precio+200) << " [0 = NO / 1 = SÍ]" << endl;
        cin >> vip;
        getchar();

        if (vip) {
            precio += 200;
        }

        if (precio > C.getCash()) {
            cout << "A chambear, Buddy. Necesitas $" << fixed << setprecision (2) << (precio - C.getCash()) << " más." << endl;
            return;
        }
        // restar el efectivo de la cuenta
        C.setCash(C.getCash() - precio);

        C.addTicket(vip, (*eventos)[boleto-1]); // añadir el ticket al inventario del cliente referenciado
        fondos += precio; // añadir los fondos correspondientes a la Tienda
        cout << "Transacción completada" << endl << endl;
    } while (boleto != 0);
}

// obtener los fondos actuales de la Tienda
float Tienda :: getFondos () const {
    return fondos;
}