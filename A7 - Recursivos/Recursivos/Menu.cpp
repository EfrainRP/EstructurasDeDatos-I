#include "Menu.h"

using namespace std;
using namespace std::chrono;

///Metodos privados
void Menu::InputData() {
    int i(0);
    Integer myInt;

    std::default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long int> distribution(0,1000000);
    auto randomInt = bind(distribution, generator);

    while(i<100000) {
        try {
            myInt.setInteger(randomInt());

            myListA->insertElement(myListA->getLastPos(),myInt);
            }
        catch(ListException ex) {
            cout << endl << "\t\tOcurrio un error" << endl;
            cout << "\t\tError de sistema:" << ex.what() << endl;
            enterMenu();
            break;
            }
        i++;
        }
    }

void Menu::stateList() {
    if (myListB->isSorted()) {
        cout<<"-> La Lista esta ordenada    -> ";
        }
    else {
        cout<<"-> La Lista NO esta ordenada  ";
        }
    }


void Menu::sortData() {
    int i(0);
    char charBuffer[6];

    while(i<6) {
        cout<<"Copiando Lista...    ";
        *myListB = *myListA;
        stateList();
        cout<<endl;

        time_point<system_clock> initTime(system_clock::now());
        switch (i) {
            case 0:
                cout<<"Ordenando por Sort Bubble  ";
                myListB->sortDataBubble();
                break;

            case 1:
                cout<<"Ordenando por Sort Insert  ";
                myListB->sortDataInsert();
                break;

            case 2:
                cout<<"Ordenando por Sort Select  ";
                myListB->sortDataSelect();
                break;

            case 3:
                cout<<"Ordenando por Sort Shell   ";
                myListB->sortDataShell();
                break;

            case 4:
                cout<<"Ordenando por Sort Merge   ";
                myListB->sortDataMerge();
                break;

            case 5:
                cout<<"Ordenando por Sort Quick   ";
                myListB->sortDataQuick();
                break;
            }
        duration<float> timeLapse(system_clock::now() - initTime);

        stateList();
        sprintf(charBuffer, "%.3f", timeLapse.count());
        cout<<"Tiempo medido: "<<charBuffer<<" segundos"<<endl<<endl;
        i++;
        }
    }

void Menu::enterMenu() {
    cout<< endl<< "Presiona cualquier tecla para continuar";
    getch();
    }

///Constructor
Menu::Menu(List<Integer,100000>& _listA, List<Integer,100000>& _listB): myListA(&_listA), myListB(&_listB) {}

///Metodo publico
void Menu::mainMenu() {
    InputData();
    sortData();
    enterMenu();
    }
