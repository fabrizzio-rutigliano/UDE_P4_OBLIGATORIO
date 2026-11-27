#include "Iterador.h"

Iterador :: Iterador()
{
    prim = NULL;
    ult = NULL;
    actual = NULL;
}

Iterador :: ~Iterador()
{
    Nodo * aux = prim;
    while(aux != NULL)
    {
        prim = prim->sig;
        delete aux;
        aux = prim;
    }
}

void Iterador :: insertar(Objeto * o)
{
    Nodo * nuevo = new Nodo;
    nuevo->info = o;
    nuevo->sig = NULL;
    if(prim == NULL)
    {
        prim = nuevo;
        ult = nuevo;
        actual = nuevo;
    }
    else
    {
        ult->sig = nuevo;
        ult = ult->sig;
    }
}

bool Iterador :: hayMasObjetos()
{
    return (bool) (actual!=NULL);
}

Objeto * Iterador :: proximoObjeto()
{
    Objeto * o = actual->info;
    actual = actual->sig;
    return o;
}

