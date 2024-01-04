#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Lista.h"
#include "Cancion.h"
#include <iostream>
#include <conio.h>

class Menu {
    private:
        //Atributos
        Lista<Cancion,50>* myList;/*Se define los tipos
    de datos de la plantilla, el tipo de variable y el
    tamaño del arreglo*/

        //Metodos Privados
        void newElement();
        void deleteElement();

        void showListMenu();
        void displayMenu();

        void enterMenu();
        void clearScreen();
    public:
        //Constructor
        Menu(Lista<Cancion,50>&);

        //Metodo
        void mainMenu();
    };

#endif // MENU_H_INCLUDED
