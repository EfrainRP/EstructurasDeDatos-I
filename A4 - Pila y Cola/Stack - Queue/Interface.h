#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "Stack.h"
#include "Queue.h"
#include "Expression.h"
#include <iostream>

class Interface {
    private:
        //Atributos
        string expres;
        Queue<char> firstQueue, secondQueue;
        Stack<char> myStack;

    public:
        //Constructor
        Interface();
        Interface(Interface&);
        Interface& operator = (Interface&);

        //Metodos
        void convertToPosFix();
        void mainInterface();

    };
#endif // INTERFACE_H_INCLUDED
