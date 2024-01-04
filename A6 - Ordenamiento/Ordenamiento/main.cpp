/*Efrain Robles Pulido*/
#include "Menu.h"
#include <iostream>

using namespace std;

int main() {
    List<Cancion,3000> newList;
    Menu interfaz(newList);
    interfaz.mainMenu();
    return 0;
    }
