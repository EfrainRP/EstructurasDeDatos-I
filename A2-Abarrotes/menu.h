#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "fecha.h"
#include "producto.h"
#include "coleccion.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cctype>

class Menu {
    private:
        //Metodos
        int buscarIdProducto(const Coleccion&);
        Producto agregarProductoNuevo() const;
        void imprimirMenu()const;

        void limpiarPantalla()const;
        void enterMenu()const;
    public:
        //Constructor
        Menu();
    };

#endif // MENU_H_INCLUDED
