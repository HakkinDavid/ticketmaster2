/*  nombre: Ticketmaster 2 (Main file)
*   autor: David Emmanuel Santana Romero
*   fecha: 31 de mayo de 2023
*/

#include "menu/menu.h" // library by David Emmanuel Santana Romero which allows for easy recursive menu implementation
#include "evento.h"
#include "tienda.h"
#include "Administrador.h"
#include "cliente.h"
#include <string> // text strings library
#include <iostream> // input output stream library
#include <fstream> // file stream library
#include "ricky.h" // completely necessary library
using namespace std;

vector<Evento> eventos {
    Evento("Tour Lámina Once", "Tijuana", 26, 3, 2023, "El Cuarteto de Nos", "Black Box, Tijuana, B.C.", 20, 0, 700, "🎵En el día de hoy:\nProducción de bienes improductivos\nCapacitación de Diógenes mediáticos\nControl de obsolescencia planificada\nY seguimos con el show...🎶"),
    Evento("World's Hottest Tour", "Tijuana", 15, 2, 2023, "Bad Bunny", "Plaza Monumental, Playas de Tijuana, B.C", 20, 0, 4000, "🎵*Ininteligible*🎶 (No sé, yo sí terminé la primaria.)"),
    Evento("PP", "Tijuana", 25, 10, 2023, "Peso Pluma", "Plaza Monumental, Playas de Tijuana, B.C", 21, 0, 2000),
    Evento("Saturo World Tour", "Tijuana", 10, 6, 2023, "Rauw Alejandro", "Plaza Monumental, Playas de Tijuana, B.C", 19, 0, 3000)
};

vector<Cliente> clientes;
Tienda * tienda = new Tienda(eventos);
int sessionID = -1;
string logo = "   __  _      __        __                       __                ___\n  / /_(_)____/ /_____  / /_____ ___  ____ ______/ /____  _____    /_  |\n / __/ / ___/ //_/ _ \\/ __/ __ `__ \\/ __ `/ ___/ __/ _ \\/ ___/   __/ /\n/ /_/ / /__/ ,< /  __/ /_/ / / / / / /_/ (__  ) /_/  __/ /      / __/ \n\\__/_/\\___/_/|_|\\___/\\__/_/ /_/ /_/\\__,_/____/\\__/\\___/_/      /____/ \n                                                                      \n";

Rick rick;

void crearUsuario ();
void iniciarSesion ();
void trabajar ();
void save ();
void load ();
void adminLogin ();
void changeAdminLogin ();

Administrador Encargado (eventos, clientes, "blockbuster123");

Menu adminMenu ({
    {'1', {"Crear evento", [] () { Encargado.crearEvento (); }}},
    {'2', {"Estadísticas de ventas", [] () { Encargado.estadisticasVentas (*tienda); }}},
    {'3', {"Información de usuarios", [] () { Encargado.infoClientes (); }}},
    {'4', {"Cambiar contraseña maestra", changeAdminLogin }}
}, logo + "MENÚ DEL ADMINISTRADOR");

Menu clientMenu ({
    {'1', {"Iniciar sesión", iniciarSesion}},
    {'2', {"Crear usuario", crearUsuario}}
}, logo + "MENÚ DEL CLIENTE");

Menu mainMenu ({
    {'1', {"Cliente", [] () { clientMenu.display(true, true); }}},
    {'2', {"Administrador", adminLogin }}
}, logo + "MENÚ PRINCIPAL");

Menu session ({
        {'1', {"Inventario", [] () { clientes[sessionID].displayInventario (); } }},
        {'2', {"Comprar", [] () { tienda -> display (clientes[sessionID]); } }},
        {'3', {"Chambear", trabajar}}
}, logo);

int main () {
    load ();
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
        getline(cin, pswd);
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    } while (pswd.size() < 8 || pswd.size() > 30);
    system ("cls");
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
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
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    }
    system ("cls");
    cout << "ID: " << id << endl;
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
    float bono = 500 + rand () % 500;
    sessionID = id-1;
    clientes[sessionID].setCash(clientes[sessionID].getCash() + bono);
    cout << "Sesión iniciada" << endl;
    cout << "Bono por iniciar sesión: +$" << bono << endl;
    session.display(true, true);
    sessionID = -1;
}

void adminLogin () {
    string pswd;
    for (int attempts = 0; Encargado.getPassword() != pswd; attempts++) {
        if (attempts >= 3) {
            cout << "INTÉNTALO MÁS TARDE" << endl;
            return;
        }
        cout << "Contraseña: ";
        getline(cin, pswd);
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    }
    system("cls");
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
    adminMenu.display(true, true);
}

void changeAdminLogin () {
    cout << "Proporciona una contraseña de 8 a 30 caracteres" << endl;
    string pswd;
    do {
        cout << "Contraseña: ";
        getline(cin, pswd);
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    } while (pswd.size() < 8 || pswd.size() > 30);
    system("cls");
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
    Encargado.setPassword(pswd);
}

void save () {
    ofstream file ("usuarios.txt");
    file << Encargado.getPassword() << endl;
    for (const auto &x : clientes) {
        file << x.getPassword() << endl;
    }
    file.close();
}

void load () {
    ifstream file ("usuarios.txt");
    if (!file.good()) {
        ofstream newFile ("usuarios.txt");
        newFile << endl;
        newFile.close();
        file.close();
        return;
    }
    string adminPswd;
    file >> adminPswd;
    if (adminPswd.size() >= 8 && adminPswd.size() <= 30) Encargado.setPassword(adminPswd);
    while (file.good()) {
        string pswd;
        file >> pswd;
        if (pswd.empty()) continue;
        clientes.emplace_back(pswd);
    }
    file.close();
}