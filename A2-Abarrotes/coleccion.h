#ifndef COLECCION_H_INCLUDED
#define COLECCION_H_INCLUDED

#include "producto.h"
#include "Fecha.h"
#include <string>

class Coleccion {
    private:
        Producto inventario[500];
        int indexInventario;

    public:
        Coleccion();//Constructores
        Coleccion(const Coleccion&);

        int getIndexInventario() const;
        void setIndexInventario(const int& indice);

        std::string toString(const int& index) const;//Regresa los valores como cadena

        //Metodos
        void agregarProducto(const Producto& );
        int buscarProducto(const std::string&) const;
        void incrementaExistencia(const int&, const int&);
        void decrementaExistencia(const int&, const int&);

    };


#endif // COLECCION_H_INCLUDED
