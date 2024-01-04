#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "ListException.h"

/*Template, nos permite cambiar el tipo de dato del todo el programa a partir de esta funcion
Se debera hacer la definicion y la implementacion en el mismo archivo para la plantilla*/
template <class T, int ARRAYSIZE = 1024>
class Lista {
    private:
        //Atributos
        T lista[ARRAYSIZE];
        int last;

        //Metodos privados
        void copyAll(const Lista<T, ARRAYSIZE>&);//Guardara el objeto creado a una copia
        bool isValidPos(const int&);

    public:
        //Constructores
        Lista();
        Lista(const Lista<T, ARRAYSIZE>&);

        //Sobrecarga de operador
        Lista<T, ARRAYSIZE>& operator = (const Lista<T, ARRAYSIZE>&);

        //Metodos para una Lista
        bool isEmpty();
        bool isFull();

        void insertElement(const int&, const T&);
        void deleteElement(const int&);
        void deleteAllElement();
        T retrieve(const int&);

        int getFirstPos();
        int getLastPos();
        int getPreviousPos(const int&);
        int getNextPos(const int&);

        std::string toString();//Paso los atributos a un string

    };

using namespace std;

//Metodos privados
template <class T, int ARRAYSIZE>
void Lista<T, ARRAYSIZE>::copyAll(const Lista<T, ARRAYSIZE>& l) {

    for(int i(0); i <= l.last; i++) {
        lista[i] = l.lista[i];
        }

    last = l.last;
    }

template <class T, int ARRAYSIZE>
bool Lista<T, ARRAYSIZE>::isValidPos(const int& p) {
    return p >= 0 && p <= last;
    }

//Constructores
template <class T, int ARRAYSIZE>
Lista<T, ARRAYSIZE>::Lista() : last(-1) {}

template <class T, int ARRAYSIZE>
Lista<T, ARRAYSIZE>::Lista(const Lista<T, ARRAYSIZE>& l) {
    copyAll(l);
    }

//Sobrecarga de operador
template <class T, int ARRAYSIZE>
Lista<T, ARRAYSIZE>& Lista<T, ARRAYSIZE>::operator = (const Lista<T, ARRAYSIZE>& l) {
    copyAll(l);
    return *this;
    }

//Metodos para una Lista
template <class T, int ARRAYSIZE>
bool Lista<T, ARRAYSIZE>::isEmpty() {
    return last == -1;
    }

template <class T, int ARRAYSIZE>
bool Lista<T, ARRAYSIZE>::isFull() {
    return last == ARRAYSIZE-1;
    }

template <class T, int ARRAYSIZE>
void Lista<T, ARRAYSIZE>::insertElement(const int& pos, const T& newElement) {
    if(isFull()) {
        throw ListException("Desbordamiento de datos, insertElement");
        }

    if(pos != -1 && !isValidPos(pos)) {
        throw ListException("Posicion Invalida, insertElement");
        //return;
        }

/*Detectara si la posicion introducida esta dentro del rango la lista creada */
    if(pos > -1 && pos < last) {
        int i(last);//Insercion en el punto de interes
        while(i >= pos) {
            lista[i+1] = lista[i];
            i--;
            }
        lista[pos] = newElement;
        last++;

        }
    else {
//Insercion despues del punto de interes de la posicion -1 y ultima posicion
        lista[pos + 1] = newElement;
        last++;
        }
    }

template <class T, int ARRAYSIZE>
void Lista<T, ARRAYSIZE>::deleteElement(const int& p) {
    if(!isValidPos(p)) {
        throw ListException("Invalid posicion, deleteElement");
        }

    int i(p);
    while(i < last) {
        lista[i] = lista[i+1];
        i++;
        }
    last--;
    }

template <class T, int ARRAYSIZE>
void Lista<T, ARRAYSIZE>::deleteAllElement() {
    last = -1;
    }

template <class T, int ARRAYSIZE>
T Lista<T, ARRAYSIZE>::retrieve(const int& p) {
    if(!isValidPos(p)) {
        throw ListException("Invalid posicion, retrive");
        }
    return lista[p];
    }

template <class T, int ARRAYSIZE>
int Lista<T, ARRAYSIZE>::getFirstPos() {
    if(isEmpty()) {
        return -1;
        }
    return 0;
    }

template <class T, int ARRAYSIZE>
int Lista<T, ARRAYSIZE>::getLastPos() {
    return last;
    }

template <class T, int ARRAYSIZE>
int Lista<T, ARRAYSIZE>::getPreviousPos(const int& p) {
    if(isEmpty() or p < 1 or p > last) {
        return -1;
        }
    else {
        return p-1;
        }
    }

template <class T, int ARRAYSIZE>
int Lista<T, ARRAYSIZE>::getNextPos(const int& p) {
    if(isEmpty() or p < 0 or p > last-1) {
        return -1;
        }
    return p+1;
    }

template <class T, int ARRAYSIZE>
string Lista<T, ARRAYSIZE>::toString() {
    string myStr;
    char pos[50];

    if(isEmpty()) {
        sprintf(pos, "%50s", "----------------EMPTY LIST----------------");
        myStr = pos;
        }
    else {
        for(int i(0); i <= last; i++) {
            sprintf(pos, "%10i |", i);
            myStr +=  pos + lista[i].toString() + "\n";
            }
        }
    return myStr;
    }

#endif // LISTA_H_INCLUDED
