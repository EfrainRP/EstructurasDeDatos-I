#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "Stack.h"
#include "Queue.h"
#include "Expression.h"

class Interface {
    private:
        ///Atributos
        std::string expres;
        Queue<char> firstQueue, secondQueue;
        Stack<char> myStack;

    public:
        ///Constructor
        Interface();
        Interface(Interface&);

        ///Sobrecarga de operador
        Interface& operator = (Interface&);

        ///Metodos
        void convertToPosFix();
        void mainInterface();

    };
#endif // INTERFACE_H_INCLUDED
