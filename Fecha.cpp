 #include "Fecha.h"


    // Auxiliar 

    int cantDiasDelMes(int m, int a) {
        switch (m) 
            { case 4: case 6: case 9: case 11: 
                return 30; 
            case 2: // Año bisiesto: divisible entre 4 y no 100, o divisible entre 400 
                if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) 
                    return 29; 
                else 
                    return 28; 
            default: return 31;
            } 
        }
    // Constructores
        
        Fecha::Fecha(){
            dia = 1; mes = 1; anio = 2000;
        }
        
        Fecha::Fecha(int d, int m, int a){
            dia = d; mes = m; anio = a;
            if(!esValida()){
                dia = 1; mes = 1; anio = 2000;
            }
        }
        
        Fecha::Fecha(const Fecha &f2){
            dia = f2.dia;
            mes = f2.mes; 
            anio = f2.anio;
        }

        Fecha::~Fecha(){}

    // Selectores
        int Fecha::getDia() {return dia; }
        int Fecha::getMes() {return mes; }
        int Fecha::getAnio() {return anio; }
    
    // Validacion
        bool Fecha::esValida() {
            if (anio < 1 || mes < 1 || mes > 12 || dia < 1 || dia > 31)
                return false;
            return dia <= cantDiasDelMes(mes, anio);
        }
    // Sobrecarga de operadores
        
        bool Fecha::operator==(Fecha f2){
            return (dia == f2.dia && mes == f2.mes && anio == f2.anio);
        }

        bool Fecha::operator<(Fecha f2){
            if (anio != f2.anio)
                return anio < f2.anio;
            if (mes != f2.mes)
                return mes < f2.mes;
            return dia < f2.dia;
        }

        Fecha Fecha::operator++(){
            diaSiguiente();
            return *this;
        }

        Fecha Fecha::operator++(int){
            Fecha temp(*this);
            diaSiguiente();
            return temp;
        }

        Fecha Fecha::operator+(int cantDias){
            Fecha fres = *this;
            for (int i = 0; i < cantDias; i++){
                fres.diaSiguiente();
            }
            return fres;
        }
        
        int Fecha::operator-(Fecha f2){
            if (*this == f2)
                return 0;
            
            if (*this < f2){
                Fecha aux = *this;
                int dif = 0;
                while(aux < f2){
                    aux.diaSiguiente();
                    dif++;
                }
                return (dif*-1);
            }else{
                Fecha aux = f2;
                int dif = 0;
                while(aux < *this){
                    aux.diaSiguiente();
                    dif++;
                }
                return dif;
            }
        }

    // metodo privado que modifica el *this
        void Fecha::diaSiguiente(){
            dia++;
            if(dia > cantDiasDelMes(mes, anio)){
                dia = 1;
                mes ++;
                if(mes > 12){
                    mes = 1;
                    anio++;
                }
            }
        }

