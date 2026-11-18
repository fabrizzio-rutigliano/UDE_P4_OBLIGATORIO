#ifndef ITERADOR_H
#define ITERADOR_H

#include "Objeto.h"


class Iterador{
    private:
        typedef struct Nodo
        {
            Objeto * info;
            Nodo * sig;
        };

        Nodo * prim;
        Nodo * ult;
        Nodo * actual;
        
    public:
        Iterador();

        ~Iterador();

        void insertar(Objeto *);

        bool hayMasObjetos();

        Objeto * proximoObjeto();
};

#endif
