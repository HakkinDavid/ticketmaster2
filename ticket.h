/*  nombre: Ticket
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#ifndef TICKET_TICKETMASTER_H
#define TICKET_TICKETMASTER_H

#include <string>
#include <array>
#include "evento.h"
using namespace std;

class Ticket {
    private:
        static int objectCount;
        int ID;
        bool VIP;
        Evento evento;
    public:
        Ticket (bool, Evento&);
        Ticket (Evento&);
        ~Ticket ();

        void setID (int);
        void setVIP (bool);
        void setEvento(Evento&);

        int getID () const;
        bool getVIP () const;
        Evento getEvento() const;

        void use ();
        void display ();
};

#include "ticket.cpp"
#endif