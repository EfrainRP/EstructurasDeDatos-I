#include "Menu.h"

using namespace std;

///Metodos privados
void Menu::newElement() {
    clearScreen();
    string myStr;
    int myInt;
    char myChar;
    Nombre newNombre;
    Cancion newCancion, temp;
    List<Cancion>::Position insertPoint;//Direccion de memoria

    cout << "\n\t Agregue Cancion" << endl;
    //Datos de la cancion
    cout << "Ingrese nombre de la cancion: ";
    cin.sync();
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
    cin.sync();
    newCancion.setRanking(myInt);

    //Archivo .MP3
    cout << "Ingrese el nombre del archivo MP3: ";
    getline(cin, myStr);
    myStr+= ".mp3";
    newCancion.setArchivo(myStr);

    try {
        if (myList->isEmpty()) {//Cuando es el primer elemento de la lista
            myList->insertData(nullptr,newCancion);//Inserta despues del punto de referencia
            cout << "\t\t\tCancion Agregada..." << endl;
            }
        else {
            cout<<"Insertar en [P]rincipio / [E]legir posicion / [F]inal : ";
            cin>>myChar;
            cin.ignore();
            myChar = toupper(myChar);

            switch(myChar) {
                case 'P':
                    myList->insertData(nullptr,newCancion);//Inserta despues del punto de referencia
                    cout << "\t\t\tCancion Agregada..." << endl;
                    break;
                case 'E':
                    cout<< "Ingrese la cancion a partir de la cual se agregara: ";
                    getline(cin, myStr);
                    temp.setCancion(myStr);
                    if((insertPoint = myList->findDataLinear(temp,Cancion::compareByCancion)) != nullptr) {
                        myList->insertData(insertPoint,newCancion);//Inserta despues del punto de referencia
                        cout << "\t\t\tCancion Agregada..." << endl;
                        }
                    else {
                        cout << "\t\t\tCancion No Encontrada"
                             <<endl<<"\t\tCancion No Agregada..."<<endl;
                        }
                    break;
                case 'F':
                    myList->insertData(myList->getLastPos(),newCancion);//Inserta despues del punto de referencia
                    cout << "\t\t\tCancion Agregada..." << endl;
                    break;
                }
            }
        }
    catch(List<Cancion>::ListException ex) {
        cout << "Ocurrio un error" << endl;
        cout << "Error de sistema:" << ex.what() << endl;
        enterMenu();
        return;
        }
    }

void Menu::deleteElement() {
    Cancion newCancion;
    string myStr;
    List<Cancion>::Position deletePoint;

    cout<< "Ingrese la cancion a eliminar: ";
    cin.sync();
    getline(cin, myStr);
    newCancion.setCancion(myStr);
    try {
        if((deletePoint = myList->findDataLinear(newCancion,Cancion::compareByCancion)) != nullptr) {
            myList->deleteData(deletePoint);
            cout<<"\n\t\t\tCancion eliminado... "<<endl;
            }
        else {
            cout << "\nNo existe la cancion..." << endl;
            }
        }
    catch(List<Cancion>::ListException ex) {
        cout << "Ocurrio un error" << endl;
        cout << "Error de sistema:" << ex.what() << endl;
        return;
        }
    enterMenu();
    }

void Menu::displayMenu() {
    cout<< "\t\t MENU " <<endl;
    cout<< "\t[A]ñadir nuevos canciones: " <<endl;
    cout<< "\t[E]liminar cancion: " <<endl;
    cout<< "\t[M]ostrar toda la lista" <<endl;
    cout<< "\t[B]usqueda" <<endl;
    cout<< "\t[S]alir " <<endl;
    cout<< "\tSelecciona una opcion (A,E,M,B,S): ";
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
    cout<<myStr<<endl;
    cout<< myList->toString()<<endl<<endl;
    }

void Menu::findAnElement() {
    List<Cancion>::Position pointSearch;
    string myString;
    char myCharA;
    Nombre newInterprete;
    Cancion element;
    do {
        clearScreen();
        cout<<"\tIngrese tipo de busqueda"<<endl;
        cout<<"Buscar por Nombre de la [C]ancion / Nombre del [I]nterprete / [R]egresar al menu: ";
        cin>> myCharA;
        cin.sync();
        myCharA = toupper(myCharA);

        switch (myCharA) {
            case 'C':///Busqueda por Cancion
                cout<<endl<<"Ingrese la cancion a buscar: ";
                getline(cin,myString);
                element.setCancion(myString);

                ///Busqueda Lineal por Cancion
                if((pointSearch = myList->findDataLinear(element,
                                  Cancion::compareByCancion)) != nullptr) {
                    element = myList->retrieve(pointSearch);
                    cout<<endl<<"La cancion es: "<<element.getArchivo()<<endl<<endl;
                    }
                else {
                    cout<<endl<< "\tNo existe la cancion "<<endl;
                    }
                break;

            case 'I':///Busqueda por Interprete
                cout<<endl<<"Ingrese primer nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setFirstName(myString);
                cout<<endl<<"Ingrese segundo nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setLastName(myString);
                element.setInterprete(newInterprete);

                ///Busque Lineal por Interprete
                if((pointSearch = myList->findDataLinear(element,Cancion::compareByInterprete)) != nullptr) {
                    element = myList->retrieve(pointSearch);
                    cout<<endl<<"La cancion es: "<<element.getArchivo()<<endl<<endl;
                    }
                else {
                    cout<<endl<<"\tNo existe la cancion "<<endl;
                    }
                break;

            case 'R':
                break;

            default:
                cout<<endl<<"ERROR, Ingrese opcion valida "<<endl;
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

///Constructor
Menu::Menu(List<Cancion>& _list): myList(&_list) {}

///Metodo
void Menu::mainMenu() {
    char opc, opcContinue;
    do {
        showListMenu();
        displayMenu();
        cin>> opc;
        cin.sync();
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
                    cout<< "\nLISTA VACIA, debe ingresar canciones"
                        <<endl;
                    enterMenu();
                    }
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
