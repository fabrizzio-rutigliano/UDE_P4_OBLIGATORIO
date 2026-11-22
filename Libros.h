//FR
#ifndef _Libros_H
#define _Libros_H

#include "Libro.h"
#include "Iterador.h"

const int B = 500;

class Libros{
    private:
        struct Nodo{
            Libro * info;
            Nodo * sig;
        };
        
        Nodo * Hash[B]; // Solucion de práctico 5 ejercicio 4, simplifica la definicion de un hash

        // Metodos auxiliares privados

        int h(String); //funcion de dispersion

        void crearLista(Nodo * &); //Inicializa una lista vacía (NULL)
        
        void destruirLista(Nodo * &); //Libera la memoria de una lista
        
        bool perteneceLista(Nodo *, String); //Busca si existe un libro con determinado ISBN
        
        void insFrontEnLista(Nodo * &, Libro *); //Inserta un libro al principio de una lista
        
        Libro * obtenerEnLista(Nodo *, String); //Devuelve el puntero al libro correspondiente al ISBN

    public:
        Libros(); //constructor por defecto

        ~Libros(); //destructor

        bool member(String); //devuelve si existe el elemento en el Hash

        void insert(Libro *); //inserta un libro en el Hash

        Libro * find(String); //devuelve el libro con el isbn correspondiente

        bool esVacio(); //devuelve si es vacio el hash o no

        void listarPorPrefijoTitulo(String, Iterador &); //lista libros con titulos que comiencen con el string

        void recaudacionEditorial(String, float &, int &); //recibe una editorial y devuelve la cantidad facturada y cantidad de copias vendidas

        void unidadesVendidasSuperanPrecio(float, int &, int &, int &); //recibe un precio y devuelve cuantas unidades vendidas de novelas, textos y escolares superan ese precio base

        Libro * libroMasVendidoEditorial(String); //recibe el nombre de la editorial y devuelve el libro mas vendido correspondiente

};

#endif