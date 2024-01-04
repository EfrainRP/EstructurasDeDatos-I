#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "List.h"
#include "Cancion.h"

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>

class Menu {
    private:
        //Atributos
        List<Cancion,3000>* myList;

        //Metodos Privados
        void newElement();
        void deleteElement();

        void showListMenu();

        void findAnElement();

        void displayMenu();

        void enterMenu();
        void clearScreen();
    public:
        //Constructor
        Menu(List<Cancion,3000>&);

        //Metodo
        void mainMenu();
    };

#endif // MENU_H_INCLUDED
