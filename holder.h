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
        int getInventarioSize () const;
        void addTicket (Ticket &);
        virtual void addTicket (bool, Evento &) = 0;
        void deleteTicket (int);

        void display ();
};

#include "holder.cpp"
#endif