#include "fecha.h"

using namespace std;
Fecha::Fecha() {} //Constructores
Fecha::Fecha(const Fecha& date): dia(date.dia),mes(date.mes),anio(date.anio) {}

int Fecha::getDia() const {
    return dia;
    }

int Fecha::getMes() const {
    return mes;
    }

int Fecha::getAnio() const {
    return anio;
    }

string Fecha::toString() const { //to_string es para convertir del VALOR (x) a una CADENA
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }

void Fecha::setDia(const int& d) {
    dia = d;
    }

void Fecha::setMes(const int& m) {
    mes = m;
    }

void Fecha::setAnio(const int& a) {
    anio = a;
    }
