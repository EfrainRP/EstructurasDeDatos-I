/*Efrain Robles Pulido*/
#include "Menu.h"
#include "Integer.h"
#include <iostream>

using namespace std;

int main() {
    BTree<Integer> myTree;
    Menu interfaz(myTree);
    interfaz.mainMenu();
    return 0;
    }
