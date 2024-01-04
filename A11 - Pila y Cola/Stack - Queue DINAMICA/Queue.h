#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <string>
#include <exception>
///Definicion de Lista
template <class T>
class Queue {       ///LDLCCED
    private:
        ///Definicion del Nodo
        class Node {//Tendra un encabezado Dummy
            private:
                T* dataPtr;
                Node* next;
                Node* prev;

            public:
                ///Definicion de Excepcion para el Nodo
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

                Node();
                Node(const T&);

                ~Node();

                T* getDataPtr()const;
                T getData()const;
                Node* getNext()const;
                Node* getPrev()const;

                void setDataPtr(T*);
                void setData(const T&);
                void setNext(Node*);
                void setPrev(Node*);
            };

    public:
        typedef Node* Position;

        ///Definicion de Excepcion para la Cola
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
        Node* header;

        void copyAll(const Queue<T>&);//Guardara el objeto creado a una copia
        void deleteAll();

    public:
        ///Constructores
        Queue();
        Queue(const Queue<T>&);

        ~Queue(); ///Destructor

        ///Sobrecarga de operador
        Queue<T>& operator = (const Queue<T>&);//No es necesario el <T> porque para el compilador ya esta todo esta plantillado asi que ya no es necesario

        ///Metodos para una Lista
        bool isEmpty()const;

        void enqueue(const T&);

        T dequeue();

        T getFront()const;
    };

///Implementacion
using namespace std;

///del Nodo
template <class T>
Queue<T>::Node::Node():dataPtr(nullptr), next(nullptr), prev(nullptr) {}

template <class T>
Queue<T>::Node::Node(const T& e): dataPtr(new T(e)), next(nullptr), prev(nullptr) {
    if(dataPtr == nullptr) {
        throw Exception ("Memoria insuficiente, creando nodo");
        }
    }

template <class T>
Queue<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* Queue<T>::Node::getDataPtr()const {
    return dataPtr;
    }

template <class T>
T Queue<T>::Node::getData()const {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }
    return *dataPtr;
    }

template <class T>
typename Queue<T>::Position Queue<T>::Node::getNext()const {
    return next;
    }

template <class T>
typename Queue<T>::Position Queue<T>::Node::getPrev()const {
    return prev;
    }

template <class T>
void Queue<T>::Node::setDataPtr(T* p) {
    dataPtr = p;
    }

template <class T>
void Queue<T>::Node::setData(const T& e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e)) == nullptr) {
            throw Exception ("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = e;
        }
    }

template <class T>
void Queue<T>::Node::setNext(Node* p) {
    next = p;
    }

template <class T>
void Queue<T>::Node::setPrev(Node* p) {
    prev = p;
    }

///de la Lista
///Metodos privados
template <class T>
void Queue<T>::copyAll(const Queue<T>& q) {
    Position aux(q.header->getNext());
    Position newNode;

    while(aux != q.header) {
        try {
            if((newNode = new Node(aux->getData())) == nullptr) {
                throw Exception("Memoria no disponible, copyAll");
                }
            }
        catch(typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
        }
    }

template <class T>
void Queue<T>::deleteAll() {
    Position aux;

    while(header->getNext() != header) {
        aux = header->getNext();
        header->setNext(aux->getNext());

        delete aux;
        }

    header->setPrev(header);
    }

///Constructores
template <class T>
Queue<T>::Queue(): header(new Node) {
    if(header == nullptr) {
        throw Exception("Memoria no disponible, inicializando Queue");
        }

    header->setNext(header);
    header->setPrev(header);
    }

template <class T>
Queue<T>::Queue(const Queue<T>& q): Queue() {//Llama otra vez al contructor
    copyAll(q);
    }

template <class T>
Queue<T>::~Queue() {///Destructor
    deleteAll();
    delete header;
    }

///Sobre carga de operador
template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& q) {
    deleteAll();
    copyAll(q);
    return *this;
    }

///Metodos publicos de la Lista
template <class T>
bool Queue<T>::isEmpty() const {
    return header->getNext() == header;
    }

template <class T>
void Queue<T>::enqueue(const T& e) {
    Position aux;

    try {
        if((aux = new Node(e)) == nullptr) {
            throw Exception ("Memoria no disponible, enqueue");
            }
        }
    catch(typename Node::Exception ex) {
        throw Exception (ex.what());
        }

    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
    }

template <class T>
T Queue<T>::dequeue() {
    if(isEmpty()) {
        throw Exception ("Insuficiencia de datos, dequeue");
        }

    T result (header->getNext()->getData());

    Position aux(header->getNext());

    aux->getPrev()->setNext(aux->getNext());
    aux->getNext()->setPrev(aux->getPrev());

    delete aux;

    return result;
    }

template <class T>
T Queue<T>::getFront() const {
    if(isEmpty()) {
        throw Exception ("Insuficiencia de datos, getFront");
        }

    return header->getNext()->getData();
    }
#endif // QUEUE_H_INCLUDED
