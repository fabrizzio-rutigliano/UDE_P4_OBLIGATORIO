#include "Escolar.h"

Escolar :: Escolar(String is, String tit, String edi, float prec, String mat, Fecha fec, int anio)
    : Texto(is, tit, edi, prec, mat, fec)
{
    anioEscuela = anio;
}

int Escolar :: getAnioEscuela(){
    return anioEscuela;
}

float Escolar :: precioVenta(){
    float prec = Texto :: precioVenta(); //ejemplo practico 6
    
    if(anioEscuela >= 1 && anioEscuela <= 3)
        prec = prec * 0.90;
    
    return prec;
}

String Escolar :: tipoLibro(){
    return "Escolar";
}