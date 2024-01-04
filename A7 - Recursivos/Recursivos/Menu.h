#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "List.h"
#include "Integer.h"

#include <iostream>
#include <random>
#include <chrono>
#include <conio.h>
#include <functional>


class Menu {
    private:
        ///Atributos
        List<Integer,100000>* myListA,*myListB;

        ///Metodos Privados
        void InputData();
        void stateList();
        void sortData();
        void enterMenu();

    public:
        ///Constructor
        Menu(List<Integer,100000>&, List<Integer,100000>&);

        ///Metodo publico
        void mainMenu();
    };

#endif // MENU_H_INCLUDED
