#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "List.h"
#include "Cancion.h"

#include <iostream>
#include <conio.h>
#include <iomanip>

class Menu {
    private:
        ///Atributos
        List<Cancion>* myList;

        ///Metodos Privados
        void newElement();
        void deleteElement();

        void showListMenu();

        void findAnElement();

        void displayMenu();

        void enterMenu();
        void clearScreen();
    public:
        ///Constructor
        Menu(List<Cancion>&);

        ///Metodo
        void mainMenu();
    };

#endif // MENU_H_INCLUDED
