#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED

#include "Nombre.h"
#include <iostream>
#include <string>

class Cancion {
    private:
        //Atributos
        std::string cancion;
        Nombre autor;
        Nombre interprete;
        int ranking;
        std::string archivo;

        //Metodo privado
        void copyAll(const Cancion&);//Guardara el objeto creado a una copia

    public:
        //constructor
        Cancion();
        Cancion(const Cancion&);

        //Metodos (Getters,Setters y etc)
        std::string getCancion() const;
        Nombre getAutor() const;
        Nombre getInterprete() const;
        int getRanking()const;
        std::string getArchivo() const;

        void setCancion(const std::string&);
        void setAutor(const Nombre&);
        void setInterprete(const Nombre&);
        void setRanking(const int&);
        void setArchivo(const std::string&) ;

        std::string toString()const;

        //Sobrecarga de operadores
        Cancion& operator = (const Cancion&);
        bool operator == (const Cancion&) const;
        bool operator != (const Cancion&) const;
        bool operator < (const Cancion&) const;
        bool operator <= (const Cancion&) const;
        bool operator > (const Cancion&) const;
        bool operator >= (const Cancion&) const;

        static int compareByCancion(const Cancion&, const Cancion&);
        static int compareByInterprete(const Cancion&, const Cancion&);
    };

#endif // CANCION_H_INCLUDED
