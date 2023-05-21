/*  nombre: Evento
*   colaboradores: David Emmanuel Santana Romero y Braulio Chamerry
*   fecha: 21 de mayo de 2023
*/

// dios, qué horror de constructor
// lo que es ser necio y no querer usar arreglos para agrupar datos similares
// pero como yo no hago las cosas al último ni a la carrera, no opino.

#include <iostream>
#include "evento.h"
using namespace std;

Evento :: Evento(string nombre = "Torero", string lugar = "Estadio Azteca", int dia = 9, int mes = 6, int anio = 2023, string artista = "Chayanne",
               string direccion = "CDMX", int hora = 12, int minuto = 0, float precio = 20000, string catchphrase = "🎵") {
    this -> nombre = nombre;
    this -> lugar = lugar;
    this -> dia = dia;
    this -> mes = mes;
    this -> anio = anio;
    this -> artista = artista;
    this -> direccion = direccion;
    this -> hora = hora;
    this -> minuto = minuto;
    this -> precio = precio;
    this -> catchphrase = catchphrase;
}

Evento :: ~Evento() {
    this -> nombre = "";
    this -> lugar = "";
    this -> dia = 0;
    this -> mes = 0;
    this -> anio = 0;
    this -> artista = "";
    this -> direccion = "";
    this -> hora = 0;
    this -> minuto = 0;
    this -> precio = 0;
}

string Evento :: getNombre() const {
    return nombre;
}

void Evento :: setNombre(const string &nombre) {
    this -> nombre = nombre;
}

string Evento :: getLugar() const {
    return lugar;
}

void Evento :: setLugar(const string &lugar) {
    this -> lugar = lugar;
}

string Evento :: getFecha() const {
    return (dia < 10 ? "0" : "") + to_string(dia) + "/" + (mes < 10 ? "0" : "") + to_string(mes) + "/" + (anio < 10 ? "0" : "") + to_string(anio);
}

bool Evento :: setFecha(int dia, int mes, int anio) {
    if (anio < 2023) {
        cout << "El año tiene que ser después de 2023.";
        return false;
    }

    if (mes < 1 || mes > 12) {
        cout << "El mes tiene que ser entre 1 y 12";
        return false;
    }

    if (    dia < 1 // no month has day 0, nor does it have negative days
            ||  dia > 31 // no month has over 31 days
            // non leap year february cannot have over 28 days
            ||  (mes == 2 && !(anio%4 == 0 && (anio%100 != 0 || anio%400 == 0)) && dia > 28)
            // february never does have more than 29 days ... actually, there was a february 30, in sweden 1712
            ||  (mes == 2 && dia > 29)
            // some months are 30 days long
            ||  (!(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 30)
            ) {
        cout << "ERROR | OUT OF RANGE DAY" << endl;
        return false;
    }

    this -> dia = dia;
    this -> mes = mes;
    this -> anio = anio;

    return true;
}

string Evento :: getArtista() const {
    return artista;
}

void Evento :: setArtista(const string &artista) {
    Evento :: artista = artista;
}

string Evento :: getDireccion() const {
    return direccion;
}

void Evento :: setDireccion(const string &direccion) {
    this -> direccion = direccion;
}

bool Evento :: setHorario(int hora, int minuto) {
    if (hora < 0 || hora > 23) {
        cerr << "Las horas del horario tienen que estar entre 0 y 23 horas";
        return false;
    }
    if (minuto < 0 || minuto > 59) {
        cerr << "Los minutos del horario tienen que estar entre 0 y 59 minutos";
        return false;
    }
    return true;
}

string Evento :: getHorario() const {
    return (hora < 10 ? "0" : "") + to_string(hora) + ":" + (minuto < 10 ? "0" : "") + to_string(minuto);
}

float Evento :: getPrecio() const {
    return precio;
}

void Evento :: setPrecio(float precio) {
    this -> precio = precio;
}

void Evento :: setCatchphrase (string &x) {
    catchphrase = x;
}

string Evento :: getCatchphrase () const {
    return catchphrase;
}

void Evento :: display() const {
    cout << "\tNombre: " << nombre << endl;
    cout << "\tArtista: " << artista << endl;
    cout << "\tDirección: " << direccion << endl;
    cout << "\tFecha: " << getFecha() << "\tHorario: " << getHorario() << endl;
    cout << "==============================" << endl;
}
