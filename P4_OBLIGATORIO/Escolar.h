//FR
#ifndef _Escolar_H
#define _Escolar_H

#include "Texto.h"

class Escolar : public Texto{
    private:
        int anioEscuela;
    
    public:
        Escolar(String, String, String, float, String, Fecha, int); //constructor comun

        int getAnioEscuela(); //selector de año de escuela

        float precioVenta(); //devuelve el precio de venta del libro escolar

        String tipoLibro(); //devuelve el tipo de libro
        
};

#endif