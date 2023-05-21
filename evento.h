/*  nombre: Evento
*   colaboradores: David Emmanuel Santana Romero y Braulio Chamerry
*   fecha: 21 de mayo de 2023
*/

#ifndef TICKETMASTER2_EVENTO_H
#define TICKETMASTER2_EVENTO_H

#include <string>
using namespace std;

class Evento {
private:
    string nombre;
    string lugar;
    int dia, mes, anio;
    string artista;
    string direccion;
    int hora, minuto;
    float precio;
    string catchphrase;
public:

    Evento(string, string, int, int, int, string, string, int, int, float, string);

    ~Evento();

    string getNombre() const;

    void setNombre(const string &);

    string getLugar() const;

    void setLugar(const string &);

    bool setFecha(int, int, int);

    string getFecha() const;

    string getArtista() const;

    void setArtista(const string &);

    string getDireccion() const;

    void setDireccion(const string &);

    bool setHorario(int, int);

    string getHorario() const;

    float getPrecio() const;

    void setPrecio(float);

    void setCatchphrase (string &);

    string getCatchphrase () const;

    void display() const;

};
#include "evento.cpp"

#endif //TICKETMASTER2_EVENTO_H
