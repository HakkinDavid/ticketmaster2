/*  nombre: Cliente
    contribuidores: David Emmanuel Santana Romero
    fecha: 23 de abril de 2023
*/

#ifndef CLIENTE_TICKETMASTER_H
#define CLIENTE_TICKETMASTER_H

#include <string>
#include <vector>
#include "ticket.h"
#include "holder.h"
using namespace std;

class Cliente : public Holder {
    private:
        static int objectCount;
        int ID;
        float cash;
        string password;
    public:
        Cliente (string);
        ~Cliente ();

        void setID (int);
        void setCash (float);
        void setPassword (string);

        int getID () const;
        float getCash () const;
        void displayCash () const;
        string getPassword () const;
        void displayInventario ();

    protected:
        void useTicket (int);
};

#include "cliente.cpp"
#endif