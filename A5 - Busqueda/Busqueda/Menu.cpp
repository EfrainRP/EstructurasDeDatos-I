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
    cin.ignore();
    newCancion.setRanking(myInt);

    //Archivo .MP3
    cout << "Ingrese el nombre del archivo MP3: ";
    getline(cin, myStr);
    myStr+= ".mp3";
    newCancion.setArchivo(myStr);

    if ((myList->getLastPos())> -1) {
        cout<< "Ingrese posicion deseada, (Ultima Posicion es "<<myList->getLastPos()<<"): ";
        cin>>myInt;
        }
    else {
        myInt = myList->getLastPos();
        }

    try {
        myList->insertElement(myInt,newCancion);
        }
    catch(ListException ex) {
        cout << "Ocurrio un error" << endl;
        cout << "Error de sistema:" << ex.what() << endl;
        enterMenu();
        return;
        }

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
    cout<< "\t[A]ñadir nuevos canciones: " <<endl;
    cout<< "\t[E]liminar cancion: " <<endl;
    cout<< "\t[M]ostrar toda la lista" <<endl;
    cout<< "\t[B]usqueda" <<endl;
    cout<< "\t[S]alir " <<endl;
    cout<< "\tSelecciona una opcion (A,E,M,B,S):  ";
    }

void Menu::showListMenu() {
    clearScreen();
    cout << setw(13) << "POSICION | "<< setw(37) << "NOMBRE DE LA CANCION | "<< setw(37) << "AUTOR |"
         << setw(38) << "INTERPRETE |"<< setw(9) << "RANKING |"<< setw(38) << "NOMBRE DE ARCHIVO |"
         << endl;
    cout<< myList->toString()<<endl<<endl;
    }

void Menu::findAnElement() {
    string myString;
    char myCharA, myCharB;
    int pos(0);

    Nombre newInterprete;
    Cancion element;

    do {
        clearScreen();
        cout<<"\tIngrese tipo de busqueda"<<endl;
        cout<<"Buscar por Nombre de la [C]ancion  /  Nombre del [I]nterprete  / [R]egresar al menu:  ";
        cin>> myCharA;
        cin.ignore();
        myCharA = toupper(myCharA);

        switch (myCharA) {
            case 'C'://Busqueda por Cancion
                cout<<endl<<"Ingrese la cancion a buscar: ";
                getline(cin,myString);
                element.setCancion(myString);

                do {
                    cout<<endl<<"Ingrese metodo de busqueda deseado [L]ineal  /  [B]inaria:  ";
                    cin>> myCharB;
                    cin.ignore();
                    myCharB = toupper(myCharB);

                    switch(myCharB) {
                        case 'L'://Busqueda Lineal por Cancion
                            cout<<endl<<"\tBusqueda Lineal"<<endl<<endl;
                            if((pos = myList->findElementLinear(element, Cancion::compareByCancion)) != -1) {
                                element = myList->retrieve(pos);
                                cout<<"La cancion esta en la posicion: "<<pos<<"\t/      Archivo:   "<<element.getArchivo()<<endl<<endl;
                                }
                            else {
                                cout<< "\tNo existe la cancion "<<endl;
                                }
                            break;
                        case 'B'://Busqueda Binaria por Cancion
                            cout<<endl<<"Busqueda Binaria"<<endl<<endl;
                            if((pos = myList->findElementBinary(element, Cancion::compareByCancion)) != -1) {
                                element = myList->retrieve(pos);
                                cout<<"La cancion esta en la posicion: "<<pos<<"\t/      Archivo:    "<<element.getArchivo()<<endl<<endl;
                                }
                            else {
                                cout<< "\tNo existe la cancion "<<endl;
                                }
                            break;
                        default:
                            cout<<endl<<"ERROR, Ingrese opcion valida    "<<endl;
                            enterMenu();
                        }
                    }
                while((myCharB != 'L') and (myCharB != 'B'));
                break;

            case 'I'://Busqueda por Interprete
                cout<<endl<<"Ingrese primer nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setFirstName(myString);
                cout<<endl<<"Ingrese segundo nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setLastName(myString);

                element.setInterprete(newInterprete);

                do {
                    cout<<endl<<"Ingrese metodo de busqueda deseado [L]ineal  /  [B]inaria:  ";
                    cin>> myCharB;

                    cin.ignore();
                    myCharB = toupper(myCharB);

                    switch(myCharB) {
                        case 'L'://Busque Lineal por Interprete
                            cout<<endl<<"\tBusqueda Lineal"<<endl<<endl;
                            if((pos = myList->findElementLinear(element, Cancion::compareByInterprete)) != -1) {
                                element = myList->retrieve(pos);
                                cout<<"La cancion esta en la posicion: "<<pos<<"\t/    Archivo:    "<<element.getArchivo()<<endl<<endl;
                                }
                            else {
                                cout<<"\tNo existe la cancion "<<endl;
                                }
                            break;
                        case 'B'://Busqueda Binaria por Interprete
                            cout<<endl<<"Busqueda Binaria"<<endl<<endl;
                            if((pos = myList->findElementBinary(element, Cancion::compareByInterprete)) != -1) {
                                element = myList->retrieve(pos);
                                cout<<"La cancion esta en la posicion: "<<pos<<"\t/     Archivo:   "<<element.getArchivo()<<endl<<endl;
                                }
                            else {
                                cout<<"\tNo existe la cancion "<<endl;
                                }
                            break;
                        default:
                            cout<<endl<<"ERROR, Ingrese opcion valida    "<<endl;
                            enterMenu();
                        }
                    }
                while((myCharB != 'L') and (myCharB != 'B'));
                break;

            case 'R':
                break;

            default:
                cout<<endl<<"ERROR, Ingrese opcion valida    "<<endl;
            }
        enterMenu();
        }
    while(myCharA != 'R');
    }

void Menu::enterMenu() {
    cout<< endl<< "Presiona cualquier tecla para continuar";
    getch();
    }


void Menu::clearScreen() {
    system("cls");
    }

//Constructores
Menu::Menu(List<Cancion,3000>& _list): myList(&_list) {}

//Metodo
void Menu::mainMenu() {
    char opc, opcContinue;

    do {
        showListMenu();
        displayMenu();
        cin>> opc;
        cin.ignore();
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
                break;

            case 'B':
                findAnElement();
                break;

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


