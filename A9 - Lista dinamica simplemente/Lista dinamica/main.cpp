/*Efrain Robles Pulido*/
#include "Menu.h"
#include <iostream>

using namespace std;

int main() {
    List<Cancion> newList;
    Menu interfaz(newList);
    interfaz.mainMenu();
    return 0;
    }
