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
        void swapData(T&, T&); //Metodo utilizado para los ordenamientos

        void sortDataMerge(const int&, const int&);
        void sortDataQuick(const int&, const int&);

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

        bool isSorted();

        void sortDataBubble();
        void sortDataInsert();
        void sortDataSelect();
        void sortDataShell();

        void sortDataMerge();
        void sortDataQuick();


    };

///Implementacion
using namespace std;

///Metodos privados
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

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::swapData(T&a, T&b) {
    T aux(a);
    a = b;
    b = aux;
    }

///Constructores
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List():last(-1) {}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>& l) {
    copyAll(l);
    }


///Sobrecarga de operador
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator = (const List<T, ARRAYSIZE>& l) {
    copyAll(l);
    return *this;
    }

///Metodos para una Lista
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
    for(int i(0); i <= last; i++) {
        myStr +=  data[i].toString() + ", ";
        }
    return myStr;
    }

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isSorted() {
    int i(0);
    while(i<last) {
        if (data[i]>data[i+1]) {
            return false;
            }
        i++;
        }
    return true;
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataBubble() {
    int i(last), j;
    bool flag;
    do {
        flag = false;
        j=0;

        while(j<i) {
            if(data[j] > data[j+1]) {
                swapData(data[j],data[j+1]);
                flag = true;
                }
            j++;
            }
        i--;
        }
    while(flag);

    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataInsert() {
    int i(1), j;
    T aux;

    while (i<=last) {
        aux = data[i];
        j=i;

        while(j>0 and aux < data[j-1]) {
            data[j] = data[j-1];

            j--;
            }

        if(i != j) {
            data[j] = aux;
            }
        i++;
        }
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataSelect() {
    int i(0),j,m;

    while(i < last) {
        m = i;
        j = i + 1;

        while(j <= last) {
            if(data[j] < data[m]) {
                m = j;
                }
            j++;
            }
        if(i!=m) {
            swapData(data[i], data[m]);
            }
        i++;
        }
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataShell() {
    float factor(0.5);
    int dif((last + 1)*factor),i,j;

    while(dif > 0) {
        i = dif;
        while(i <= last) {
            j=i;
            while(j >=dif and data[j-dif] > data[j]) {
                swapData(data[j-dif],data[j]);

                j-= dif;
                }
            i++;
            }
        dif*=factor;
        }
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataMerge() {
    sortDataMerge(0,last);
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataMerge(const int& leftEdge, const int& rightEdge) {
    if (leftEdge >= rightEdge) { //Criterio de paro
        return;
        }
    int m((leftEdge + rightEdge)/2);//Divide y venceras

    sortDataMerge(leftEdge, m);
    sortDataMerge(m + 1,rightEdge);

    static T aux[ARRAYSIZE];//Copia al auxiliar
    for(int n(leftEdge); n<= rightEdge; n++) {
        aux[n] = data[n];
        }

    int i(leftEdge),j(m+1),x(leftEdge);//Intercalacion

    while(i <=m and j<= rightEdge) {
        while(i <=m and aux[i]<= aux[j]) {
            data[x++] = aux[i++];
            }
        if(i<=m) {
            while (j <= rightEdge and aux[j]<= aux[i]) {
                data[x++] = aux[j++];
                }
            }
        }
    while(i <= m) {
        data[x++] = aux[i++];
        }
    while(j <= rightEdge) {
        data[x++] = aux[j++];
        }
    }


template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataQuick() {
    sortDataQuick(0,last);
    }

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataQuick(const int& leftEdge, const int& rightEdge) {
    if (leftEdge >= rightEdge) { //Criterio de paro
        return;
        }
    int i(leftEdge),j(rightEdge);//Separacion

    while (i<j) {
        while(i < j and data[i] <= data[rightEdge]) {
            i++;
            }
        while (i<j and data[j] >= data[rightEdge]) {
            j--;
            }
        if (i != j) {
            swapData(data[i], data[j]);
            }
        }
    if(i!= rightEdge) {
        swapData(data[i], data[rightEdge]);
        }

    sortDataQuick(leftEdge, i - 1);//Divide y venceras
    sortDataQuick(i + 1, rightEdge);
    }

#endif // LIST_H_INCLUDED
