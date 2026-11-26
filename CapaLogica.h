#ifndef _CapaLogica_H
#define _CapaLogica_H

#include "Autores.h"
#include "Libros.h"
#include "Novela.h"
#include "Escolar.h"
#include "TipoError.h"

// Fachada de acceso a la capa logica. Es el unico punto de entrada que usa el main.
// Ninguna operacion imprime en pantalla: los resultados y errores se devuelven por parametro.

class CapaLogica
{
    private:
        Autores dicAutores;
        Libros dicLibros;

    public:
        CapaLogica(); //constructor por defecto

        ~CapaLogica(); //destructor (los diccionarios liberan autores y libros)

        // Req 1: registra el autor. Si la cedula ya existe devuelve AUTOR_YA_EXISTE
        // y libera el autor recibido (la fachada pasa a ser duenia del puntero).
        void registrarAutor(Autor *, TipoError &);

        // Req 2: registra el libro (Novela, Texto o Escolar) con 0 unidades vendidas.
        // Si el isbn ya existe devuelve LIBRO_YA_EXISTE y libera el libro recibido.
        void registrarLibro(Libro *, TipoError &);

        // Req 3: asocia el autor (cedula) a la novela (isbn), reemplazando el anterior si lo habia.
        void asociarAutorNovela(int, String, TipoError &);

        // Req 4: carga en el iterador los libros cuyo titulo comienza con la frase.
        void listarLibrosPorPrefijo(String, Iterador &, TipoError &);

        // Req 5: devuelve el libro con ese isbn (para que el main liste todos sus datos).
        void consultarDetalleLibro(String, Libro * &, TipoError &);

        // Req 6: carga en el iterador los autores ordenados por cedula de menor a mayor.
        void listarAutores(Iterador &, TipoError &);

        // Req 7: registra la venta de una unidad y devuelve el importe de esa unidad.
        void registrarVentaUnidad(String, float &, TipoError &);

        // Req 8: devuelve el monto total recaudado por los libros de esa editorial.
        void recaudacionPorEditorial(String, float &, TipoError &);

        // Req 9: unidades vendidas de libros con precio base mayor al dado,
        // discriminadas en novelas, textos comunes y escolares.
        void unidadesVendidasSuperanPrecio(float, int &, int &, int &);

        // Req 10: devuelve el libro mas vendido de la editorial.
        void libroMasVendidoEditorial(String, Libro * &, TipoError &);
};

#endif
