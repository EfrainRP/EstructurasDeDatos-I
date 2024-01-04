#include "coleccion.h"

using namespace std;

Coleccion::Coleccion() : indexInventario(0) {}//Inicializo en 0 en indice

Coleccion::Coleccion(const Coleccion& otro): indexInventario(otro.indexInventario) { //Inicializo el arreglo para empezar a guardar datos
    for(int x(0); x < indexInventario ; x++) {
        inventario[x] = otro.inventario[x];
        }
    }

int Coleccion::getIndexInventario() const {
    return indexInventario;
    }

void Coleccion::setIndexInventario(const int& indice) {
    indexInventario = indice;
    }

string Coleccion::toString(const int& index) const {
    string mystr;//Variable temporal
    mystr = "\tProducto #" + to_string(index+1) + "\n";
    mystr += inventario[index].toString() + "\n";
    return mystr;
    }

void Coleccion::agregarProducto(const Producto& otro) {
    inventario[indexInventario] = otro;
    indexInventario++;
    }

int Coleccion::buscarProducto(const std::string& otro) const {
    int indexNew(-5);
    for(int x(0); x < indexInventario; x++) {
        if (otro == inventario[x].getcodigoBarrasP()) {
            indexNew = x;
            break;
            }
        }
    return indexNew;
    }

void Coleccion::incrementaExistencia(const int& index, const int& existActual) {
    int existNueva(0);
    existNueva = inventario[index].getExistP() + existActual;
    inventario[index].setExistP(existNueva);
    }

void Coleccion::decrementaExistencia(const int& index, const int& existActual) {
    int existNueva(0);
    existNueva = inventario[index].getExistP() - existActual;
    if(existNueva < 0) {
        inventario[index].setExistP(0);
        }
    else {
        inventario[index].setExistP(existNueva);
        }
    }

