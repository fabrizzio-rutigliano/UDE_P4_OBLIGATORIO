#include "Novela.h"

Novela :: Novela(String ib, String tit, String edi, float pre, String gen) : Libro(ib, tit, edi, pre)
{
    genero = gen;
    autor = NULL;
}

String Novela :: getGenero()
{
    return genero;
}

Autor * Novela :: getAutor()
{
    return autor;
}

void Novela :: setAutor(Autor * a)
{
    autor = a;
}

bool Novela :: tieneAutor()
{
    return (autor != NULL);
}

float Novela :: precioVenta()
{
    float prec;
    if(genero == "Infantil")
        prec = (getPrecioBase() * 0.80);
    else 
        prec = getPrecioBase();
    return prec;
}

String Novela :: tipoLibro()
{
    return "Novela";
}