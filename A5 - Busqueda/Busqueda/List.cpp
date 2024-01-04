/*#include "Lista.h"

using namespace std;

void Lista::copyAll(const Lista& l){
    int i(0);
    while (i <= l.last){
        lista[i] = l.lista[i];
        i++;
    }
    last = l.last;
}

bool Lista::isValidPos(const int& p){
    return p >= 0 and p <= last;
}


Lista::Lista(): last(-1){}

Lista::Lista(const Lista& l){
    copyAll(l);
}

Lista& Lista::operator = (const Lista& l) {
    copyAll(l);
    return *this;
}

bool Lista::isEmpty() const{
    return last == -1;
}

bool Lista::isFull() const{
    return last == 49;
}

void Lista::insertElement(const int& p, const Cancion& newElement) {
    if (isFull()){
        throw ListException("Desvordamiento de datos");
    }
    if ((p != -1) and (!isValidPos(p))){
        throw ListException("Posicion invalida, addElement");
    }

    int i(last);//insercion despues del punto de interes
    while(i >= p){//corrimiento
        lista[i+1]= lista[i];
        i--;
    }
    lista[p] = newElement;
    last++;
}

void Lista::deleteElement(const int& p) {
    if(!isValidPos(p)){//checa si esta vacia
        throw ListException("Posicion invalida, deleteElement");
        return;
    }
    int i(p);
    while(i < last){//corrimiento
        lista[i]= lista[i + 1];
        i++;
    }
    last--;
}

void Lista::deleteAll(){
    last= -1;
}

Cancion Lista::retrieveElement(const int& p) {
    if (!isValidPos(p)){
        throw ListException("Posicion invalida, retrieveElement");
    }
    return lista[p];
}

int Lista::getFirstPos() const {
    int position;
    if (isEmpty()){
        return -1;
    }
    return 0;
}

int Lista::getLastPos() const {
    return last;
}

int Lista::getPrevPos(const int& p) const {
    if (isEmpty()or p > last or p < 1){
        return -1;
    }else{
        return p - 1;
    }
}

int Lista::getNextPos(const int& p) const {
    if (isEmpty() or p > last-1 or p < 0){
        return -1;
    }
    return p + 1;
}

string Lista::toString() const{
    string myStr;
    char mychar[70];

    if(isEmpty()) {
        sprintf(mychar, "%80s", "----------------EMPTY LIST----------------");
        myStr = mychar;
    }
    else{
        for(int i(0); i <= last; i++) {
            sprintf(mychar, "%20i |", i);
            myStr +=  mychar + lista[i].toString() + "\n";
        }
    }

    return myStr;
}
*/


