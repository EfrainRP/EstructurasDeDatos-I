#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <string>
#include "ListException.h"

//Definicion
template <class T, int ARRAYSIZE = 1024>
class List {
    private:
        //Atributos
        T data[ARRAYSIZE];
        int last;

        //Metodos privados
        void copyAll(const List<T, ARRAYSIZE>&);//Guardara el objeto creado a una copia
        bool isValidPos(const int&);//Si esta en el rango adecuado

    public:
        //Constructores
        List();
        List(const List<T, ARRAYSIZE>&);

        //Sobrecarga de operador
        List<T, ARRAYSIZE>& operator = (const List<T, ARRAYSIZE>&);

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

        std::string toString();

        int findElementLinear(const T&, int cmp(const T&, const T&));
        int findElementBinary(const T&, int cmp(const T&, const T&));

    };

//Implementacion
using namespace std;

//Metodos privados
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE>& l) {

    for(int i(0); i <= l.last; i++) {
        data[i] = l.data[i];
        }

    last = l.last;
    }

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValidPos(const int& p) {
    return p >= 0 && p <= last;
    }

//Constructores
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List():last(-1) {}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>& l) {
    copyAll(l);
    }


//Sobrecarga de operador
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator = (const List<T, ARRAYSIZE>& l) {
    copyAll(l);
    return *this;
    }

//Metodos para una Lista
template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() {
    return last == -1;
    }

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() {
    return last == ARRAYSIZE-1;
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertElement(const int& pos, const T& newElement) {
    if(isFull()) {
        throw ListException("Desbordamiento de datos, insertElement");
        }

    if(pos != -1 && !isValidPos(pos)) {
        throw ListException("Posicion Invalida, insertElement");
        }

//Detectara si la posicion introducida esta dentro del rango la lista creada */
    if(pos > -1 && pos < last) {
        int i(last);//Insercion en el punto de interes
        while(i >= pos) {
            data[i+1] = data[i];
            i--;
            }
        data[pos] = newElement;
        last++;

        }
    else {
//Insercion despues del punto de interes de la posicion -1 y ultima posicion
        data[pos + 1] = newElement;
        last++;
        }
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteElement(const int& p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion Invalida, deleteElement");
        }

    int i(p);
    while(i < last) {
        data[i] = data[i+1];
        i++;
        }
    last--;
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteAllElement() {
    last = -1;
    }

template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::retrieve(const int& p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion Invalida, retrive");
        }
    return data[p];
    }

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPos() {
    if(isEmpty()) {
        return -1;
        }
    return 0;
    }

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos() {
    return last;
    }

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPreviousPos(const int& p) {
    if(isEmpty() or p < 1 or p > last) {
        return -1;
        }
    else {
        return p-1;
        }
    }

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int& p) {
    if(isEmpty() or p < 0 or p > last-1) {
        return -1;
        }
    return p+1;
    }

template <class T, int ARRAYSIZE>
string List<T, ARRAYSIZE>::toString() {
    string myStr;
    char pos[50];

    if(isEmpty()) {
        sprintf(pos, "%50s", "----------------EMPTY LIST----------------");
        myStr = pos;
        }
    else {
        for(int i(0); i <= last; i++) {
            sprintf(pos, "%10i |", i);
            myStr +=  pos + data[i].toString() + "\n";
            }
        }
    return myStr;
    }

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findElementLinear(const T& element, int cmp(const T&, const T&)) {
    int i(0);
    while(i <= last) {
        if(cmp(data[i],element) == 0) {
            return i;
            }
        i++;
        }
    return -1;
    }

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findElementBinary(const T& element, int cmp(const T&, const T&)) {
    int i(0), j(last),m(0);
    while(i <= j) {
        m = (i + j)/2;
        if(cmp(data[m],element) == 0) {
            return m;
            }

        if (cmp(element,data[m]) == -1) {
            j = m - 1;
            }
        else {
            i = m + 1;
            }
        }
    return -1;
    }

#endif // LIST_H_INCLUDED
