#include "Libro.h"

Libro :: Libro(String is, String tit, String edi, float prec): isbn(is), titulo(tit), editorial(edi){
    precioBase = prec;
    unidadesVendidas = 0;
}

Libro :: ~Libro(){}

String Libro :: getIsbn(){
    return isbn;
}

String Libro :: getTitulo(){
    return titulo;
}

String Libro :: getEditorial(){
    return editorial;
}

float Libro :: getPrecioBase(){
    return precioBase;
}

int Libro :: getUnidadesVendidas(){
    return unidadesVendidas;
}
        
void Libro :: setPrecioBase(float prec){
    precioBase = prec;
}

void Libro :: incrementarVenta(){
    unidadesVendidas ++;
}

// Los metodos virtuales puros precioVenta y tipoLibro se implementan en las clases derivadas