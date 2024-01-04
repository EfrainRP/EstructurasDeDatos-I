#include "producto.h"
#include "fecha.h"
#include <string>

using namespace std;

Producto::Producto() {} //Constructores
Producto::Producto(const Producto& otro): codigoBarrasP(otro.codigoBarrasP),
    nombreP(otro.nombreP), pesoP(otro.pesoP), fechaIn(otro.fechaIn),
    precioMayoreoP(otro.precioMayoreoP), precioMenudeoP(otro.precioMenudeoP),
    existA(otro.existA) {};

string Producto::getcodigoBarrasP() const {
    return codigoBarrasP;
    }

string Producto::getNombreP() const {
    return nombreP;
    }

float Producto::getPesoP() const {
    return pesoP;
    }

Fecha Producto::getFechaIn() const {
    return fechaIn;
    }

float Producto::getPrecioMayoreoP() const {
    return precioMayoreoP;
    }

float Producto::getPrecioMenudeoP() const {
    return precioMenudeoP;
    }

int Producto::getExistP() const {
    return existA;
    }

string Producto::toString() const {
    char str_precioMayoreoP[10], str_precioMenudeoP[10], str_peso[10];
    sprintf (str_peso, "%.2f", pesoP);
    sprintf (str_precioMayoreoP, "%.2f", precioMayoreoP);
    sprintf (str_precioMenudeoP, "%.2f", precioMenudeoP);
    //sprintf sirve para guardar como una cadena en el búfer señalado por str, con formato de un printf de un valor

    return "Codigo de barras: " + codigoBarrasP + "\n" +
           "Nombre del producto: " + nombreP + "\n" +
           "Peso: " + str_peso + " kg" + "\n" +
           "Fecha de entrada: " + fechaIn.toString() + "\n" +
           "Precio de mayoreo: $" + str_precioMayoreoP + "\n" +
           "Precio de menudeo: $" + str_precioMenudeoP + "\n" +
           "Existencia actual: " + to_string(existA) + "\n";
    }


void Producto::setcodigoBarrasP(const std::string& codigoBarrasNuevo) {
    codigoBarrasP = codigoBarrasNuevo;
    }

void Producto::setNombreP(const std::string& nombreNuevo) {
    nombreP = nombreNuevo;
    }

void Producto::setPesoP(const float& pesoNuevo) {
    pesoP = pesoNuevo;
    }

void Producto::setFechaIn(const Fecha& fechaNuevo) {
    fechaIn = fechaNuevo;
    }

void Producto::setPrecioMayoreoP(const float& precioMayoreoNuevo) {
    precioMayoreoP = precioMayoreoNuevo;
    }

void Producto::setPrecioMenudeoP(const float& precioMenudeoNuevo) {
    precioMenudeoP = precioMenudeoNuevo;
    }

void Producto::setExistP(const int& existNuevo) {
    existA = existNuevo;
    }

Producto& Producto::operator =(const Producto& otro) {
    codigoBarrasP = otro.codigoBarrasP;
    nombreP = otro.nombreP;
    pesoP = otro.pesoP;
    fechaIn = otro.fechaIn;
    precioMayoreoP = otro.precioMayoreoP;
    precioMenudeoP = otro.precioMenudeoP;
    existA = otro.existA;

    return *this;
    }

