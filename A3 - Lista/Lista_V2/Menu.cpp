#include "Menu.h"

using namespace std;

//Metodos privados
void Menu::newElement() {
    clearScreen();
    string myStr;
    int myInt;
    Nombre newNombre;
    Cancion newCancion;

    cout << "\n\t Agregue Cancion" << endl;
    //Datos de la cancion
    cout << "Ingrese nombre de la cancion: ";
    cin.ignore();
    getline(cin, myStr);
    newCancion.setCancion(myStr);

    //Datos del nombre del autor
    cout << "Ingrese primer nombre del autor: ";
    getline(cin, myStr);
    newNombre.setFirstName(myStr);
    cout << "Ingrese segundo nombre del autor: ";
    getline(cin, myStr);
    newNombre.setLastName(myStr);
    newCancion.setAutor(newNombre);

    //Datos del nombre del interprete
    cout << "Ingrese primer nombre del interprete: ";
    getline(cin, myStr);
    newNombre.setFirstName(myStr);
    cout << "Ingrese segundo nombre del interprete: ";
    getline(cin, myStr);
    newNombre.setLastName(myStr);
    newCancion.setInterprete(newNombre);

    //Posicion del ranking
    cout << "Ingrese posicion en el ranking: ";
    cin >> myInt;
    newCancion.setRanking(myInt);


    if ((myList->getLastPos())> -1) {
        cout<< "Ingrese posicion deseada, (Ultima Posicion es "<<myList->getLastPos()<<"): ";
        cin>>myInt;
        }
    else {
        myInt = myList->getLastPos();
        }
    myList->insertElement(myInt,newCancion);
    cout << "\t\tCancion Agregada" << endl;

    }

void Menu::deleteElement() {
    int pos;
    cout<< "Ingrese la posicion de la cancion a eliminar: ";
    cin>>pos;
    myList->deleteElement(pos);
    cout<<"\t\tCancion eliminado "<<endl;
    }


void Menu::displayMenu() {
    cout<< "\t\t MENU " <<endl;
    cout<< "\t[A]ñadir nuevos cancion: " <<endl;
    cout<< "\t[E]liminar cancion: " <<endl;
    cout<< "\t[M]ostrar toda la lista" <<endl;
    cout<< "\t[S]alir " <<endl;
    cout<< "\tSelecciona una opcion (A,E,M,S):  ";
    }

void Menu::showListMenu() {
    clearScreen();
    cout<< "   POSICION|\t\t\t\t CANCION|\t\t\t\t AUTOR|\t\t\t          INTERPRETE| RANKING "<<endl;
    cout<< myList->toString()<<endl<<endl;
    }

void Menu::enterMenu() {
    cout << "\nPresiona cualquier tecla para continuar ";
    getch();//  Detecta un teclazo
    }


void Menu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    }

//Constructores
Menu::Menu(Lista<Cancion,50>& _list): myList(&_list) {}

//Metodo
void Menu::mainMenu() {
    char opc, opcContinue;

    do {
        showListMenu();
        displayMenu();
        cin>> opc;
        cin.ignore();/*Se usa despues de capturar una variable
                    de un solo caracter, se limpia el buffer*/
        opc = toupper(opc);

        switch (opc) {
            case 'A':
                do {
                    showListMenu();
                    displayMenu();
                    newElement();
                    cout<< "Ingresar otra cancion [S]/[N]: ";
                    cin>> opcContinue;
                    opcContinue = toupper(opcContinue);
                    enterMenu();
                    }
                while(opcContinue != 'N');
                break;

            case 'E':
                showListMenu();
                if(!(myList->isEmpty())) {
                    deleteElement();
                    showListMenu();
                    }
                else {
                    cout<< "\nLISTA VACIA, debe ingresar canciones" <<endl;
                    }
                enterMenu();
                break;

            case 'M':
                cout<<endl<<endl;
                showListMenu();
                enterMenu();

            case 'S':
                cout << "\n\tFIN del programa" << endl;
                break;

            default:
                cout<< "ERROR, ingrese opcion valida" <<endl;
                enterMenu();
            }
        }
    while (opc!='S');
    }


