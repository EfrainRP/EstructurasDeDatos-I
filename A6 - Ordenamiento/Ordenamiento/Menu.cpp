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
        cout << endl << "\t\tOcurrio un error" << endl;
        cout << "\t\tError de sistema:" << ex.what() << endl;
        cout << "\t\tCancion NO Agregada" << endl;
        enterMenu();
        return;
        }

    cout << "\t\tCancion Agregada" << endl;

    }

void Menu::deleteElement() {
    int pos;
    cout<< "Ingrese la posicion de la cancion a eliminar: ";
    cin>>pos;

    try {
        myList->deleteElement(pos);
        }
    catch(ListException ex) {
        cout << "Ocurrio un error" << endl;
        cout << "Error de sistema:" << ex.what() << endl;
        enterMenu();
        return;
        }
    cout<<"\t\tCancion eliminado "<<endl;
    }


void Menu::displayMenu() {
    cout<< "\t\t MENU " <<endl;
    cout<< "\t[A]ñadir nuevos canciones: " <<endl;
    cout<< "\t[E]liminar cancion: " <<endl;
    cout<< "\t[M]ostrar toda la lista" <<endl;
    cout<< "\t[B]uscar" <<endl;
    cout<< "\t[O]rdenar" <<endl;
    cout<< "\t[S]alir " <<endl;
    cout<< "\tSelecciona una opcion (A,E,M,B,O,S):  ";
    }

void Menu::showListMenu() {
    clearScreen();
    string myStr;
    myStr += "POSICION | ";
    myStr += "NOMBRE DE LA CANCION";
    myStr.resize (36,' ');
    myStr += " | ";
    myStr += "AUTOR";
    myStr.resize (57,' ');
    myStr += " | ";
    myStr += "INTERPRETE";
    myStr.resize (79,' ');
    myStr += " | ";
    myStr += "RANKING";
    myStr.resize (89,' ');
    myStr += " | ";
    myStr += "NOMBRE DE ARCHIVO";
    myStr.resize (121,' ');
    myStr += " | ";
    /*cout << setw(10) << "POSICION |"<< setw(27) << "NOMBRE DE LA CANCION |"<< setw(21) << "AUTOR |"
         << setw(22) << "INTERPRETE |"<< setw(10) << "RANKING |"<< setw(32) << "NOMBRE DE ARCHIVO |"
         << endl;*/
    cout<<myStr<<endl;

    cout<< myList->toString()<<endl<<endl;
    }

void Menu::searchAnElement() {
    string myString;
    char myChar;

    Nombre newInterprete;
    Cancion newElement;

    do {
        clearScreen();
        cout<<"\tIngrese tipo de busqueda"<<endl;
        cout<<"Buscar por Nombre de la [C]ancion  /  Nombre del [I]nterprete  / [R]egresar al menu:  ";
        cin>> myChar;
        cin.ignore();
        myChar = toupper(myChar);

        switch (myChar) {
            case 'C'://Busqueda por Cancion
                cout<<endl<<"Ingrese la cancion a buscar: ";
                getline(cin,myString);
                newElement.setCancion(myString);

                searchMethod(newElement,Cancion::compareByCancion);
                break;

            case 'I'://Busqueda por Interprete
                cout<<endl<<"Ingrese primer nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setFirstName(myString);
                cout<<endl<<"Ingrese segundo nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setLastName(myString);

                newElement.setInterprete(newInterprete);

                searchMethod(newElement,Cancion::compareByInterprete);
                break;

            case 'R':
                break;

            default:
                cout<<endl<<"ERROR, Ingrese opcion valida    "<<endl;
            }
        enterMenu();
        }
    while(myChar != 'R');
    }

void Menu::searchMethod(Cancion& e, int cmp(const Cancion&, const Cancion&)) {
    char myChar;
    int pos(0);
    do {
        cout<<endl<<"Ingrese metodo de busqueda deseado [L]ineal  /  [B]inaria:  ";
        cin>> myChar;
        cin.ignore();
        myChar = toupper(myChar);

        switch(myChar) {
            case 'L'://Busqueda Lineal
                cout<<endl<<"\tBusqueda Lineal"<<endl<<endl;
                if((pos = myList->findElementLinear(e, cmp)) != -1) {
                    e = myList->retrieve(pos);
                    cout<<"La cancion esta en la posicion: "<<pos<<"\t/      Archivo:   "<<e.getArchivo()<<endl<<endl;
                    }
                else {
                    cout<< "\tNo existe la cancion "<<endl;
                    }
                break;
            case 'B'://Busqueda Binaria
                cout<<endl<<"Busqueda Binaria"<<endl<<endl;
                if((pos = myList->findElementBinary(e, cmp)) != -1) {
                    e = myList->retrieve(pos);
                    cout<<"La cancion esta en la posicion: "<<pos<<"\t/      Archivo:    "<<e.getArchivo()<<endl<<endl;
                    }
                else {
                    cout<< "\tNo existe la cancion "<<endl;
                    }
                break;
            default:
                cout<<endl<<"ERROR, Ingrese opcion valida    "<<endl;
            }
        }
    while((myChar != 'L') and (myChar != 'B'));
    }

void Menu::sortElements() {
    char myChar;
    do {
        clearScreen();
        cout<<"\tIngrese tipo de ordenamiento"<<endl;
        cout<<"Ordenar por Nombre de la [C]ancion  /  Nombre del [I]nterprete  / [R]egresar al menu:  ";
        cin>> myChar;
        cin.ignore();
        myChar = toupper(myChar);

        switch(myChar) {
            case 'C'://Ordenamiento por Cancion
                sortMethod(Cancion::compareByCancion);
                showListMenu();
                //sortMethod(myCharA);
                break;
            case 'I'://Ordenamiento por Interprete
                sortMethod(Cancion::compareByInterprete);
                showListMenu();
                //sortMethod(myCharA);
                break;

            case 'R':
                break;

            default:
                cout<<endl<<"ERROR, Ingrese opcion valida    "<<endl;
            }
        enterMenu();
        }
    while(myChar != 'R');
    }

void Menu::sortMethod(int cmp(const Cancion&, const Cancion&)) {
    char myChar;
    do {
        cout<<endl<<"Ingrese metodo de ordenamiento deseado [B]ubbleSort / [I]nsertSort / [S]electSort / [Sh]ellSort: ";
        cin>> myChar;
        cin.ignore();
        myChar = toupper(myChar);
        switch(myChar) {
            case 'B'://BUBLESORT
                cout<<endl<<"\tBubleSort"<<endl<<endl;
                myList->sortDataBubble(cmp);
                break;

            case 'I'://INSERTSORT
                cout<<endl<<"\tInsertSort"<<endl<<endl;
                myList->sortDataInsert(cmp);
                break;

            case 'S'://SELECTSORT
                cout<<endl<<"\tSelectSort"<<endl<<endl;
                myList->sortDataSelect(cmp);
                break;

            case 'SH'://SHELLSORT
                cout<<endl<<"\tShellSort"<<endl<<endl;
                myList->sortDataShell(cmp);
                break;

            default:
                cout<<endl<<"\tERROR, Ingrese opcion valida    "<<endl;
                myChar = 'E';
                enterMenu();
            }
        }
    while(myChar == 'E');
    }

/*void Menu::sortMethod(const char& Form) {
    char myCharB;
    cout<<endl<<"Ingrese metodo de ordenamiento deseado [B]ubbleSort \ [I]nsertSort \ [S]electSort \ [Sh]ellSort: ";
    cin>> myCharB;
    cin.ignore();
    myCharB = toupper(myCharB);
        switch (Form){
        case 'C':
            switch(myCharB) {
                case 'B'://BUBLESORT
                    cout<<endl<<"\tBubleSort"<<endl<<endl;
                    myList->sortDataBubble(Cancion::compareByCancion);
                    break;

                case 'I'://INSERTSORT
                    cout<<endl<<"\tInsertSort"<<endl<<endl;
                    myList->sortDataInsert(Cancion::compareByCancion);
                    break;

                case 'S'://SELECTSORT
                    cout<<endl<<"\tSelectSort"<<endl<<endl;
                    myList->sortDataSelect(Cancion::compareByCancion);
                    break;

                case 'SH'://SHELLSORT
                    cout<<endl<<"\tShellSort"<<endl<<endl;
                    myList->sortDataShell(Cancion::compareByCancion);
                    break;

                default:
                    cout<<endl<<"\tERROR, Ingrese opcion valida    "<<endl;
                    enterMenu();
                }
                break;
        case 'I':
            switch(myCharB) {
                case 'B'://BUBLESORT
                    cout<<endl<<"\tBubleSort"<<endl<<endl;
                    myList->sortDataBubble(Cancion::compareByInterprete);
                    break;

                case 'I'://INSERTSORT
                    cout<<endl<<"\tInsertSort"<<endl<<endl;
                    myList->sortDataInsert(Cancion::compareByInterprete);
                    break;

                case 'S'://SELECTSORT
                    cout<<endl<<"\tSelectSort"<<endl<<endl;
                    myList->sortDataSelect(Cancion::compareByInterprete);
                    break;

                case 'SH'://SHELLSORT
                    cout<<endl<<"\tShellSort"<<endl<<endl;
                    myList->sortDataShell(Cancion::compareByInterprete);
                    break;

                default:
                    cout<<endl<<"\tERROR, Ingrese opcion valida    "<<endl;
                    enterMenu();
                }
            break;

                default:
                   cout<<endl<<"\tERROR, Ingrese opcion valida    "<<endl;
                    enterMenu();

        }
        cout<<"Ordenado"<<endl<<endl;
        showListMenu();
        enterMenu();
    }*/

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
                searchAnElement();
                break;

            case 'O':
                sortElements();
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


