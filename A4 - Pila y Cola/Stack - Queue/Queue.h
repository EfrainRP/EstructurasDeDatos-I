#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <string>
#include "AnyException.h"

//Definicion
template <class T, int ARRAYSIZE = 1024>
class Queue {
    private:
        //Atributos
        T data[ARRAYSIZE];
        int frontPos;
        int endPos;

        //Metodos privados
        void copyAll(const Queue<T, ARRAYSIZE>&);

    public:
        //Constructores
        Queue();
        Queue(const Queue<T, ARRAYSIZE>&);

        //Sobrecarga de operador
        Queue<T, ARRAYSIZE>& operator = (const Queue<T, ARRAYSIZE>&);

        //Metodos para una Lista
        bool isEmpty();
        bool isFull();

        void enqueue(const T&);
        T dequeue();
        T getFrontPos();
    };

//Implementacion

using namespace std;

//Metodos privados
template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE>& q) {
    int i(q.frontPos);
    while(i != q.endPos + 1) {
        data[i] = q.data[i];

        if(++i == ARRAYSIZE) {
            i=0;
            }
        }

    frontPos = q.frontPos;
    endPos = q.endPos;
    }

//Constructores
template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue() : frontPos(0), endPos(ARRAYSIZE-1) {}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue<T, ARRAYSIZE>& q) {
    copyAll(q);
    }

//Sobrecarga de operador
template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator = (const Queue<T, ARRAYSIZE>& q) {
    copyAll(q);
    return *this;
    }

//Metodos para una Lista
template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty() {
    return frontPos == endPos + 1
           or (frontPos == 0 and endPos == ARRAYSIZE - 1);
    }

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull() {
    return frontPos == endPos + 2
           or (frontPos == 0 and endPos == ARRAYSIZE - 2)
           or (frontPos == 1 and endPos == ARRAYSIZE - 1);
    }

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T& newElement) {
    if(isFull()) {
        throw AnyException("Desbordamiento de datos, enqueue");
        }

    if(++endPos == ARRAYSIZE) {
        endPos = 0;
        }
    data[endPos] = newElement;
    }

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue() {
    if(isEmpty()) {
        throw AnyException("Insuficiencia de datos, dequeue");
        }

    T result(data[frontPos]);

    if (++frontPos == ARRAYSIZE) {
        frontPos = 0;
        }
    return result;
    }

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFrontPos() {
    if(isEmpty()) {
        throw AnyException("Insuficiencia de datos, getFrontPos");
        }
    return data[frontPos];
    }

#endif // QUEUE_H_INCLUDED
