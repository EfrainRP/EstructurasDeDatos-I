/*Efrain Robles Pulido*/
#include "Menu.h"
#include <iostream>

using namespace std;

int main() {
    List<Cancion,5000> myList;
    Menu interfaz(myList);
    interfaz.mainMenu();
    return 0;
    }
