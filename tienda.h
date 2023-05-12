/*  nombre: Tienda
    contribuidores: David Emmanuel Santana Romero
    fecha: 9 de mayo de 2023
*/

#ifndef TIENDA_TICKETMASTER_H
#define TIENDA_TICKETMASTER_H

#include <string>
#include <vector>
#include "ticket.h"
#include "cliente.h"
using namespace std;

class Tienda {
    private:
        vector<Evento> eventos;
    public:
        Tienda (vector<Evento> &eventos);
        ~Tienda ();
        
        void display (Cliente &);
};

#include "tienda.cpp"
#endif