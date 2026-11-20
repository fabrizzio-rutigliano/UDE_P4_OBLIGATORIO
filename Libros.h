//FR
#ifndef _Libros_H
#define _Libros_H

#include "Libro.h"
#include "Iterador.h"

const int B = 500;

class Libros{
    private:
        typedef struct Nodo{
            Libro * info;
            Nodo * sig;
        };

        typedef Nodo * Lista;

        typedef Lista Hash[B];

    public:
        Libros(); //constructor por defecto

        ~Libros(); //destructor

        bool member(String); //devuelve si existe el elemento en el Hash

        void insert(Libro *); //inserta un libro en el Hash

        Libro * find(String); //devuelve el libro con el isbn correspondiente

        bool esVacio(); //devuelve si es vacio el hash o no

        void listarPorPrefijoTitulo(String, Iterador &); //lista libros con titulos que comiencen con el string

        void recaudacionEditorial(String, float &, int &); //recibe una editorial y devuelve la cantidad facturada y cantidad de copias vendidas

        Libro * libroMasVendidoEditorial(String); //recibe el nombre de la editorial y devuelve el libro mas vendido correspondiente

};

#endif