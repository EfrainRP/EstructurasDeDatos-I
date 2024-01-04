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
        ///Atributos
        List<Cancion,5000>* myList;

        ///Metodos Privados
        void newElement();
        void deleteElement();

        void showListMenu();

        void searchAnElement();
        void searchMethod(Cancion&,int cmp(const Cancion&, const Cancion&));

        void sortElements();
        void sortMethod(int cmp(const Cancion&, const Cancion&));

        void displayMenu();

        void enterMenu();
        void clearScreen();
    public:
        ///Constructor
        Menu(List<Cancion,5000>&);

        ///Metodo
        void mainMenu();
    };

#endif // MENU_H_INCLUDED
