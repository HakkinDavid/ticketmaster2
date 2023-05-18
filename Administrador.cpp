/** nombre: Administrador
    colaboradores: Renata Flores
    fecha: 30 de abril de 2023 **/

#include "Administrador.h"
#include <string>
#include <iostream>
#include <math.h>
#include <conio.h>

Administrador::Administrador()
{
    nombre = "";
    apellido = "";
    telefono = 0;
    empresa = "";
    correo = "";
    password = "";
    estatusAdmi = false;
}

Administrador::~Administrador(){}
//funciones set
void Administrador::setNombre(std::string nombre){
    if(nombre.size() > 30){
        std::cout << "El nombre no puede ser de longitud mayor a 30 caracteres" << std::endl;
        return;
    }else
    {
        this -> nombre = nombre;
    }
}
void Administrador::setApellido(std::string apellido){
    if(apellido.size() > 25){
        std::cout << "El appellido no puede ser de longitud mayor a 25 caracteres" << std::endl;
        return;
    }else
    {
        this -> apellido = apellido;
    }
}
void Administrador::setTelefono(long long telefono){
    int size = int (log10(telefono) +1);
    if(size == 10)
        this -> telefono = telefono;
    else{
        std::cout << "El numero de telefono no es correcto" << std::endl;
        return;
    }
}
void Administrador::setEmpresa(std::string empresa){
    if(empresa.size() > 25){
        std::cout << "No puedes utilizar mas de 25 caracteres" << std::endl;
        return;
    }else
    {
        this -> empresa = empresa;
    }
}
void Administrador::setCorreo(std::string correo){
    if(correo.size() > 30){
        std::cout << "No puede utilizar mas de 30 caracteres" << std::endl;
        return;
    }else
    {
        this -> correo = correo;
    }
}
void Administrador::setPassword(std::string password){
    if (password.size() < 8 || password.size() > 30) {
        std::cout << "La contrasena es de 8 carcteres a 30 caracteres";
        return;
    }else
    {
        this -> password = password;
    }
}
void Administrador::setEstatusAdmi(bool estatusAdmi){
    this -> estatusAdmi = estatusAdmi;
}
//funciones get
std::string Administrador::getNombre()const{
    return nombre;
}
std::string Administrador::getApellido()const{
    return apellido;
}
long long Administrador::getTelefono()const{
    return telefono;
}
std::string Administrador::getEmpresa()const{
    return empresa;
}
std::string Administrador::getCorreo()const{
    return correo;
}
std::string Administrador::getPassword()const{
    return password;
}
//determinar si existe un administrador o no
bool Administrador::getEstatusAdmi()const{
    return estatusAdmi;
}
//fin funciones get

void Administrador::crearAdministrador(){
    std::cin.ignore();
    std::cout << "Nombre(s): "; getline(std::cin, nombre);
    setNombre(nombre);
    std::cout << "Apellido(s): "; getline(std::cin, apellido);
    setApellido(apellido);
    std::cout << "Empresa: "; getline(std::cin, empresa);
    setEmpresa(empresa);
    std::cout << "Telefono: "; std::cin >> telefono;
    setTelefono(telefono);
    std::cout << "Correo Electronico: ";
    std::cin >> correo;
    setCorreo(correo);
    std::cout << "Password: ";
    setPassword(password);
    setEstatusAdmi(true);
}

void Administrador::iniciarSesion(){
    if(getEstatusAdmi() == 1){
        std::cout << "Correo Electronico: ";
        std::cin >> correo;
        if(getCorreo != correo){
            cout << "El correo es incorrecto";
            return;
        }
        std::cout << "Password: ";
        do{
            std::cin >> password;
        }while(password == getPassword())
    }
    else{
        std::cout << "Administrador Inexistente" << std::endl;
        return;
    }
}

