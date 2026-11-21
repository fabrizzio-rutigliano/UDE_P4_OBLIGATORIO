//FR
#ifndef _Libro_H
#define _Libro_H

#include "Objeto.h"

class Libro : public Objeto{
    private:
        String isbn;
        String titulo;
        String editorial;
        float precioBase;
        int unidadesVendidas;

    public:
        Libro(String, String, String, float);
        virtual ~Libro();

        String getIsbn();
        String getTitulo();
        String getEditorial();
        float getPrecioBase();
        int getUnidadesVendidas();
        
        void setPrecioBase(float);
        void incrementarVenta();
        
        //Son metodos virtuales puros, ejemplo en Practico 6, ejercicio 1
        virtual float precioVenta() = 0;
        virtual String tipoLibro() = 0;

};

#endif