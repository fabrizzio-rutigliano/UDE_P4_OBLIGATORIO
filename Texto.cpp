#include "Texto.h"

Texto :: Texto(String is, String tit, String edi, float prec, String mat, Fecha fec) 
    : Libro(is, tit, edi, prec), materia(mat), fechaPublicado(fec)
    {

}

String Texto :: getMateria(){
    return materia;
}
Fecha Texto :: getFechaPublicado(){
    return fechaPublicado;
}

float Texto :: precioVenta(){

    Fecha limite(1,1,2026);
    float prec;

    if(fechaPublicado < limite)
        prec = getPrecioBase() * 0.75;
    else
        prec = getPrecioBase();
    return prec;
}

String Texto :: tipoLibro(){
    
    return "Texto";
}