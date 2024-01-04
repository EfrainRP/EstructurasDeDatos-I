#include "Interface.h"
#include <iostream>

using namespace std;

///Contructores
Interface::Interface() {}

Interface::Interface(Interface& i): expres(i.expres), firstQueue(i.firstQueue), secondQueue(i.secondQueue), myStack(i.myStack) {}

///Sobrecarga de operador
Interface& Interface::operator = (Interface& i) {
    expres = i.expres;
    firstQueue = i.firstQueue;
    secondQueue = i.secondQueue;
    myStack = i.myStack;
    }

///Metodos
void Interface::convertToPosFix() {

    cout << "Ingrese expresion con notacion infija: ";
    cin>> expres;

    int i(expres.size());
    while(i >= 0) {
        firstQueue.enqueue(expres[i]);
        i--;
        }

    Expression myExpression(myStack);
    myExpression.getInfix(firstQueue);
    secondQueue = myExpression.convertPosfix();

    cout << "Conversion a notacion posfija: ";
    while(!secondQueue.isEmpty()) {
        cout << secondQueue.dequeue();
        }
    cout << endl << endl;
    }

void Interface::mainInterface() {
    char opc;

    cout<< "\tConvertidor de Notacion de Infija a Posfija"<<endl<<endl;
    do {
        convertToPosFix();

        cout << "Desea convertir otra expresion [S]i/[N]o): ";
        cin >> opc;
        opc = toupper(opc);

        cout << endl;

        }
    while(opc != 'N');
    }



