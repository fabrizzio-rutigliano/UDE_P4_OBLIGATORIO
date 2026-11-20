//GP
#ifndef _Autor_H
#define _Autor_H

#include "String.h"

class Autor{
    private:
        int cedula;
        String nombre;
        String apellido;
    
    public:
        Autor(); //constructor por defecto

        Autor(int, String, String); //constructor comun

        ~Autor(); //Destructor

        int getCedula(); //Devuelve la cedula del autor

        String getNombre(); //Devuelve el nombre del autor

        String getApellido(); //Devuelve el apellido del autor

};

#endif