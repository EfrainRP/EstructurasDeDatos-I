#ifndef AVL_BTree_H_INCLUDED
#define AVL_BTree_H_INCLUDED

#include <iostream>
#include <string>
#include <exception>

///Definicion del Arbol AVL
template <class T>
class AVL_BTree {
    private:
        ///Definicion del Nodo
        class Node {
            private:
                T* dataPtr;
                Node* left;
                Node* right;
                int height;

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
                Node*& getLeft();
                Node*& getRight();
                int getHeight()const;

                void setDataPtr(T*);
                void setData(const T&);
                void setLeft(Node*&);
                void setRight(Node*&);
                void setHeight(const int&);
            };

    public:
        typedef Node* Position;

        ///Definicion de Excepcion para el arbol
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

        Position root;

        void copyAll(AVL_BTree<T>&);

        void insertData(Position&, const T&);
        void deleteData(Position&, const T&);
        Position& findData (Position&, const T&);

        Position& getLowest (Position&);
        Position& getHighest (Position&);

        void recalculedHeight(Position&);

        void parsePreOrder (Position&);
        void parseInOrder (Position&);
        void parsePostOrder (Position&);

        void parsePostOrderDeleteAll(Position&);
        void parsePreOrderCopy(Position&, Position&);

        ///Metodos del arbol AVL
        void doBalancing(Position&);

        int getBalanceFactor(const Position&)const;

        void doSimpleLeftRot(Position&);
        void doSimpleRightRot(Position&);

    public:
        ///Constructores
        AVL_BTree();
        AVL_BTree(AVL_BTree<T>&);
        ~AVL_BTree(); ///Destructor

        ///Sobrecarga de operador
        AVL_BTree<T>& operator = (const AVL_BTree<T>&);

        ///Metodos para un Arbol
        bool isEmpty()const;

        void insertData(const T&);
        void deleteData(const T&);
        void deleteAll();

        T retrieve(Position&)const;

        Position& getLeftSonOfRoot ();
        Position& getRightSonOfRoot ();

        Position& findData(const T&);
        Position& getLowest();
        Position& getHighest();

        bool isLeaf(const Position&)const;

        int getHeight(const Position&)const;
        int getHeight();

        void parsePreOrder ();
        void parseInOrder ();
        void parsePostOrder ();
    };

///Implementacion
using namespace std;

///del Nodo
template <class T>
AVL_BTree<T>::Node::Node():dataPtr(nullptr),left(nullptr), right(nullptr), height(1) {}

template <class T>
AVL_BTree<T>::Node::Node(const T& e): dataPtr(new T(e)), left(nullptr), right(nullptr), height(1) {
    if(dataPtr == nullptr) {
        throw Exception ("Memoria insuficiente, creando nodo");
        }
    }

template <class T>
AVL_BTree<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* AVL_BTree<T>::Node::getDataPtr()const {
    return dataPtr;
    }

template <class T>
T AVL_BTree<T>::Node::getData()const {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }

    return *dataPtr;
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::Node::getLeft() {
    return left;
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::Node::getRight() {
    return right;
    }

template <class T>
int AVL_BTree<T>::Node::getHeight() const {
    return height;
    }

template <class T>
void AVL_BTree<T>::Node::setDataPtr(T* e) {
    dataPtr = e;
    }

template <class T>
void AVL_BTree<T>::Node::setData(const T& e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = e;
        }
    }

template <class T>
void AVL_BTree<T>::Node::setLeft(Node*& p) {
    left = p;
    }

template <class T>
void AVL_BTree<T>::Node::setRight(Node*& p) {
    right = p;
    }

template <class T>
void AVL_BTree<T>::Node::setHeight(const int& h) {
    height = h;
    }

///del Arbol
///Metodos privados
template <class T>
void AVL_BTree<T>::copyAll( AVL_BTree<T>& t) {
    //Position rootCopy(t.root);
    parsePreOrderCopy(root, t.root);
    }

template <class T>
void AVL_BTree<T>::insertData(Position& r, const T& e) {
    if(r == nullptr) {//Inserta como hoja(esta balanceado)
        try {
            if((r = new Node(e)) == nullptr) {
                throw Exception("Memoria no disponible, insertData");
                }
            }
        catch (typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        }
    else {//Inserta recursivamente a la izq o der (ruta de insercion)
        if(e < r->getData()) {
            insertData(r->getLeft(),e);
            }
        else {
            insertData(r->getRight(),e);
            }
        //Sale de recursividad - paso atras en la ruta
        recalculedHeight(r);
        doBalancing(r);
        }
    }

template <class T>
void AVL_BTree<T>::deleteData(Position& r, const T& e) {
    if(isEmpty()) {
        return;
        }
    if(e == r->getData()) {//Encontro el valor
        if(isLeaf(r)) {//Es hoja
            delete r;
            r = nullptr;
            return;
            }
        else if(r->getRight() == nullptr or r->getLeft() == nullptr) {//Tiene un hijo
            Position aux(r);
            r = r->getLeft() == nullptr? r->getRight():r->getLeft();
            delete aux;
            return;
            }
        //Tiene dos hijos
        T sustitution(getHighest(r->getLeft())->getData());
        r->setData(sustitution);
        deleteData(r->getLeft(),sustitution);
        }
    else {//Elimina recursivamente a la izq o der (ruta de eliminacion)
        if(e < r->getData()) {
            deleteData(r->getLeft(), e);
            }
        else {
            deleteData(r->getRight(), e);
            }
        //Sale de recursividad - paso atras en la ruta
        recalculedHeight(r);
        doBalancing(r);
        }
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::findData (Position& r, const T& e) {
    if(r == nullptr or r->getData() == e) {
        return r;
        }
    if(e < r->getData()) {
        return findData(r->getLeft(), e);
        }
    return findData(r->getRight(), e);
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::getLowest (Position& r) {
    if(r == nullptr or r->getLeft() ==nullptr) {
        return r;
        }
    return getLowest(r->getLeft());
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::getHighest (Position& r) {
    if(r == nullptr or r->getRight() == nullptr) {
        return r;
        }
    return getHighest(r->getRight());
    }

template <class T>
void AVL_BTree<T>::parsePreOrder (Position& r) {
    if(r == nullptr) {
        return;
        }
    std::cout << r->getData().toString() << ", ";
    parsePreOrder(r->getLeft());
    parsePreOrder(r->getRight());
    }

template <class T>
void AVL_BTree<T>::parseInOrder (Position& r) {
    if(r == nullptr) {
        return;
        }
    parseInOrder(r->getLeft());
    cout << r->getData().toString() << ", ";
    parseInOrder(r->getRight());
    }

template <class T>
void AVL_BTree<T>::parsePostOrder (Position& r) {
    if(r == nullptr) {
        return;
        }
    parsePostOrder(r->getLeft());
    parsePostOrder(r->getRight());
    cout << r->getData().toString() << ", ";
    }

template <class T>
void AVL_BTree<T>::parsePostOrderDeleteAll(Position& r) {
    if(r == nullptr) {
        return;
        }

    parsePostOrderDeleteAll(r->getLeft());
    parsePostOrderDeleteAll(r->getRight());
    delete r;
    }

template <class T>
void AVL_BTree<T>::parsePreOrderCopy(Position& r, Position& rCopy) {
    if(rCopy == nullptr) {
        r = nullptr;
        }
    else {
        try {
            if((r = new Node(rCopy->getData())) == nullptr) {
                throw Exception("Memoria no disponible, copyAll");
                }
            }
        catch (typename Node::Exception ex) {
            throw Exception(ex.what());
            }

        parsePreOrderCopy(r->getLeft(), rCopy->getLeft());
        parsePreOrderCopy(r->getRight(), rCopy->getRight());
        }
    }

///Metodos del arbol AVL
template <class T>
void AVL_BTree<T>:: doBalancing(Position& r) {
    switch(getBalanceFactor(r)) {
        case -2://Desbalanceado a la izq.
            ///Se factorizo la funcion simpleRightRot
            if(getBalanceFactor(r->getLeft()) == 1) {//Rotacion Doble
                doSimpleLeftRot(r->getLeft());
                }
            doSimpleRightRot(r);
            break;

        case 2://Desbalanceado a la der.
            ///Se factorizo la funcion simpleLeftRot
            if(getBalanceFactor(r->getRight()) == -1) {//Rotacion Doble
                doSimpleRightRot(r->getRight());
                }
            doSimpleLeftRot(r);
            break;
        }
    }

template <class T>
int AVL_BTree<T>::getBalanceFactor(const Position& r) const {
    return getHeight(r->getRight()) - getHeight(r->getLeft());
    }

template <class T>
void AVL_BTree<T>:: doSimpleLeftRot(Position& r) {
    Position aux1(r->getRight());
    Position aux2(aux1->getLeft());

    r->setRight(aux2);
    aux1->setLeft(r);
    r = aux1;

    recalculedHeight(r->getLeft());
    recalculedHeight(r);
    }

template <class T>
void AVL_BTree<T>:: doSimpleRightRot(Position& r) {
    Position aux1(r->getLeft());
    Position aux2(aux1->getRight());

    r->setLeft(aux2);
    aux1->setRight(r);
    r = aux1;

    recalculedHeight(r->getRight());
    recalculedHeight(r);
    }

///Constructores
template <class T>
AVL_BTree<T>::AVL_BTree(): root(nullptr) {}

template <class T>
AVL_BTree<T>::AVL_BTree(AVL_BTree<T>& t): AVL_BTree() {
    copyAll(t);
    }

template <class T>
AVL_BTree<T>::~AVL_BTree() {///Destructor
    deleteAll();
    }

///Sobre carga de operador
template <class T>
AVL_BTree<T>& AVL_BTree<T>::operator =(const AVL_BTree<T>&t) {
    deleteAll();
    copyAll(t);
    return *this;
    }

///Metodos publicos de la AVL_BTree
template <class T>
bool AVL_BTree<T>::isEmpty() const {
    return root == nullptr;
    }

template <class T>
void AVL_BTree<T>::insertData(const T& e) {
    insertData(root, e);
    }

template <class T>
void AVL_BTree<T>::deleteData(const T& e) {
    deleteData(root, e);
    }

template <class T>
void AVL_BTree<T>::deleteAll() {
    parsePostOrderDeleteAll(root);
    root = nullptr;
    }

template <class T>
T AVL_BTree<T>::retrieve(Position& r) const {
    return r->getData();
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::getLeftSonOfRoot () {
    return root->getLeft();
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::getRightSonOfRoot () {
    return root->getRight();
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::findData(const T& e) {
    return findData(root, e);
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::getLowest() {
    return getLowest(root);
    }

template <class T>
typename AVL_BTree<T>::Position& AVL_BTree<T>::getHighest() {
    return getHighest(root);
    }

template <class T>
bool AVL_BTree<T>::isLeaf(const Position& r)const {
    return r != nullptr and r->getLeft() == r->getRight();
    }

template <class T>
int AVL_BTree<T>::getHeight() {
    return getHeight(root);
    }

template <class T>
int AVL_BTree<T>::getHeight(const Position& r)const {
    if(r == nullptr) {
        return 0;
        }
    return r->getHeight();
    }

template <class T>
void AVL_BTree<T>::recalculedHeight(Position& r) {
    int lH(r->getLeft() == nullptr? 0 : r->getLeft()->getHeight());
    int rH(r->getRight() == nullptr? 0 : r->getRight()->getHeight());

    r->setHeight((lH > rH ? lH : rH) + 1);
    }

template <class T>
void AVL_BTree<T>::parsePreOrder () {
    parsePreOrder(root);
    }

template <class T>
void AVL_BTree<T>::parseInOrder () {
    parseInOrder(root);
    }

template <class T>
void AVL_BTree<T>::parsePostOrder () {
    parsePostOrder(root);
    }

#endif // AVL_BTree_H_INCLUDED
