/** nombre: Administrador
    colaboradores: Renata Flores y David Emmanuel Santana Romero
    fecha: 30 de abril de 2023 **/

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include "cliente.h"

using namespace std;

class Administrador
{
    public:
        Administrador (vector<Evento> &, vector<Cliente> &, string);
        ~Administrador ();

        void setPassword (string);
        string getPassword ();

        void crearEvento ();
        void infoClientes ();
        void estadisticasVentas (Tienda &);
    private:
        string password;
        vector<Evento>* eventos;
        vector<Cliente>* clientes;
};

#include "Administrador.cpp"

#endif // ADMINISTRADOR_H
