#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


#include <string>
#include <exception>
///Definicion de Lista
template <class T>
class List {
    private:
///Definicion del Nodo
        class Node {//Es una clase anidad de la lista aprovechando la plantilla
            private:
                T data;
                Node* next;
                Node* prev;

            public:
                Node();
                Node(const T&);
                T& getData();
                Node* getNext()const;
                Node* getPrev()const;

                void setData(const T&);
                void setNext(Node*);
                void setPrev(Node*);
            };
    public:
        typedef Node* Position;//aunque el nodo sea pivado, el nodo sera publico atraves de Position y se inicializa
///Definicion de Excepcion
        class ListException : public std::exception {
            private:
                std::string msg;
            public:
                explicit ListException(const char* message): msg(message)
                    {}
                explicit ListException(const std::string& message):
                    msg(message) {}
                virtual ~ListException() throw() {}
                virtual const char* what() const throw () {
                    return msg.c_str();
                    }
            };
    private:
        Node* anchor;//Se abre esta area para aprovechar e incializar lo que tengo anteriormente
        bool isValidPos(Node*)const;
        void copyAll(const List<T>&);//Guardara el objeto creado a una copia
    public:
///Constructores
        List();
        List(const List<T>&);
        ~List(); ///Destructor
///Sobrecarga de operador
        List<T>& operator = (const List<T>&);//No es necesario el <T> porque para el compilador ya esta todo esta plantillado asi que ya no es necesario
        T& operator [](const int&);

///Metodos para una Lista
        bool isEmpty()const;
        std::string toString()const;
        void insertData(Position, const T&);
        void deleteData(Position);
        void deleteAll();
        T& retrieve(Position);
        Position getFirstPos()const;
        Position getLastPos()const;
        Position getPrevPos(Position)const;
        Position getNextPos(Position)const;
        Position findDataLinear(const T&, int comp(const T&, const T&))const;
    };
///Implementacion
using namespace std;
///del Nodo
template <class T>
List<T>::Node::Node():next(nullptr), prev(nullptr) {}

template <class T>
List<T>::Node::Node(const T& e): next(nullptr), prev(nullptr), data(e) {}

template <class T>
T List<T>::Node::getData()const {
    return data;
    }
template <class T>
typename List<T>::Position List<T>::Node::getNext()const {
    return next;
    }
template <class T>
typename List<T>::Position List<T>::Node::getPrev()const {
    return prev;
    }
template <class T>
void List<T>::Node::setData(const T& e) {
    data = e;
    }
template <class T>
void List<T>::Node::setNext(Node* p) {
    next = p;
    }
template <class T>
void List<T>::Node::setPrev(Node* p) {
    prev = p;
    }

///de la Lista
///Metodos privados
template <class T>
bool List<T>::isValidPos(Position p) const {//cambia
    Position aux(anchor);
    while (aux != nullptr) {
        if(aux == p) {
            return true;
            }
        aux=aux->getNext();
        }
    return false;
    }
template <class T>
void List<T>::copyAll(const List<T>& l) {//cambia
    Position aux(l.anchor);
    Position last(nullptr);
    Position newNode;
    while(aux != nullptr) {
        newNode = new Node(aux->getData());
        if(newNode == nullptr) {
            throw ListException("Memoria no disponible, inserData");
            }
        if(last == nullptr) {
            anchor = newNode;
            }
        else {
            last->setNext(newNode);
            newNode->setPrev(last);
            }
        last = newNode;
        aux = aux->getNext();
        }
    }
///Constructores
template <class T>
List<T>::List(): anchor(nullptr) {}

template <class T>
List<T>::List(const List<T>& l):List() {
    copyAll(l);
    }
template <class T>
List<T>::~List() {///Destructor
    deleteAll();
    }
///Sobre carga de operador
template <class T>
List<T>& List<T>::operator =(const List<T>&l) {
    deleteAll();
    copyAll(l);
    return *this;
    }

template <class T>
T& List<T>::operator [](const int& p) {
    if(!isEmpty()){
        throw Exception ("Indice invalido");
    }
    int i(0);
    Position aux(anchor);
    do{
        if(i==p){
            return aux->getData();
        }
        i++;
        aux=aux->getNext();
    }while(aux !=anchor);

    throw Exception ("Indice invalido");
    }
///Metodos publicos de la Lista
template <class T>
bool List<T>::isEmpty() const {
    return anchor == nullptr;
    }
template <class T>
std::string List<T>::toString() const {
    string myStr;
    char pos[10];
    Position aux(anchor);
    for(int i(0); aux != nullptr; i++) {
        sprintf(pos, "%5i | ", i);
        myStr += pos + aux->getData().toString() + "\n";
        aux = aux->getNext();
        }
    return myStr;
    }
template <class T>
void List<T>::insertData(Position p, const T& e) {
    if(p != nullptr and !isValidPos(p)) {
        throw ListException("Posicion Invalida, insetData");
        }
    Position aux(new Node(e));
    if(aux == nullptr) {
        throw ListException ("Memoria no disponible, inserData");
        }
    //Religado
    if(p == nullptr) { //Insertar al principio
        aux->setNext(anchor);

        if(anchor!=nullptr){
            anchor->setPrev(aux);
            anchor->setNext(aux);
        }else{//ya es circular
            anchor->setPrev(getLastPos());
            anchor->setNext(anchor);

            getLastPos()->setNext(aux);
            anchor->setPrev(aux);
        }
        anchor = aux;
        }
    else { //Insertar en cualquier posicion (despues del punto de interes)
        aux->setPrev(p);
        aux->setNext(p->getNext());

        p->getNext()->setPrev(aux);
        p->setPrev(aux);///Verificar
        }
    }
template <class T>
void List<T>::deleteData(Position p) {
    if(!isValidPos(p)) {
        throw ListException ("Posicion invalida, deleteData");
        }
        p->getPrev()->setNext(p->getNext());
        p->getNext()->setPrev(p->getPrev());

    if(p != anchor) { //Si es el primero
        if(p->getNext() == p ){
                anchor =nullptr;
        }else{
            //anchor0 anchor->      Verificar
        }
        p->getNext()->setNext(p->getNext());
        }

    delete p;
    }
template <class T>
void List<T>::deleteAll() {
    Position aux, marca(anchor);

    do {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
        }while(marca != anchor);
    }
template <class T>
T& List<T>::retrieve(Position p) {
    if(!isValidPos(p)) {
        throw ListException ("Posicion invalida, retrieve");
        }
    return p->getData();
    }
template <class T>
typename List<T>::Position List<T>::getFirstPos() const {
    return anchor;
    }
template <class T>
typename List<T>::Position List<T>::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
        }

    return anchor->getPrev();
    }
template <class T>
typename List<T>::Position List<T>::getPrevPos(Position p) const {
    if(p== anchor or !isValidPos()){
        return nullptr;
    }
    return p->getPrev();
    }
template <class T>
typename List<T>::Position List<T>::getNextPos(Position p) const {
    if(p == getLastPos() or !isValidPos(p)) {
        return nullptr;
        }
    return p->getNext();
    }
template <class T>
typename List<T>::Position List<T>::findDataLinear(const T& e, int
        comp(const T&, const T&)) const {
    Position aux(anchor);
    while(aux!=nullptr and comp(aux->getData(),e) != 0) {
        aux=aux->getNext();
        }
    return aux;
    }
#endif // LIST_H_INCLUDED
