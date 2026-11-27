#include "Libros.h"


// METODOS AUXILIARES PRIVADOS

int Libros :: h(String isbn){
// Calcula la posicion en el Hash procesando el ISBN digito a digito,
// conservando el resto parcial para evitar desbordamientos. 

/*  Explicacion en pseudocodigo
    posicion = 0

    PARA cada caracter del ISBN
        digito = convertir caracter a número

        posicion = (posicion * 10 + digito) MOD 500
    FIN PARA

    RETORNAR posicion*/

    int posicion = 0;
    
    for(int i=0; i<isbn.largo(); i++)
    
        posicion = (posicion * 10 + (isbn.caracter(i) - '0')) % B;
    
    return posicion;

}

void Libros :: crearLista(Nodo * &L){
    L = NULL;
}
        
void Libros :: destruirLista(Nodo * &L){
    Nodo * aux = L;
    
    while(aux != NULL){
        L = aux->sig;
        delete aux->info;
        delete aux;
        aux = L;
    }
    L = NULL;
}
        
bool Libros :: perteneceLista(Nodo * L, String isbn){
    bool existe = false;
    
    while(!existe && L != NULL){
        
        if( L->info->getIsbn() == isbn) //practico 5 ejercicio 4
            existe = true;
        else
            L = L->sig;
    }
    return existe;
}
        
void Libros :: insFrontEnLista(Nodo * &L, Libro * libro){
    Nodo * aux = new Nodo;
    aux->info = libro;
    aux->sig = L;
    L = aux;

}
       
Libro * Libros :: obtenerEnLista(Nodo * L, String isbn){
    while(L != NULL && !(L->info->getIsbn() == isbn))
        L = L->sig;

    if (L != NULL)
        return L->info;
    else
        return NULL;
}

// METODOS PUBLICOS

Libros :: Libros(){
    for(int i = 0; i < B; i++)
        crearLista(Hash[i]);
}

Libros :: ~Libros(){
    for(int i = 0; i < B; i++)
        destruirLista(Hash[i]);
}

bool Libros :: member(String isbn){
    int cubeta = h(isbn);
    return perteneceLista(Hash[cubeta], isbn);
}

// precondicion: no existe otro libro con el mismo isbn
void  Libros :: insert(Libro * libro){
    int cubeta = h(libro->getIsbn());
    insFrontEnLista(Hash[cubeta], libro);
}

Libro * Libros :: find(String isbn){
    int cubeta = h(isbn);
    return obtenerEnLista(Hash[cubeta], isbn);
}

bool Libros:: esVacio(){
    for(int i = 0; i < B; i++)
        if(Hash[i] != NULL)
            return false;
    return true;
}

void Libros :: listarPorPrefijoTitulo(String frase, Iterador &iter){
    for(int i = 0; i < B; i++){
        Nodo * aux = Hash[i];
        while(aux!=NULL){
            String titulo = aux->info->getTitulo();
            bool coincide = frase.largo() <= titulo.largo();

            for (int j = 0; coincide && j < frase.largo(); j++){
                if(titulo.caracter(j) != frase.caracter(j))
                    coincide = false;
                }
            
            if(coincide)
                iter.insertar(aux->info);
            
            aux = aux->sig;
        }
    }
}

void Libros :: recaudacionEditorial(String editorial, float &recaudacion, int &cantidad){
    recaudacion = 0;
    cantidad = 0;

    for(int i = 0; i < B; i++){
        Nodo * aux = Hash[i];
        while(aux != NULL){
            Libro * libro = aux->info;
            if(libro->getEditorial() == editorial)
            {
                recaudacion += libro->getUnidadesVendidas() * libro->precioVenta();
                cantidad ++;
            }
        aux = aux->sig;
        }
    }
}

void Libros :: unidadesVendidasSuperanPrecio(float precio, int &novelas, int &textos, int &escolares){
    novelas = 0;
    textos = 0;
    escolares = 0;

    for(int i = 0; i < B; i++){
        Nodo * aux = Hash[i];
        while(aux!=NULL){
            Libro * libro = aux->info;
            if(libro->getPrecioBase()>precio){
                String tipo = libro->tipoLibro();
                if (tipo == "Novela")
                    novelas += libro->getUnidadesVendidas();
                else if (tipo == "Texto")
                    textos += libro->getUnidadesVendidas();
                else if (tipo == "Escolar")
                    escolares += libro->getUnidadesVendidas();
            }
            aux = aux->sig;
        }
    }

}

Libro * Libros :: libroMasVendidoEditorial(String editorial){
    Libro * mayor = NULL;

    for(int i = 0; i < B; i++){
        Nodo * aux = Hash[i];
        while(aux!= NULL){
            Libro * libro = aux->info;
            if(libro->getEditorial() == editorial){
                if(mayor == NULL || libro->getUnidadesVendidas() > mayor->getUnidadesVendidas())
                mayor = libro;
            }
        aux = aux->sig;
        }
    }
    return mayor;
}