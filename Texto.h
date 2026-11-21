//FR
#ifndef _Texto_H
#define _Texto_H

#include "Libro.h"
#include "Fecha.h"

class Texto : public Libro{
    private:
        String materia;
        Fecha fechaPublicado;
    
    public:
        Texto(String, String, String, float, String, Fecha); //constructor comun

        String getMateria(); //selector de materia
        Fecha getFechaPublicado(); //selector de fecha de publicacion

        float precioVenta(); //devuelve el precio de venta del libro de texto
        String TipoLibro(); //devuelve el tipo libro
}



#endif