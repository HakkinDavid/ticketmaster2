/** nombre: Administrador
    colaboradores: Renata Flores
    fecha: 30 de abril de 2023 **/

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>

class Administrador
{
    public:
        Administrador();
        virtual ~Administrador();
        //funciones set
        void setNombre(std::string);
        void setApellido(std::string);
        void setTelefono(long long);
        void setEmpresa(std::string);
        void setCorreo(std::string);
        void setPassword(std::string);
        void setEstatusAdmi(bool);
        //funciones get
        std::string getNombre()const;
        std::string getApellido()const;
        long long getTelefono()const;
        std::string getEmpresa()const;
        std::string getCorreo()const;
        std::string getPassword()const;
        bool getEstatusAdmi()const;

        void crearAdministrador();
        void iniciarSesion();
   

    private:
        std::string nombre;
        std::string apellido;
        long long telefono;
        std::string empresa;
        std::string correo;
        std::string password;
        bool estatusAdmi;

};

#endif // ADMINISTRADOR_H
