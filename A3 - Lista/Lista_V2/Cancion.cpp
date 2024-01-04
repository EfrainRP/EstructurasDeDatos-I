#include "Cancion.h"

using namespace std;

//Metodo privado
void Cancion::copyAll(const Cancion& c) {
    cancion = c.cancion;
    autor = c.autor;
    interprete = c.interprete;
    ranking = c.ranking;
    }

//Constructores
Cancion::Cancion() {}

Cancion::Cancion(const Cancion& n) {
    copyAll(n);
    }

//Sobrecarga de operador
Cancion& Cancion::operator =(const Cancion& n) {
    copyAll(n);
    return *this;
    }

//Metodos (Getters,Setters y etc)
std::string Cancion::getCancion() const {
    return cancion;
    }

Nombre Cancion::getAutor() const {
    return autor;
    }

Nombre Cancion::getInterprete() const {
    return interprete;
    }

int Cancion::getRanking() const {
    return ranking;
    }


void Cancion::setCancion(const std::string& _cancion) {
    cancion = _cancion;
    }

void Cancion::setAutor(const Nombre& _autor) {
    autor = _autor;
    }

void Cancion::setInterprete(const Nombre& _interprete) {
    interprete = _interprete;
    }

void Cancion::setRanking(const int& _ranking) {
    ranking = _ranking;
    }

std::string Cancion::toString()const {
    string myStr;
    char mychar[200];
    sprintf(mychar,"%35s | %35s | %35s | %3i",cancion.c_str(),autor.toString().c_str(),interprete.toString().c_str(),ranking);
    myStr += mychar;
    //c_str() es un puntero temporal cuyo contenido es una cadena que apunta a una matriz de caracteres
    return myStr;
    }
