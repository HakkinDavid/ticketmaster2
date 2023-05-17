/*  nombre: Ticketmaster 2 (Main file)
*   autor: David Emmanuel Santana Romero
*   fecha: 31 de mayo de 2023
*/

#include "menu/menu.h" // library by David Emmanuel Santana Romero which allows for easy recursive menu implementation
#include "evento.h"
#include "tienda.h"
#include "cliente.h"
#include <string> // text strings library
#include <iostream> // input output stream library
#include <fstream> // file stream library
using namespace std;

vector<Evento> eventos{
        Evento("World's Hottest Tour", "Tijuana", 15, 2, 2023, "Bad Bunny", "Plaza Monumental, Playas de Tijuana, B.C", 20, 0, 4000),
        Evento("PP", "Tijuana", 25, 10, 2023, "Peso Pluma", "Plaza Monumental, Playas de Tijuana, B.C", 21, 0, 2000),
        Evento("Saturo World Tour", "Tijuana", 10, 6, 2023, "Rauw Alejandro", "Plaza , Playas de Tijuana, B.C", 19, 0, 3000)
};

vector<Cliente> clientes;
Tienda * tienda = new Tienda(eventos);
int sessionID = -1;
string logo = "   __  _      __        __                       __                ___\n  / /_(_)____/ /_____  / /_____ ___  ____ ______/ /____  _____    /_  |\n / __/ / ___/ //_/ _ \\/ __/ __ `__ \\/ __ `/ ___/ __/ _ \\/ ___/   __/ /\n/ /_/ / /__/ ,< /  __/ /_/ / / / / / /_/ (__  ) /_/  __/ /      / __/ \n\\__/_/\\___/_/|_|\\___/\\__/_/ /_/ /_/\\__,_/____/\\__/\\___/_/      /____/ \n                                                                      \n";

void crearUsuario ();
void iniciarSesion ();
void trabajar ();
void sessionMenu ();
void save ();
void load ();

Menu adminMenu ({
    // {}
}, "MENÚ DEL ADMINISTRADOR");

Menu clientMenu ({
    {'1', {"Iniciar sesión", iniciarSesion}},
    {'2', {"Crear usuario", crearUsuario}}
}, "MENÚ DEL CLIENTE");

Menu mainMenu ({
    {'1', {"Cliente", [] () { clientMenu.display(true, true); }}},
    {'2', {"Administrador", [] () { adminMenu.display(true, true); }}}
}, logo + "MENÚ PRINCIPAL");

Menu session ({
        {'1', {"Inventario", [] () { clientes[sessionID].displayInventario (); } }},
        {'2', {"Comprar", [] () { tienda -> display (clientes[sessionID]); } }},
        {'3', {"Chambear", trabajar}}
});

int main () {
    load ();
    cout << "CLIENTES: " << clientes.size() << endl;
    mainMenu.display(true, true);
    cout << logo << endl;
    cout << "Guardando datos y limpiando la memoria ..." << endl;
    delete tienda;
    tienda = NULL;
    save ();
    return 0;
}

void crearUsuario () {
    cout << "Proporciona una contraseña de 8 a 30 caracteres" << endl;
    string pswd;
    do {
        cout << "Contraseña: ";
        cin >> pswd;
        getchar();
    } while (pswd.size() < 8 || pswd.size() > 30);
    float bono = 5000 + rand () % 1000;
    clientes.emplace_back(pswd);
    clientes.back().setCash(bono);
    cout << "El ID del nuevo usuario es: " << clientes.back().getID() << endl;
    cout << "Bono por crear cuenta: +$" << bono << endl;
}

void trabajar () {
    float bono = 500 + rand () % 500;
    cout << "Has obtenido +$" << bono << endl;
    clientes[sessionID].setCash(clientes[sessionID].getCash() + bono);
}

void iniciarSesion () {
    int id;
    string pswd;
    cout << "ID: ";
    cin >> id;
    getchar();
    if (id < 1 || id > clientes.size()) {
        cout << "USUARIO INEXISTENTE" << endl;
        return;
    }
    for (int attempts = 0; clientes[id-1].getPassword() != pswd; attempts++) {
        if (attempts >= 3) {
            cout << "INTÉNTALO MÁS TARDE" << endl;
            return;
        }
        cout << "Contraseña: ";
        getline(cin, pswd);
    }
    float bono = 500 + rand () % 500;
    sessionID = id-1;
    clientes[sessionID].setCash(clientes[sessionID].getCash() + bono);
    cout << "Sesión iniciada" << endl;
    cout << "Bono por iniciar sesión: +$" << bono << endl;
    session.display(true, true);
    sessionID = -1;
}

void save () {
    ofstream file ("clientes.txt");
    for (const auto x : clientes) {
        file << x.getPassword() << endl;
    }
    file.close();
}

void load () {
    ifstream file ("clientes.txt");
    while (file.good()) {
        string pswd;
        file >> pswd;
        if (pswd.empty()) continue;
        clientes.emplace_back(pswd);
    }
    file.close();
}