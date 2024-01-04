#include "Cancion.h"
#include <string>
#include <algorithm>

using namespace std;

//Metodo privado
void Cancion::copyAll(const Cancion& c) {
    cancion = c.cancion;
    autor = c.autor;
    interprete = c.interprete;
    ranking = c.ranking;
    archivo = c.archivo;
    }

//Constructores
Cancion::Cancion() {}

Cancion::Cancion(const Cancion& n) {
    copyAll(n);
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

std::string Cancion::getArchivo() const {
    return archivo;
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

void Cancion::setArchivo(const std::string& _archivo) {
    archivo = _archivo;
    }


std::string Cancion::toString()const {
    string myStr;
    myStr += cancion.c_str();
    myStr.resize (25,' ');
    myStr += " | ";
    myStr += autor.toString().c_str();
    myStr.resize (46,' ');
    myStr += " | ";
    myStr += interprete.toString().c_str();
    myStr.resize (68,' ');
    myStr += " | ";
    myStr += to_string(ranking);
    myStr.resize (78,' ');
    myStr += " | ";
    myStr += archivo.c_str();
    myStr.resize (110,' ');
    myStr += " | ";

    /*char mychar[200];
    sprintf(mychar,"%25s | %20s | %21s | %8i | %28s |",cancion.c_str(),autor.toString().c_str(),interprete.toString().c_str(),ranking, archivo.c_str());
    myStr += mychar;*/
    //c_str() es un puntero temporal cuyo contenido es una cadena que apunta a una matriz de caracteres
    return myStr;
    }

//Sobrecarga de operadores
Cancion& Cancion::operator =(const Cancion& n) {
    copyAll(n);
    return *this;
    }
bool Cancion::operator==(const Cancion& c) const {
    return cancion == c.cancion;
    }

bool Cancion::operator!=(const Cancion& c) const {
    return !(*this==c);
    }

bool Cancion::operator<(const Cancion& c) const {
    return cancion < c.cancion;
    }

bool Cancion::operator<=(const Cancion& c) const {
    return (*this < c) or (*this==c);
    }

bool Cancion::operator>(const Cancion& c) const {
    return !(*this<=c);
    }

bool Cancion::operator>=(const Cancion& c) const {
    return !(*this<c);
    }

int Cancion::compareByCancion(const Cancion& a, const Cancion& b) {
    /*string Acancion = a.getCancion();//Cadena que se recibe de cada elemento de la lista
    string Bcancion = b.getCancion();//Cadena que nosotros introducimos

    std::transform(Acancion.begin(), Acancion.end(), Acancion.begin(),::tolower);//Pone en mayusculas todo
    Acancion.erase(std::remove(Acancion.begin(), Acancion.end(), ' '), Acancion.end());//Elimina todos los espacios

    std::transform(Bcancion.begin(), Bcancion.end(), Bcancion.begin(),::tolower);//Pone en mayusculas todo
    Bcancion.erase(std::remove(Bcancion.begin(), Bcancion.end(), ' '), Bcancion.end());//Elimina todos los espacios

    return Acancion.compare(Bcancion);*/
    return a.cancion.compare(b.cancion);
    }

int Cancion::compareByInterprete(const Cancion& a, const Cancion& b) {

    /*string Acancion = a.interprete.toString();//Cadena que se recibe de cada elemento de la lista
    string Bcancion = b.interprete.toString();//Cadena que nosotros introducimos

    std::transform(Acancion.begin(), Acancion.end(), Acancion.begin(),::tolower);//Pone en mayusculas todo
    Acancion.erase(std::remove(Acancion.begin(), Acancion.end(), ' '), Acancion.end());//Elimina todos los espacios

    std::transform(Bcancion.begin(), Bcancion.end(), Bcancion.begin(),::tolower);//Pone en mayusculas todo
    Bcancion.erase(std::remove(Bcancion.begin(), Bcancion.end(), ' '), Bcancion.end());//Elimina todos los espacios

    return Acancion.compare(Bcancion);*/
    return a.interprete.toString().compare(b.interprete.toString());
    }

