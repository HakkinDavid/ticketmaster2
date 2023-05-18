/*  nombre: Holder (abstracta)
    contribuidores: David Emmanuel Santana Romero
    fecha: 9 de mayo de 2023
*/

#ifndef HOLDER_TICKETMASTER_H
#define HOLDER_TICKETMASTER_H

#include <string>
#include <vector>
#include "ticket.h"
using namespace std;

class Holder {
    protected:
        vector <Ticket> inventario;
    public:
        ~Holder ();

        void setInventario (vector <Ticket> &);
        void addTicket (Ticket &);
        void deleteTicket (int);

        void display ();
};

#include "holder.cpp"
#endif