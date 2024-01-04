#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>

#include "AnyException.h"

//Definicion
template <class T, int ARRAYSIZE = 1024>
class Stack {
    private:
        //Atributos
        T data[ARRAYSIZE];
        int top;

        //Metodos privados
        void copyAll(const Stack<T, ARRAYSIZE>&);

    public:
        //Constructores
        Stack();
        Stack(const Stack<T, ARRAYSIZE>&);

        //Sobrecarga de operador
        Stack<T, ARRAYSIZE>& operator = (const Stack<T, ARRAYSIZE>&);

        //Metodos para una Lista
        bool isEmpty();
        bool isFull();

        void push(const T&);//COLOCA
        T pop();//BORRA
        T getTop();//OBTIENE

        void showStack();
        void gotoxy(T&, T&);
    };

//Implementacion

using namespace std;

//Metodos privados
template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& s) {
    for(int i(0); i <= s.top; i++) {
        data[i] = s.data[i];
        }
    top = s.top;
    }

//Constructores
template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) {}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE>& s) {
    copyAll(s);
    }

//Sobrecarga de operador
template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator = (const Stack<T, ARRAYSIZE>& s) {
    copyAll(s);
    return *this;
    }

//Metodos para una Pila
template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() {
    return top == -1;
    }

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() {
    return top == ARRAYSIZE - 1;
    }

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& newElement) {
    if(isFull()) {
        throw AnyException("Desbordamiento de datos, push");
        }

    data[++top] = newElement;
    }

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop() {
    if(isEmpty()) {
        throw AnyException("Insuficiencia de datos, pop");
        }
    return data[top--];
    }

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop() {
    if(isEmpty()) {
        throw AnyException("Insuficiencia de datos, getTop");
        }
    return data[top];
    }

#endif // STACK_H_INCLUDED
