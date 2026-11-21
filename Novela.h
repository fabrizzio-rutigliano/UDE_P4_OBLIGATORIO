//GP

#ifndef _Novela_H
#define _Novela_H

#include "Libro.h"
#include "Autor.h"

class Novela : public Libro{
    private:
        String genero;
        Autor * autor;

    public:
        Novela(String, String, String, float, String); //constructor comun

        String getGenero(); //selector de genero

        Autor * getAutor(); //selector de autor

        void setAutor(Autor *); //carga el autor de la novela

        bool tieneAutor(); //devuelve si tiene autor asociado

        float precioVenta(); //devuelve el precio de venta de la novela

        String tipoLibro(); //devuelve el tipo de libro
};

#endif