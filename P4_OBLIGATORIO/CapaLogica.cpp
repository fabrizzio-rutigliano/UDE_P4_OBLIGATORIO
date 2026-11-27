#include "CapaLogica.h"

CapaLogica :: CapaLogica() : dicAutores(), dicLibros()
{

}

CapaLogica :: ~CapaLogica()
{
    // No hace falta liberar nada aca: al destruirse dicAutores y dicLibros
    // sus destructores liberan cada Autor y cada Libro una sola vez.
    // Las novelas solo apuntan a autores del diccionario, por eso no los liberan.
}

// Req 1
void CapaLogica :: registrarAutor(Autor * a, TipoError &error)
{
    if (dicAutores.member(a->getCedula()))
    {
        error = AUTOR_YA_EXISTE;
        delete a; // el autor no se inserta, se libera para no perder memoria
    }
    else
    {
        dicAutores.insert(a);
        error = SIN_ERROR;
    }
}

// Req 2
void CapaLogica :: registrarLibro(Libro * l, TipoError &error)
{
    if (dicLibros.member(l->getIsbn()))
    {
        error = LIBRO_YA_EXISTE;
        delete l; // destructor virtual: libera la Novela/Texto/Escolar que corresponda
    }
    else
    {
        // las unidades vendidas ya quedan en 0 desde el constructor de Libro
        dicLibros.insert(l);
        error = SIN_ERROR;
    }
}

// Req 3
void CapaLogica :: asociarAutorNovela(int ci, String isbn, TipoError &error)
{
    if (!dicLibros.member(isbn))
        error = LIBRO_NO_EXISTE;
    else
    {
        Libro * l = dicLibros.find(isbn);
        Novela * n = dynamic_cast<Novela *>(l); // NULL si el libro no es una novela
        if (n == NULL)
            error = NO_ES_NOVELA;
        else if (!dicAutores.member(ci))
            error = AUTOR_NO_EXISTE;
        else
        {
            n->setAutor(dicAutores.find(ci)); // si ya tenia autor, queda reemplazado
            error = SIN_ERROR;
        }
    }
}

// Req 4
void CapaLogica :: listarLibrosPorPrefijo(String frase, Iterador &iter, TipoError &error)
{
    dicLibros.listarPorPrefijoTitulo(frase, iter);
    if (iter.hayMasObjetos())
        error = SIN_ERROR;
    else
        error = SIN_COINCIDENCIAS;
}

// Req 5
void CapaLogica :: consultarDetalleLibro(String isbn, Libro * &l, TipoError &error)
{
    if (!dicLibros.member(isbn))
    {
        l = NULL;
        error = LIBRO_NO_EXISTE;
    }
    else
    {
        l = dicLibros.find(isbn);
        error = SIN_ERROR;
    }
}

// Req 6
void CapaLogica :: listarAutores(Iterador &iter, TipoError &error)
{
    if (dicAutores.esVacio())
        error = SIN_AUTORES;
    else
    {
        dicAutores.listarAutoresOrden(iter);
        error = SIN_ERROR;
    }
}

// Req 7
void CapaLogica :: registrarVentaUnidad(String isbn, float &importe, TipoError &error)
{
    if (!dicLibros.member(isbn))
    {
        importe = 0;
        error = LIBRO_NO_EXISTE;
    }
    else
    {
        Libro * l = dicLibros.find(isbn);
        l->incrementarVenta();
        importe = l->precioVenta(); // polimorfico segun Novela / Texto / Escolar
        error = SIN_ERROR;
    }
}

// Req 8
void CapaLogica :: recaudacionPorEditorial(String editorial, float &recaudacion, TipoError &error)
{
    int cantLibros;
    dicLibros.recaudacionEditorial(editorial, recaudacion, cantLibros);
    if (cantLibros == 0)
        error = EDITORIAL_SIN_LIBROS;
    else
        error = SIN_ERROR;
}

// Req 9
void CapaLogica :: unidadesVendidasSuperanPrecio(float precio, int &novelas, int &textos, int &escolares)
{
    dicLibros.unidadesVendidasSuperanPrecio(precio, novelas, textos, escolares);
}

// Req 10
void CapaLogica :: libroMasVendidoEditorial(String editorial, Libro * &l, TipoError &error)
{
    l = dicLibros.libroMasVendidoEditorial(editorial);
    if (l == NULL)
        error = EDITORIAL_SIN_LIBROS;
    else
        error = SIN_ERROR;
}
