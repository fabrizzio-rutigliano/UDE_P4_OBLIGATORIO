//GP
#ifndef _Autor_H
#define _Autor_H

#include "Objeto.h"

class Autor : public Objeto{
    private:
        int cedula;
        String nombre;
        String apellido;
    
    public:

        Autor(int, String, String); //constructor comun

        ~Autor(); //Destructor

        int getCedula(); //Devuelve la cedula del autor

        String getNombre(); //Devuelve el nombre del autor

        String getApellido(); //Devuelve el apellido del autor

};

#endif