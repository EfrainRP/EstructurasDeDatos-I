#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED

#include "nombre.h"
#include <string>

class Cancion {
    private:
        //Atributos
        std::string cancion;
        Nombre autor;
        Nombre interprete;
        int ranking;

        //Metodo privado
        void copyAll(const Cancion&);//Guardara el objeto creado a una copia

    public:
        //constructor
        Cancion();
        Cancion(const Cancion&);

        //Sobrecarga de operador
        Cancion& operator = (const Cancion&);

        //Metodos (Getters,Setters y etc)
        std::string getCancion() const;
        Nombre getAutor() const;
        Nombre getInterprete() const;
        int getRanking()const;

        void setCancion(const std::string&);
        void setAutor(const Nombre&);
        void setInterprete(const Nombre&);
        void setRanking(const int&);

        std::string toString()const;//Paso los atributos a un string
    };

#endif // CANCION_H_INCLUDED
