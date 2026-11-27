#include "Autores.h"



Autores :: Autores()
{
    arbol = NULL;
}

Autores :: ~Autores()
{
    destruirArbol(arbol);
}

void Autores :: destruirArbol(ABB &a)
{
    if (a != NULL)
    {
        destruirArbol(a->hizq);
        destruirArbol(a->hder);
        delete a->info;
        delete a;
        a = NULL;
    }
}

bool Autores :: member(int ci)
{
    bool encontre = false;
    ABB aux = arbol;
    while (!encontre && aux!=NULL)
    {
        if(ci == aux->info->getCedula())
            encontre = true;
        else
        {
            if(ci < aux->info->getCedula())
                aux = aux->hizq;
            else
                aux = aux->hder;
        }
    }
    return encontre;
}

//precondicion: el autor no existe en el diccionario
void Autores :: insert(Autor * a)
{
    Nodo * aut = new Nodo;
    aut->info = a;
    aut->hizq = NULL;
    aut->hder = NULL;

    if (arbol == NULL)
        arbol = aut; 
    else
    {  
        ABB aux = arbol;
        ABB padre = NULL;  
        while (aux!=NULL)
        {
            padre = aux;
            if(a->getCedula() < aux->info->getCedula())
                aux = aux->hizq;
            else
                aux = aux->hder;
        }
    
        if (a->getCedula() < padre->info->getCedula())
            padre->hizq = aut;           
        else
            padre->hder = aut;
    }
}

//precondicion: el autor con esa cedula existe en el diccionario
Autor * Autores :: find(int ci)
{
    bool encontre = false;
    ABB aux = arbol;
    while (!encontre)
    {
        if(ci == aux->info->getCedula())
            encontre = true;
        else
        {
            if(ci < aux->info->getCedula())
                aux = aux->hizq;
            else
                aux = aux->hder;
        }
    }
    return aux->info;
}

bool Autores :: esVacio()
{
    return (arbol == NULL);
}

void Autores :: listarAutoresOrden(Iterador &iter)
{
    cargarAutoresIterador(arbol, iter);
}

void Autores :: cargarAutoresIterador(ABB a, Iterador &iter)
{
    if (a != NULL)
    {
        cargarAutoresIterador(a->hizq, iter);
        iter.insertar(a->info);
        cargarAutoresIterador(a->hder, iter);
    }
}