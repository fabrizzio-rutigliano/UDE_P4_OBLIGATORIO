#ifndef _String_H
#define _String_H

#include <stdio.h>

const int MAX = 80;
class String
{
    private:
        char * cadena;
    public:
        String(); // constructor por defecto.
    
        String (const char* s); // constructor común
        
        String (const String &); // constructor de copia

        ~String(); // destructor

        String operator= (const String &); // sobrecarga de asignación

        bool operator== (String); // compara dos strings por igualdad.

        bool operator< (String); // compara dos strings alfabéticamente

        String operator+ (String); // concatenación de strings.

        void scan(); // lee un string desde la entrada estándar.

        void print(); // muestra un string en la salida estándar

        // AUXILIARES PARA METODOS ESPECIFICOS DEL PROBLEMA -> manejo de libros
        int largo(); // Devuelve la cantidad de caracteres del String

        char caracter(int); // Devuelve el caracter de la posicion indicada

};

#endif