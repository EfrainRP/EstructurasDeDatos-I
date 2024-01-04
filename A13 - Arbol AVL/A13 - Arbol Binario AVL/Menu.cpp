#include "Menu.h"

using namespace std;
using namespace std::chrono;

///Constructor
Menu::Menu(AVL_BTree<Integer>& _Tree): myTree(&_Tree) {}

///Metodo publico
void Menu::mainMenu() {
    int i(0), N(0);
    Integer myInt;

    cout<<"\t\t\tARBOLES BINARIO DE BUSQUEDA BALANCEADO"<<endl<<endl<<"Ingrese N valores a utilizar: ";
    cin>>N;
    cout<<endl<<"->Valores generados: "<<endl;

    std::default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long int> distribution(0,100000);
    auto randomInt = bind(distribution, generator);

    while(i < N) {
        myInt.setInteger(randomInt());
        cout<<myInt.toString() + ", ";
        myTree->insertData(myInt);
        i++;
        }

    cout<<endl<<endl<<"->PreOrder: "<<endl;
    myTree->parsePreOrder();

    cout<<endl<<endl<<"->InOrder: "<<endl;
    myTree->parseInOrder();

    cout<<endl<<endl<<"->PostOrder: "<<endl;
    myTree->parsePostOrder();

    cout<<endl<<endl<<"->Elemento menor: "<< myTree->retrieve(myTree->getLowest()).toString();

    cout<<endl<<endl<<"->Elemento mayor: "<<myTree->retrieve(myTree->getHighest()).toString()<<endl;

    //cout<<endl<<"->Altura del Arbol: "<<myTree->getHeight()<<endl;

    cout<<endl<<"->Altura de Subarbol Izquierdo, respecto a la Raiz del Arbol: "<<myTree->getHeight(myTree->getLeftSonOfRoot())<<endl;

    cout<<endl<<"->Altura de Subarbol Derecho, respecto a la Raiz del Arbol: "<<myTree->getHeight(myTree->getRightSonOfRoot())<<endl;

    /*cout<<endl<<"MALA ->Altura de Subarbol Izquierdo, respecto a la Raiz del Arbol: "<<theRoot->getLeft()->getHeight()<<endl;

    cout<<endl<<"->Altura de Subarbol Derecho, respecto a la Raiz del Arbol: "<<theRoot->getRight()->getHeight()<<endl;
    */
    /*cout<<endl<<endl<<"\t\t\tARBOL 2 "<<endl;

    AVL_BTree<Integer> myTreeB(*myTree);

    cout<<endl<<"PreOrder: ";
    myTreeB.parsePreOrder();
    cout<<endl<<endl<<"InOrder: ";
    myTreeB.parseInOrder();
    cout<<endl<<endl<<"PostOrder: ";
    myTreeB.parsePostOrder();

    cout<<endl<<endl<<"Elemento menor: "<< myTreeB.getLowest()->getData().toString();

    cout<<endl<<endl<<"Elemento mayor: "<<myTreeB.getHighest()->getData().toString()<<endl;

    cout<<endl<<"Altura del Arbol: "<<myTreeB.getHeight()<<endl;

    cout<<endl<<"Altura de Subarbol Izquierdo del Arbol: "<<myTreeB.getHeight(theRoot->getLeft())+1<<endl;

    cout<<endl<<"Altura de Subarbol Derecho del Arbol: "<<myTreeB.getHeight(theRoot->getRight())+1<<endl;

    cout<<endl<<"NUM: ";
    cin>>i;
    myInt.setInteger(i);
    cout<<endl<<"postOrder: "<<myInt.getInteger()<<endl;
    myTreeB.deleteData(myInt);
    myTreeB.parsePostOrder();

    myTreeB.deleteAll();
    cout<<endl<<"postOrder: delete"<<endl;
    myTreeB.parsePostOrder();
    */
    }
