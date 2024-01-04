#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "AVL_BTree.h"
#include "Integer.h"

#include <iostream>
#include <random>
#include <chrono>
#include <functional>

class Menu {
    private:
        ///Atributos
        AVL_BTree<Integer>* myTree;

    public:
        ///Constructor
        Menu(AVL_BTree<Integer>&);

        ///Metodo publico
        void mainMenu();
    };


#endif // MENU_H_INCLUDED
