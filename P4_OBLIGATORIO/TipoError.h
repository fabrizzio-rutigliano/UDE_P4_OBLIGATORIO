#ifndef _TipoError_H
#define _TipoError_H

// Codigos de error que la Fachada devuelve a la capa de presentacion (main).
// La capa logica no imprime mensajes: solo informa que paso y el main decide que mostrar.

enum TipoError
{
    SIN_ERROR,              // la operacion se realizo correctamente
    AUTOR_YA_EXISTE,        // Req 1: ya hay un autor con esa cedula
    LIBRO_YA_EXISTE,        // Req 2: ya hay un libro con ese isbn
    LIBRO_NO_EXISTE,        // Req 3, 5, 7: no hay un libro con ese isbn
    NO_ES_NOVELA,           // Req 3: el isbn existe pero no corresponde a una novela
    AUTOR_NO_EXISTE,        // Req 3: no hay un autor con esa cedula
    SIN_COINCIDENCIAS,      // Req 4: ningun titulo comienza con la frase
    SIN_AUTORES,            // Req 6: no hay autores registrados
    EDITORIAL_SIN_LIBROS    // Req 8, 10: no hay libros de esa editorial
};

#endif
