#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include "Fecha.h"
#include <string>

class Producto {
    private:
        std::string codigoBarrasP;
        std::string nombreP;
        float pesoP;
        Fecha fechaIn;
        float precioMayoreoP;
        float precioMenudeoP;
        int existA;

    public:
        Producto(); //Constructores
        Producto(const Producto&);

        std::string getcodigoBarrasP() const;
        std::string getNombreP() const;
        float getPesoP() const;
        Fecha getFechaIn() const;
        float getPrecioMayoreoP() const;
        float getPrecioMenudeoP() const;
        int getExistP() const;

        std::string toString() const;//Regresa los valores como cadena

        void setcodigoBarrasP(const std::string&);
        void setNombreP(const std::string&);
        void setPesoP(const float&);
        void setFechaIn(const Fecha&);
        void setPrecioMayoreoP(const float&);
        void setPrecioMenudeoP(const float&);
        void setExistP(const int&);

        Producto& operator = (const Producto&);//Para asignar el valor entrante a nuestro objeto

    };

#endif // PRODUCTO_H_INCLUDED
