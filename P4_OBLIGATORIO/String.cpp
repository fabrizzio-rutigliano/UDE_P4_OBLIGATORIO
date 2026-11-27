#include "String.h"
#include <iostream>
#include <string.h>
using namespace std;


String::String()
{
    cadena = new char[1];
    cadena[0] = '\0';
}

String::String(const char* s) 
{
    int largo = strlen(s);
    cadena = new char[largo + 1];
    strcpy(cadena, s);
}

String::String(const String &otro) 
{
    int largo = strlen(otro.cadena);
    cadena = new char[largo + 1];
    strcpy(cadena, otro.cadena);
}

String::~String() 
{
    delete[] cadena;
}


String String :: operator= (const String &otro)
{
    if (this != &otro)
    {
        delete [] cadena;
        int largo = strlen (otro.cadena);
        cadena = new char[largo+1];
        strcpy (cadena, otro.cadena);
    }
    return (*this);
}

bool String :: operator== (String otro)
{
    return (bool) (strcmp (cadena, otro.cadena) == 0);
}

bool String :: operator< (String otro)
{
    return (bool) (strcmp (cadena, otro.cadena) < 0);
}


String String :: operator+ (String otro)
{
    String aux;
    int largo1 = strlen (cadena);
    int largo2 = strlen (otro.cadena);
    aux.cadena = new char [largo1 + largo2 + 1];
    strcpy (aux.cadena, cadena);
    strcat (aux.cadena, otro.cadena);
    return aux;
}

void String :: scan ()
{
    char aux[MAX];
    char c = cin.get();
    int i=0;
    while (c != '\n' && !cin.eof() && i < MAX-1)
    {
        aux[i] = c;
        i++;
        c = cin.get();
    }
    aux[i] = '\0';
    // si la linea era mas larga que MAX, se descarta el resto para que no lo lea la proxima entrada
    while (c != '\n' && !cin.eof())
        c = cin.get();
    delete [] cadena; // se libera la cadena anterior para no perder memoria
    cadena = new char[i+1];
    strcpy (cadena, aux);
}

void String :: print()
{
    cout << cadena;
}

// AUXILIARES PARA METODOS ESPECIFICOS DEL PROBLEMA -> manejo de libros

int String :: largo()
{
    return strlen(cadena);
}

char String :: caracter(int posicion)
{
    return cadena[posicion];
}