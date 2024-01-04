#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "BTree.h"
#include "Integer.h"

#include <iostream>
#include <random>
#include <chrono>
#include <conio.h>
#include <functional>

class Menu {
    private:
        ///Atributos
        BTree<Integer>* myBTree;

        ///Metodos Privados
        void enterMenu();

    public:
        ///Constructor
        Menu(BTree<Integer>&);

        ///Metodo publico
        void mainMenu();
    };


#endif // MENU_H_INCLUDED
