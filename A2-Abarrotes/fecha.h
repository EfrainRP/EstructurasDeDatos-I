#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <string>

class Fecha {
    private:
        int dia, mes, anio;

    public:
        Fecha();//Constructores
        Fecha(const Fecha&);

        int getDia()const;
        int getMes()const;
        int getAnio()const;

        std::string toString() const;//Funcion para pasar variables a cadena

        void setDia(const int&);
        void setMes(const int&);
        void setAnio(const int&);
    };

#endif // FECHA_H_INCLUDED
