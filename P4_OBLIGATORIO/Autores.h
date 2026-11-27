//GP
#ifndef _Autores_H
#define _Autores_H

#include "Autor.h"
#include "Iterador.h"


class Autores{
    private:
        struct Nodo{
            Autor * info;
            Nodo * hizq;
            Nodo * hder;
        };

        typedef Nodo * ABB;

        ABB arbol;

        void destruirArbol(ABB &); //auxiliar para desrtuctor recursivo

        void cargarAutoresIterador(ABB, Iterador &); //auxiliar para listarAutoresOrden recursiva.

    public:
        Autores(); //Constructor por defecto

        ~Autores(); //Destructor

        bool member(int); //Devuelve si el Autor con esa CI existe en el ABB

        void insert(Autor *); //inserta el autor en el ABB

        Autor * find(int); //Devuelve el autor correspondiente a la CI 

        bool esVacio(); //devuelve si el ABB es vacio

        void listarAutoresOrden(Iterador &); //lista en el iterador todos los Autores del arbol en orden por CI

};

#endif