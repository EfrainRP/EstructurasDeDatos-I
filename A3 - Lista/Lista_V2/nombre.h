#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED

#include <string>

class Nombre {
    private:
        //Atributos
        std::string firstName;
        std::string secondName;

        //Metodo privado
        void copyAll(const Nombre&);//Guardara el objeto creado a una copia
    public:
        //Constructores
        Nombre ();
        Nombre(const Nombre&);

        //Sobrecarga de operador
        Nombre& operator = (const Nombre&);

        //Metodos (Getters,Setters y etc)
        std::string getFirstName()const;
        std::string getLastName()const;

        void setFirstName(const std::string&);
        void setLastName(const std::string&);

        std::string toString() const;//Paso los atributos a un string
    };

#endif // NOMBRE_H_INCLUDED
