//FR
#ifndef _Libro_H
#define _Libro_H

#include "Objeto.h"

class Libro{
    private:
        String isbn;
        String titulo;
        String editorial;
        float precioBase;
        int unidadesVendidas;

    public:
        Libro(String, String, String, float, int);
        virtual ~Libro();
        String getIsbn();
        String getTitulo();
        String Editorial();
        float getPrecioBase();
        int getUnidadesVendidas();
        void setPrecioBase(float);
        void incrementarVenta();
        virtual float precioVenta();
        virtual String tipoLibro();

};

#endif