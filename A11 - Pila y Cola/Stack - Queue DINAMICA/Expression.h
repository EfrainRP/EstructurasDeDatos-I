#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED

#include "Stack.h"
#include "Queue.h"

class Expression {
    private:
        ///Atributo
        Stack<char> *myStack;

        ///Metodos privados
        int getPrecedence(const char&) const; //Pasamos los operadores como valores, como la precedencia

        //Determina la precedencia, de la pila a utilizar y la de la cola infija
        int comparePrecedence(Stack<char>, char)const;

    public:
        ///Contructores
        Expression();
        Expression(Stack<char>&);

        ///Metodos
        void getInfix(Queue<char>&);
        Queue<char> convertPosfix() ;
    };


#endif // EXPRESSION_H_INCLUDED
