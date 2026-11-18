#ifndef FECHA_H
#define FECHA_H

class Fecha {
    private:
        int dia, mes, anio;
        void diaSiguiente();
    public:

    // Constructores
        Fecha();
        Fecha(int d, int m, int a);
        Fecha(const Fecha &f2);
        ~Fecha();
    // Selectores
        int getDia();
        int getMes();
        int getAnio();
    // Validacion
        bool esValida();
    // Sobrecarga de operadores
        
        bool operator==(Fecha f2);
        bool operator<(Fecha f2);

        Fecha operator++();
        Fecha operator++(int);

        Fecha operator+(int cantDias);
        int operator-(Fecha f2);

};

#endif
