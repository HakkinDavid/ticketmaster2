/*  nombre: Ticketmaster 2 (Main file)
*   autor: David Emmanuel Santana Romero
*   fecha: 31 de mayo de 2023
*/

#include "evento.h" // librería del proyecto que define la clase Evento
#include "tienda.h" // librería del proyecto que define la clase Tienda
#include "Administrador.h" // librería del proyecto que define la clase Administrador
#include "cliente.h" // librería del proyecto que define la clase Cliente

#include "menu/menu.h" // librería de David Emmanuel Santana Romero que permite implementar menús recursivos de manera fácil
#include <string> // librería de strings
#include <iostream> // librería de i/o
#include <fstream> // librería de archivos

#include "ricky.h" // librería sumamente necesaria
using namespace std;

// vector base para los eventos de la tienda
vector<Evento> eventos {
    Evento("Tour Lámina Once", "Tijuana", 26, 3, 2023, "El Cuarteto de Nos", "Black Box, Tijuana, B.C.", 20, 0, 700, "🎵En el día de hoy:\nProducción de bienes improductivos\nCapacitación de Diógenes mediáticos\nControl de obsolescencia planificada\nY seguimos con el show...🎶"),
    Evento("World's Hottest Tour", "Tijuana", 15, 2, 2023, "Bad Bunny", "Plaza Monumental, Playas de Tijuana, B.C", 20, 0, 4000, "🎵*Ininteligible*🎶 (No sé, yo sí terminé la primaria.)"),
    Evento("PP", "Tijuana", 25, 10, 2023, "Peso Pluma", "Plaza Monumental, Playas de Tijuana, B.C", 21, 0, 2000),
    Evento("Saturo World Tour", "Tijuana", 10, 6, 2023, "Rauw Alejandro", "Plaza Monumental, Playas de Tijuana, B.C", 19, 0, 3000)
};

// vector que contiene a los clientes del programa
vector<Cliente> clientes;

// objeto en memoria dinámica de tipo Tienda que se inicializa con el vector de eventos
Tienda * tienda = new Tienda(eventos);

// variable global que almacena la sesión actual
int sessionID = -1;

// logotipo del proyecto
string logo = "   __  _      __        __                       __                ___\n  / /_(_)____/ /_____  / /_____ ___  ____ ______/ /____  _____    /_  |\n / __/ / ___/ //_/ _ \\/ __/ __ `__ \\/ __ `/ ___/ __/ _ \\/ ___/   __/ /\n/ /_/ / /__/ ,< /  __/ /_/ / / / / / /_/ (__  ) /_/  __/ /      / __/ \n\\__/_/\\___/_/|_|\\___/\\__/_/ /_/ /_/\\__,_/____/\\__/\\___/_/      /____/ \n                                                                      \n";

// we both know what's been going on
Rick rick;

// declaración de las funciones del programa
void crearUsuario ();
void iniciarSesion ();
void trabajar ();
void save ();
void load ();
void adminLogin ();
void changeAdminLogin ();

// creación del objeto tipo Administrador con una contraseña predefinida
Administrador Encargado (eventos, clientes, "blockbuster123");

// creación de los menús del programa, siguiendo la sintaxis de la librería de David Emmanuel Santana Romero
// Menu nombreDelObjeto ({
//    {char, {string, void/lambda function }}, ...
// }, string);
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

// programa principal
int main () {
    load (); // cargar la base de datos
    mainMenu.display(true, true); // desplegar el menú principal
    cout << logo << endl; // desplegar el logotipo para despedirse
    cout << "Guardando datos y limpiando la memoria ..." << endl;
    delete tienda; // eliminar la tienda de la memoria dinámica
    tienda = nullptr; // borrar el puntero
    save (); // guardar los datos en la base de datos persistente
    return 0; // salir
}

// creación de un usuario
void crearUsuario () {
    // introducir la contraseña
    cout << "Proporciona una contraseña de 8 a 30 caracteres" << endl;
    string pswd;
    do {
        cout << "Contraseña: ";
        getline(cin, pswd);
        // cerciorarse que no es el código konami
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    } while (pswd.size() < 8 || pswd.size() > 30);
    system ("cls");
    // censurar la contraseña
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
    // calcular el bono
    float bono = 5000 + rand () % 1000;
    // crear el cliente
    clientes.emplace_back(pswd);
    // otorgar el bono
    clientes.back().setCash(bono);
    cout << "El ID del nuevo usuario es: " << clientes.back().getID() << endl;
    cout << "Bono por crear cuenta: +$" << bono << endl;
}

// función para agregar fondos a la cuenta cuya sesión está iniciada
void trabajar () {
    float bono = 500 + rand () % 500;
    cout << "Has obtenido +$" << bono << endl;
    clientes[sessionID].setCash(clientes[sessionID].getCash() + bono);
}

// iniciar sesión
void iniciarSesion () {
    int id;
    string pswd;
    // obtener el ID
    cout << "ID: ";
    cin >> id;
    getchar();
    if (id < 1 || id > clientes.size()) {
        cout << "USUARIO INEXISTENTE" << endl;
        return;
    }
    // 3 intentos para ingresar la contraseña
    for (int attempts = 0; clientes[id-1].getPassword() != pswd; attempts++) {
        if (attempts >= 3) {
            cout << "INTÉNTALO MÁS TARDE" << endl;
            return;
        }
        cout << "Contraseña: ";
        getline(cin, pswd);
        // ¿es el código konami?
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    }
    system ("cls");
    cout << "ID: " << id << endl;
    // censurar la contraseña
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
    // calcular el bono
    float bono = 500 + rand () % 500;
    sessionID = id-1; // establecer el ID de sesión
    // otorgar el bono
    clientes[sessionID].setCash(clientes[sessionID].getCash() + bono);
    cout << "Sesión iniciada" << endl;
    cout << "Bono por iniciar sesión: +$" << bono << endl;
    session.display(true, true); // desplegar el menú de la sesión
    sessionID = -1; // cerrar sesión cuando el menú se cierra
}

// iniciar sesión como el administrador
void adminLogin () {
    string pswd;
    // 3 intentos para introducir la contraseña
    for (int attempts = 0; Encargado.getPassword() != pswd; attempts++) {
        if (attempts >= 3) {
            cout << "INTÉNTALO MÁS TARDE" << endl;
            return;
        }
        cout << "Contraseña: ";
        getline(cin, pswd);
        // ¿es el código konami?
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    }
    system("cls");
    // censurar la contraseña
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
    adminMenu.display(true, true); // desplegar el menú del administrador
}

// cambiar la contraseña maestra
void changeAdminLogin () {
    cout << "Proporciona una contraseña de 8 a 30 caracteres" << endl;
    string pswd;
    // introducir la nueva contraseña
    do {
        cout << "Contraseña: ";
        getline(cin, pswd);
        // ¿es el código konami?
        if (rick.isPasscode(pswd)) {
            rick.roll();
            return;
        }
    } while (pswd.size() < 8 || pswd.size() > 30);
    system("cls");
    // censurar la contraseña
    cout << "Contraseña: ";
    for (int i = 0; i < pswd.size(); i++) {
        cout << "*";
    }
    cout << endl;
    Encargado.setPassword(pswd); // establecer la nueva contraseña
}

// guardar la base de datos en un medio persistente
void save () {
    // elegir la ruta de la base de datos
    ofstream file ("usuarios.txt");
    // escribir la contraseña del administrador
    file << Encargado.getPassword() << endl;
    // escribir las contraseñas de los clientes
    for (const auto &x : clientes) {
        file << x.getPassword() << endl;
    }
    // cerrar el archivo
    file.close();
}

void load () {
    // elegir la ruta de la base de datos
    ifstream file ("usuarios.txt");
    // si no existe, crearla y salir
    if (!file.good()) {
        ofstream newFile ("usuarios.txt");
        newFile << endl;
        newFile.close();
        file.close();
        return;
    }
    // obtener la contraseña del administrador
    string adminPswd;
    file >> adminPswd;
    // si realmente cumple con las especificaciones de la contraseña maestra, establecerla como tal
    // caso contrario, la contraseña predefinida será usada
    if (adminPswd.size() >= 8 && adminPswd.size() <= 30) Encargado.setPassword(adminPswd);
    // mientras el archivo contenga contraseñas, leerlas y crear los objetos Cliente necesarios
    while (file.good()) {
        string pswd;
        file >> pswd;
        if (pswd.empty()) continue; // ignorar líneas en blanco
        clientes.emplace_back(pswd);
    }
    // cerrar el archivo
    file.close();
}