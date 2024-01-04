/*Efrain Robles Pulido*/
#include "Menu.h"
#include <iostream>

using namespace std;

int main() {
    Lista<Cancion,50> newList;
    Menu interfaz(newList);
    interfaz.mainMenu();
    return 0;
    }
