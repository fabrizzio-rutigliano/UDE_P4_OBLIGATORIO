// Capa de presentacion: menu, lectura de datos y mensajes al usuario.
// Toda la logica se resuelve a traves de la fachada (CapaLogica).
// Los mensajes no llevan tildes para que se vean bien en la consola de Windows.

#include "CapaLogica.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ---------------------------------------------------------------------
// Lectura de datos con validacion
// ---------------------------------------------------------------------

// Descarta lo que quede en la linea actual (por ejemplo el '\n' despues de un numero).
void limpiarLinea()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

// Lee un entero entre min y max. Si se ingresa algo invalido, lo vuelve a pedir.
int leerEntero(const char * mensaje, int min, int max)
{
    int n;
    bool valido = false;
    do
    {
        cout << mensaje;
        cin >> n;
        if (cin.eof())
            return min; // fin de la entrada: se devuelve un valor seguro
        if (cin.fail() || n < min || n > max)
            cout << "  Valor invalido. Debe ser un numero entre " << min << " y " << max << "." << endl;
        else
            valido = true;
        limpiarLinea();
    } while (!valido);
    return n;
}

// Lee un numero real mayor o igual a cero.
float leerPrecio(const char * mensaje)
{
    float p;
    bool valido = false;
    do
    {
        cout << mensaje;
        cin >> p;
        if (cin.eof())
            return 0;
        if (cin.fail() || p < 0)
            cout << "  Valor invalido. Debe ser un numero mayor o igual a cero." << endl;
        else
            valido = true;
        limpiarLinea();
    } while (!valido);
    return p;
}

// Lee una linea de texto no vacia.
String leerTexto(const char * mensaje)
{
    String s;
    do
    {
        cout << mensaje;
        s.scan();
        if (s.largo() == 0 && !cin.eof())
            cout << "  El texto no puede ser vacio." << endl;
    } while (s.largo() == 0 && !cin.eof());
    return s;
}

// Un isbn valido tiene solo digitos, salvo el ultimo que puede ser una X (digito verificador).
// Validarlo aca evita que la funcion de dispersion de Libros reciba caracteres no numericos.
bool isbnValido(String isbn)
{
    int largo = isbn.largo();
    bool valido = (largo > 0);
    for (int i = 0; valido && i < largo; i++)
    {
        char c = isbn.caracter(i);
        bool esDigito = (c >= '0' && c <= '9');
        bool esXFinal = (i == largo - 1 && (c == 'X' || c == 'x'));
        if (!esDigito && !esXFinal)
            valido = false;
    }
    return valido;
}

String leerIsbn()
{
    String isbn;
    bool valido = false;
    do
    {
        isbn = leerTexto("ISBN: ");
        if (cin.eof())
            return isbn;
        valido = isbnValido(isbn);
        if (!valido)
            cout << "  ISBN invalido. Solo se admiten digitos (el ultimo puede ser X)." << endl;
    } while (!valido);
    return isbn;
}

int leerCedula()
{
    return leerEntero("Cedula (sin puntos ni guion): ", 1, 99999999);
}

// Lee una fecha valida (dia, mes y anio por separado).
Fecha leerFecha()
{
    bool valida = false;
    Fecha f;
    do
    {
        cout << "Fecha de publicacion:" << endl;
        int d = leerEntero("  Dia: ", 1, 31);
        int m = leerEntero("  Mes: ", 1, 12);
        int a = leerEntero("  Anio: ", 1, 9999);
        Fecha aux(d, m, a);
        // el constructor de Fecha cambia las fechas invalidas por 01/01/2000,
        // por eso se compara con lo ingresado para detectar el error
        valida = (aux.getDia() == d && aux.getMes() == m && aux.getAnio() == a);
        if (!valida && !cin.eof())
            cout << "  La fecha ingresada no existe." << endl;
        else
            f = aux;
    } while (!valida && !cin.eof());
    return f;
}

// El genero se elige de una lista para que "Infantil" quede siempre escrito igual
// (de eso depende el descuento del 20% en Novela::precioVenta).
String leerGenero()
{
    cout << "Genero:" << endl;
    cout << "  1) Infantil   2) Policial   3) Romance   4) Ciencia ficcion" << endl;
    cout << "  5) Drama      6) Aventura   7) Otro" << endl;
    int op = leerEntero("Opcion: ", 1, 7);
    switch (op)
    {
        case 1: return "Infantil";
        case 2: return "Policial";
        case 3: return "Romance";
        case 4: return "Ciencia ficcion";
        case 5: return "Drama";
        case 6: return "Aventura";
        default: return leerTexto("Escriba el genero: ");
    }
}

// ---------------------------------------------------------------------
// Mostrar datos
// ---------------------------------------------------------------------

void mostrarFecha(Fecha f)
{
    cout << setfill('0') << setw(2) << f.getDia() << "/" << setw(2) << f.getMes() << "/" << f.getAnio() << setfill(' ');
}

void mostrarAutor(Autor * a)
{
    cout << "Cedula: " << a->getCedula() << " | Nombre: ";
    a->getNombre().print();
    cout << " | Apellido: ";
    a->getApellido().print();
    cout << endl;
}

// Muestra todos los datos de un libro segun su tipo (Req 5 y 10).
void mostrarDetalleLibro(Libro * l)
{
    cout << "  Tipo:              "; l->tipoLibro().print(); cout << endl;
    cout << "  ISBN:              "; l->getIsbn().print(); cout << endl;
    cout << "  Titulo:            "; l->getTitulo().print(); cout << endl;
    cout << "  Editorial:         "; l->getEditorial().print(); cout << endl;
    cout << "  Precio base:       $" << l->getPrecioBase() << endl;
    cout << "  Precio de venta:   $" << l->precioVenta() << endl;
    cout << "  Unidades vendidas: " << l->getUnidadesVendidas() << endl;

    Novela * n = dynamic_cast<Novela *>(l);
    if (n != NULL)
    {
        cout << "  Genero:            "; n->getGenero().print(); cout << endl;
        if (n->tieneAutor())
        {
            cout << "  Autor:             ";
            mostrarAutor(n->getAutor());
        }
        else
            cout << "  Autor:             (sin autor asociado)" << endl;
    }
    else
    {
        // si no es novela es un Texto (comun o escolar)
        Texto * t = dynamic_cast<Texto *>(l);
        cout << "  Materia:           "; t->getMateria().print(); cout << endl;
        cout << "  Fecha publicacion: "; mostrarFecha(t->getFechaPublicado()); cout << endl;

        Escolar * e = dynamic_cast<Escolar *>(l);
        if (e != NULL)
            cout << "  Anio de escuela:   " << e->getAnioEscuela() << endl;
    }
}

void mostrarError(TipoError error)
{
    cout << "ERROR: ";
    switch (error)
    {
        case AUTOR_YA_EXISTE:      cout << "ya existe un autor con esa cedula. Registro cancelado."; break;
        case LIBRO_YA_EXISTE:      cout << "ya existe un libro con ese ISBN. Registro cancelado."; break;
        case LIBRO_NO_EXISTE:      cout << "no existe un libro con ese ISBN."; break;
        case NO_ES_NOVELA:         cout << "el libro con ese ISBN no es una novela."; break;
        case AUTOR_NO_EXISTE:      cout << "no existe un autor con esa cedula."; break;
        case SIN_COINCIDENCIAS:    cout << "no hay libros cuyo titulo comience con esa frase."; break;
        case SIN_AUTORES:          cout << "aun no hay autores registrados."; break;
        case EDITORIAL_SIN_LIBROS: cout << "no hay libros de esa editorial."; break;
        default:                   cout << "error desconocido."; break;
    }
    cout << endl;
}

// ---------------------------------------------------------------------
// Opciones del menu (una por requerimiento)
// ---------------------------------------------------------------------

// Req 1
void opRegistrarAutor(CapaLogica &fachada)
{
    TipoError error;
    int ci = leerCedula();
    String nombre = leerTexto("Nombre: ");
    String apellido = leerTexto("Apellido: ");
    fachada.registrarAutor(new Autor(ci, nombre, apellido), error);
    if (error == SIN_ERROR)
        cout << "Autor registrado correctamente." << endl;
    else
        mostrarError(error);
}

// Req 2
void opRegistrarLibro(CapaLogica &fachada)
{
    TipoError error;
    cout << "Tipo de libro: 1) Novela   2) Texto comun   3) Texto escolar" << endl;
    int tipo = leerEntero("Opcion: ", 1, 3);
    String isbn = leerIsbn();
    String titulo = leerTexto("Titulo: ");
    String editorial = leerTexto("Editorial: ");
    float precio = leerPrecio("Precio base: $");

    Libro * l;
    if (tipo == 1)
    {
        String genero = leerGenero();
        l = new Novela(isbn, titulo, editorial, precio, genero);
    }
    else
    {
        String materia = leerTexto("Materia: ");
        Fecha fecha = leerFecha();
        if (tipo == 2)
            l = new Texto(isbn, titulo, editorial, precio, materia, fecha);
        else
        {
            int anio = leerEntero("Anio de escuela (1 a 6): ", 1, 6);
            l = new Escolar(isbn, titulo, editorial, precio, materia, fecha, anio);
        }
    }

    fachada.registrarLibro(l, error); // si el isbn ya existe, la fachada libera el libro
    if (error == SIN_ERROR)
        cout << "Libro registrado correctamente." << endl;
    else
        mostrarError(error);
}

// Req 3
void opAsociarAutor(CapaLogica &fachada)
{
    TipoError error;
    cout << "Datos de la novela:" << endl;
    String isbn = leerIsbn();
    cout << "Datos del autor:" << endl;
    int ci = leerCedula();
    fachada.asociarAutorNovela(ci, isbn, error);
    if (error == SIN_ERROR)
        cout << "Autor asociado a la novela correctamente." << endl;
    else
        mostrarError(error);
}

// Req 4
void opListarPorPrefijo(CapaLogica &fachada)
{
    TipoError error;
    Iterador iter;
    String frase = leerTexto("Frase con la que comienza el titulo: ");
    fachada.listarLibrosPorPrefijo(frase, iter, error);
    if (error == SIN_ERROR)
    {
        while (iter.hayMasObjetos())
        {
            Libro * l = (Libro *) iter.proximoObjeto();
            cout << "ISBN: "; l->getIsbn().print();
            cout << " | Titulo: "; l->getTitulo().print();
            cout << " | Tipo: "; l->tipoLibro().print();
            cout << endl;
        }
    }
    else
        mostrarError(error);
}

// Req 5
void opDetalleLibro(CapaLogica &fachada)
{
    TipoError error;
    Libro * l;
    String isbn = leerIsbn();
    fachada.consultarDetalleLibro(isbn, l, error);
    if (error == SIN_ERROR)
        mostrarDetalleLibro(l);
    else
        mostrarError(error);
}

// Req 6
void opListarAutores(CapaLogica &fachada)
{
    TipoError error;
    Iterador iter;
    fachada.listarAutores(iter, error);
    if (error == SIN_ERROR)
    {
        while (iter.hayMasObjetos())
            mostrarAutor((Autor *) iter.proximoObjeto());
    }
    else
        mostrarError(error);
}

// Req 7
void opRegistrarVenta(CapaLogica &fachada)
{
    TipoError error;
    float importe;
    String isbn = leerIsbn();
    fachada.registrarVentaUnidad(isbn, importe, error);
    if (error == SIN_ERROR)
        cout << "Venta registrada. Importe a cobrar: $" << importe << endl;
    else
        mostrarError(error);
}

// Req 8
void opRecaudacionEditorial(CapaLogica &fachada)
{
    TipoError error;
    float recaudacion;
    String editorial = leerTexto("Editorial: ");
    fachada.recaudacionPorEditorial(editorial, recaudacion, error);
    if (error == SIN_ERROR)
        cout << "Monto total recaudado: $" << recaudacion << endl;
    else
        mostrarError(error);
}

// Req 9
void opUnidadesSuperanPrecio(CapaLogica &fachada)
{
    int novelas, textos, escolares;
    float precio = leerPrecio("Precio base: $");
    fachada.unidadesVendidasSuperanPrecio(precio, novelas, textos, escolares);
    cout << "Unidades vendidas de libros con precio base mayor a $" << precio << ":" << endl;
    cout << "  Novelas:          " << novelas << endl;
    cout << "  Textos comunes:   " << textos << endl;
    cout << "  Textos escolares: " << escolares << endl;
}

// Req 10
void opMasVendidoEditorial(CapaLogica &fachada)
{
    TipoError error;
    Libro * l;
    String editorial = leerTexto("Editorial: ");
    fachada.libroMasVendidoEditorial(editorial, l, error);
    if (error == SIN_ERROR)
    {
        cout << "Libro mas vendido de la editorial:" << endl;
        mostrarDetalleLibro(l);
    }
    else
        mostrarError(error);
}

// ---------------------------------------------------------------------
// Programa principal
// ---------------------------------------------------------------------

void mostrarMenu()
{
    cout << endl;
    cout << "============ LIBRERIA ============" << endl;
    cout << " 1) Registrar autor" << endl;
    cout << " 2) Registrar libro" << endl;
    cout << " 3) Asociar autor a una novela" << endl;
    cout << " 4) Listar libros cuyo titulo comienza con una frase" << endl;
    cout << " 5) Ver detalle de un libro" << endl;
    cout << " 6) Listar autores" << endl;
    cout << " 7) Registrar venta de una unidad" << endl;
    cout << " 8) Recaudacion de una editorial" << endl;
    cout << " 9) Unidades vendidas que superan un precio base" << endl;
    cout << "10) Libro mas vendido de una editorial" << endl;
    cout << " 0) Salir" << endl;
    cout << "==================================" << endl;
}

int main()
{
    CapaLogica fachada;
    int opcion;

    cout << fixed << setprecision(2); // los importes se muestran con 2 decimales

    do
    {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 0, 10);
        if (cin.eof())
            opcion = 0;
        cout << endl;

        switch (opcion)
        {
            case 1:  opRegistrarAutor(fachada); break;
            case 2:  opRegistrarLibro(fachada); break;
            case 3:  opAsociarAutor(fachada); break;
            case 4:  opListarPorPrefijo(fachada); break;
            case 5:  opDetalleLibro(fachada); break;
            case 6:  opListarAutores(fachada); break;
            case 7:  opRegistrarVenta(fachada); break;
            case 8:  opRecaudacionEditorial(fachada); break;
            case 9:  opUnidadesSuperanPrecio(fachada); break;
            case 10: opMasVendidoEditorial(fachada); break;
        }
    } while (opcion != 0);

    cout << "Fin del programa." << endl;
    return 0; // al salir se destruye la fachada y con ella todos los autores y libros
}
