/** nombre: Administrador
    colaboradores: Renata Flores y David Emmanuel Santana Romero
    fecha: 30 de abril de 2023 **/

#include "Administrador.h"
#include <string>
#include <iostream>
#include "cliente.h"

using namespace std;

Administrador :: Administrador (vector<Evento> &e, vector<Cliente> &c, string password = "12345678") {
    eventos = &e;
    clientes = &c;
    this -> password = password;
}

Administrador :: ~Administrador () {
    eventos = nullptr;
    clientes = nullptr;
    password = "";
}

void Administrador :: setPassword (string password){
    if (password.size() < 8 || password.size() > 30) {
        cout << "La contraseña debe tener de 8 a 30 caracteres" << endl;
        return;
    } else
    {
        this -> password = password;
    }
}

string Administrador :: getPassword () {
    return password;
}

void Administrador :: crearEvento () {
    eventos->emplace_back();
    Evento *eventito = &eventos->back();
    string data;
    array <int, 3> fecha;
    array <int, 2> horario;
    float precio;

    cout << "Nombre del evento: ";
    getline(cin, data);
    (*eventito).setNombre(data);

    cout << "Lugar: ";
    getline(cin, data);
    (*eventito).setLugar(data);

    do {
        cout << "Año: "; cin >> fecha[0]; getchar();
        cout << "Mes: "; cin >> fecha[1]; getchar();
        cout << "Día: "; cin >> fecha[2]; getchar();
    } while (!(*eventito).setFecha(fecha[2], fecha[1], fecha[0]));

    do {
        cout << "Hora: "; cin >> horario[0]; getchar();
        cout << "Minuto: "; cin >> horario[1]; getchar();
    } while (!(*eventito).setHorario(horario[0], horario[1]));

    cout << "Artista: ";
    getline(cin, data);
    (*eventito).setArtista(data);

    cout << "Dirección: ";
    getline(cin, data);
    (*eventito).setDireccion(data);

    cout << "Precio por boleto: $";
    cin >> precio;
    getchar();

    (*eventito).setPrecio(precio);
    //eventos->emplace_back(nombre,lugar,dia,mes,anio,artista,direccion,hora,minuto,precio);
}

void Administrador :: infoClientes () {
    for(Cliente &i : (*clientes)){
        cout << "[ID: " << i.getID() << " | ";
        //hice una funcion getInventario para saber cuantos boletos compro cada usuario
        //pero no se si inventario es el que guarda esos datos
        cout << "Cantidad de boletos: " << i.getInventarioSize() << " | ";
        cout << "Saldo actual: $" << i.getCash() << "]" << endl;
    }
} 

void Administrador :: estadisticasVentas (Tienda &tienda) {
    float costoTotal;
    cout << "Ingresos totales: $" << tienda.getFondos() << endl;
    cout << "Costo administrativo: $";
    cin >> costoTotal;
    getchar();
    cout << "Ganancias: $" << tienda.getFondos() - costoTotal << endl;
    cout << "Porcentaje de Ganancias: " << ((tienda.getFondos() - costoTotal) / tienda.getFondos()) * 100 << "%" << endl;
}