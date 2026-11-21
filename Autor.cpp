#include "Autor.h"


Autor :: Autor(int ci, String nom, String ape)
{
    cedula = ci;
    nombre = nom;
    apellido = ape;
}

Autor :: ~Autor()
{

}

int Autor :: getCedula()
{
    return cedula;
}

String Autor :: getNombre()
{
    return nombre;
}

String Autor :: getApellido()
{
    return apellido;
}