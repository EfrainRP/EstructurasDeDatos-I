///Efrain Robles Pulido
#include "Menu.h"
#include "Integer.h"

#include <iostream>

int main() {
    List<Integer,100000 > listA, listB;
    Menu interfaz(listA, listB);
    interfaz.mainMenu();
    return 0;
    }
