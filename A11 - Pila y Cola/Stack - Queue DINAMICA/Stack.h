#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>
#include <exception>

///Definicion de Pila
template <class T>
class Stack {           ///LSLLSE
    private:
        ///Definicion del Nodo
        class Node {
            private:
                T data;
                Node* next;

            public:
                Node();
                Node(const T&);

                T getData()const;
                Node* getNext()const;

                void setData(const T&);
                void setNext(Node*);
            };

    public:
        typedef Node* Position;

        ///Definicion de Excepcion para la Pila
        class Exception : public std::exception {
            private:
                std::string msg;
            public:
                explicit Exception(const char* message): msg(message) {}
                explicit Exception(const std::string& message): msg(message) {}
                virtual ~Exception() throw() {}
                virtual const char* what() const throw () {
                    return msg.c_str();
                    }
            };

    private:
        ///Atributo
        Position anchor;//Se abre esta area para aprovechar e incializar lo que tengo anteriormente

        ///Metodo privado
        void copyAll(const Stack&);//Guardara el objeto creado a una copia
        void deleteAll();//Como ya no es parte del metodo de la pila se implementara como un metodo privado

    public:
        ///Constructores
        Stack();
        Stack(const Stack&);

        ~Stack(); ///Destructor

        ///Sobrecarga de operador
        Stack& operator = (const Stack&);//No es necesario el <T> porque para el compilador ya esta todo esta plantillado asi que ya no es necesario

        ///Metodos para una Pila
        bool isEmpty()const;
        void push(const T&);
        T pop();
        T getTop()const;
    };

///Implementacion
using namespace std;

///del Nodo
template <class T>
Stack<T>::Node::Node():next(nullptr) {}

template <class T>
Stack<T>::Node::Node(const T& e): next(nullptr), data(e) {}

template <class T>
T Stack<T>::Node::getData()const {
    return data;
    }

template <class T>
typename Stack<T>::Position Stack<T>::Node::getNext()const {
    return next;
    }

template <class T>
void Stack<T>::Node::setData(const T& e) {
    data = e;
    }

template <class T>
void Stack<T>::Node::setNext(Node* p) {
    next = p;
    }

///de la Pila
///Metodos privados
template <class T>
void Stack<T>::copyAll(const Stack<T>& l) {
    Position aux(l.anchor);
    Position last(nullptr);
    Position newNode;

    while(aux != nullptr) {
        newNode = new Node(aux->getData());

        if(newNode == nullptr) {
            throw Exception("Memoria no disponible, inserData");
            }
        if(last == nullptr) {
            anchor = newNode;
            }
        else {
            last->setNext(newNode);
            }
        last = newNode;
        aux = aux->getNext();
        }
    }

template <class T>
void Stack<T>::deleteAll() {
    Position aux;
    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
        }
    }

///Constructores
template <class T>
Stack<T>::Stack(): anchor(nullptr) {}

template <class T>
Stack<T>::Stack(const Stack& s): Stack() {
    copyAll(s);
    }

template <class T>
Stack<T>::~Stack() {///Destructor
    deleteAll();
    }

///Sobre carga de operador
template <class T>
Stack<T>& Stack<T>::operator =(const Stack<T>&s) {
    deleteAll();
    copyAll(s);
    return *this;
    }

///Metodos publicos de la Pila
template <class T>
bool Stack<T>::isEmpty() const {
    return anchor == nullptr;
    }

template <class T>
void Stack<T>::push(const T& e) {
    Position aux(new Node(e));
    if(aux == nullptr) {
        throw Exception ("Memoria no disponible, push");
        }

    //Religado
    aux->setNext(anchor);
    anchor=aux;
    }

template <class T>
T Stack<T>::pop() {
    if(anchor == nullptr) {
        throw Exception ("Insuficiencia de datos, pop");
        }

    T result (anchor->getData());

    Position aux(anchor);
    anchor = anchor->getNext();

    delete aux;

    return result;
    }

template <class T>
T Stack<T>::getTop() const {
    if(anchor == nullptr) {
        throw Exception ("Insuficiencia de datos, getTop");
        }
    return anchor->getData();
    }

#endif // STACK_H_INCLUDED
