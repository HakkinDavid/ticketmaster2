#include <iostream>
#include "evento.h"

Evento::Evento(std::string nombre, std::string lugar, int dia, int mes, int anio, std::string artista,
               std::string direccion, int hora, int minuto, float precio) {
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
}

Evento::~Evento() {
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

std::string Evento::getNombre() const {
    return nombre;
}

void Evento::setNombre(const std::string &nombre) {
    Evento::nombre = nombre;
}

std::string Evento::getLugar() const {
    return lugar;
}

void Evento::setLugar(const std::string &lugar) {
    Evento::lugar = lugar;
}

std::string Evento::getFecha() const {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

void Evento::setFecha(int dia, int mes, int anio) {
    if (anio < 2023) {
        std::cerr << "El anio tiene que ser despues de 2023.";
        return;
    }

    if (mes < 1 || mes > 12) {
        std::cerr << "El mes tiene que ser entre 1 y 12";
        return;
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
        return;
    }

    this -> dia = dia;
    this -> mes = mes;
    this -> anio = anio;
}

std::string Evento::getArtista() const {
    return artista;
}

void Evento::setArtista(const std::string &artista) {
    Evento::artista = artista;
}

std::string Evento::getDireccion() const {
    return direccion;
}

void Evento::setDireccion(const std::string &direccion) {
    Evento::direccion = direccion;
}

void Evento::setHorario(int hora, int minuto) {
    if (hora < 0 || hora > 24) {
        std::cerr << "Las horas del horario tienen que estar entre 0 y 24 horas";
        return;
    }
    if (minuto < 0 || minuto > 60) {
        std::cerr << "Los minutos del horario tienen que estar entre 0 y 60 minutos";
        return;
    }
}

std::string Evento::getHorario() const {
    return std::to_string(hora) + ":" + std::to_string(minuto);
}

float Evento::getPrecio() const {
    return precio;
}

void Evento::setPrecio(float precio) {
    Evento::precio = precio;
}

void Evento::display() const {
    std::cout << "--- Datos del Evento ---" << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar: " << lugar << std::endl;
    std::cout << "Fecha: " << getFecha() << std::endl;
    std::cout << "Artista: " << artista << std::endl;
    std::cout << "Direccion: " << direccion << std::endl;
    std::cout << "Horario: " << getHorario() << std::endl;
}
