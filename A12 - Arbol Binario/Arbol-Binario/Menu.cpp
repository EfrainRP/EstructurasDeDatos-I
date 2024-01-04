#include "Menu.h"

using namespace std;
using namespace std::chrono;

///Metodo privado
void Menu::enterMenu() {
    cout<< endl<< "Presiona cualquier tecla para continuar";
    getch();
    }

///Constructor
Menu::Menu(BTree<Integer>& _BTree): myBTree(&_BTree) {}

///Metodo publico
void Menu::mainMenu() {
    int i(0), N;
    Integer myInt;
    BTree<Integer>::Position theRoot;

    cout<<"\t\t\tARBOLES BINARIOS DE BUSQUEDA"<<endl<<endl<<"Ingrese N valores a utilizar: ";
    cin>>N;
    cout<<endl<<"->Valores generados: "<<endl;

    std::default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long int> distribution(0,100000);
    auto randomInt = bind(distribution, generator);

    while(i < N) {
        myInt.setInteger(randomInt());
        myBTree->insertData(myInt);
        //cout<<myInt.toString() + ", ";
        if(i==0) {
            theRoot = myBTree->findData(myInt);
            cout<<endl<<"->ROOT: "<<theRoot->getData().toString()<<endl;
            }
        i++;
        }

    cout<<endl<<endl<<"->PreOrder: "<<endl;
    myBTree->parsePreOrder();
    cout<<endl<<endl<<"->InOrder: "<<endl;
    myBTree->parseInOrder();

    cout<<endl<<endl<<"->PostOrder: "<<endl;
    myBTree->parsePostOrder();

    cout<<endl<<endl<<"->Elemento menor: "<< myBTree->getLowest()->getData().toString();

    cout<<endl<<endl<<"->Elemento mayor: "<<myBTree->getHighest()->getData().toString()<<endl;

    cout<<endl<<"->Altura del Arbol: "<<myBTree->getHeight()<<endl;
    cout<<endl<<"->ROOT DER: "<<theRoot->getRight()->getData().toString()<<endl;
    cout<<endl<<"->ROOT Izq: "<<theRoot->getLeft()->getData().toString()<<endl;

    cout<<endl<<"->Altura de Subarbol Izquierdo, respecto a la Raiz del Arbol: "<<myBTree->getHeight(theRoot->getLeft())<<endl;

    cout<<endl<<"->Altura de Subarbol Derecho, respecto a la Raiz del Arbol: "<<myBTree->getHeight(theRoot->getRight())<<endl;

    enterMenu();

    /*cout<<endl<<endl<<"\t\t\tARBOL 2 "<<endl;

    BTree<Integer> myBTreeB(*myBTree);

    cout<<endl<<"PreOrder: ";
    myBTreeB.parsePreOrder();
    cout<<endl<<endl<<"InOrder: ";
    myBTreeB.parseInOrder();
    cout<<endl<<endl<<"PostOrder: ";
    myBTreeB.parsePostOrder();

    cout<<endl<<endl<<"Elemento menor: "<< myBTreeB.getLowest()->getData().toString();

    cout<<endl<<endl<<"Elemento mayor: "<<myBTreeB.getHighest()->getData().toString()<<endl;

    cout<<endl<<"Altura del Arbol: "<<myBTreeB.getHeight()<<endl;

    cout<<endl<<"Altura de Subarbol Izquierdo del Arbol: "<<myBTreeB.getHeight(theRoot->getLeft())+1<<endl;

    cout<<endl<<"Altura de Subarbol Derecho del Arbol: "<<myBTreeB.getHeight(theRoot->getRight())+1<<endl;

    cout<<endl<<"NUM: ";
    cin>>i;
    myInt.setInteger(i);
    cout<<endl<<"postOrder: "<<myInt.getInteger()<<endl;
    myBTreeB.deleteData(myInt);
    myBTreeB.parsePostOrder();

    myBTreeB.deleteAll();
    cout<<endl<<"postOrder: delete"<<endl;
    myBTreeB.parsePostOrder();*/

    }
