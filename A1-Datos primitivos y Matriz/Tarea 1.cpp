#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <functional>

using namespace std;
class Matriz {
    private:
        int sizeM;  //Atriutos
        float matriz[10][10];

    public:
        Matriz() {} //Constructores
        Matriz(const Matriz& mtrz) : sizeM(mtrz.sizeM) {
            for(int i = 0; i < this->sizeM; i++) {
                for(int j = 0; j < this->sizeM; j++) {
                    this->matriz[i][j] = mtrz.matriz[i][j];
                    }
                }
            }

        Matriz(const int& N) :  sizeM(N) {}

        //Metodos
        void fillMatriz() {//Llena matriz
            std::default_random_engine generator(clock());//Llama generador de numero reales random
            std::uniform_real_distribution<double> distribution(-100.00,100.00);
            for(int i = 0; i < sizeM; i++) {
                for(int j = 0; j < sizeM; j++) {
                    matriz[i][j] = distribution(generator);
                    }
                }
            }

        string printMatriz() const { //Imprime matriz resultante
            string _space;
            char myStr[11];
            for(int i = 0; i < this->sizeM; i++) {
                for(int j = 0; j < this->sizeM; j++) {
                    sprintf(myStr,"%8.2f", this->matriz[i][j]);
                    _space+= myStr;
                    _space+= "\t";
                    }
                _space+= "\n";
                }
            return _space;
            }

        //Operadores
        Matriz operator + (const Matriz& mtrz) {
            Matriz resultante(sizeM);
            for(int i = 0; i < this->sizeM; i++) {
                for(int j = 0; j < this->sizeM; j++) {
                    resultante.matriz[i][j] = matriz[i][j] + mtrz.matriz[i][j];
                    }
                }
            return resultante;
            }

        Matriz operator * (const Matriz& mtrz) {
            Matriz resultante(sizeM);
            for(int i = 0; i < sizeM; i++) {
                for(int j = 0; j < sizeM; j++) {
                    float sum = 0;
                    for(int a = 0; a < sizeM; a++) {
                        sum += matriz[i][a] * mtrz.matriz[a][j];
                        }
                    resultante.matriz[i][j] = sum;
                    }
                }
            return resultante;
            }

        Matriz& operator = (const Matriz& mtrz) {
            for(int i = 0; i < sizeM; i++) {
                for(int j = 0; j < sizeM; j++) {
                    matriz[i][j] = mtrz.matriz[i][j];
                    }
                }
            return *this;
            }
    };

class TiposDatosPrimitivos {
    public:
        void InfoData() {
            cout<<"\n  Tipo de dato              Bits       Valor minimo           Valor maximo"<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Caracter Con Signo           "<<sizeof(signed char)*8<<"            "<<+numeric_limits<signed char>::min()<<"                    "<<+numeric_limits<signed char>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Caracter Sin Signo           "<<sizeof(unsigned char)*8<<"              "<<+numeric_limits<unsigned char>::min()<<"                     "<<+numeric_limits<unsigned char>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Entero Corto Con Signo       "<<sizeof(signed short int)*8<<"          "<<+numeric_limits<signed short int>::min()<<"                  "<<+numeric_limits<signed short int>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Entero Corto Sin Signo       "<<sizeof(unsigned short int)*8<<"             "<<+numeric_limits<unsigned short int>::min()<<"                    "<<+numeric_limits<unsigned short int>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Entero Largo Con Signo       "<<sizeof(signed long int)*8<<"        "<<+numeric_limits<signed long int>::min()<<"             "<<+numeric_limits<signed long int>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Entero Largo Sin Signo       "<<sizeof(unsigned long int)*8<<"             "<<+numeric_limits<unsigned long int>::min()<<"                  "<<+numeric_limits<unsigned long int>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Real De Precision Simple     "<<sizeof(float)*8<<"         "<<+numeric_limits<float>::min()<<"            "<<+numeric_limits<float>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            std::cout<<"Real De Doble Precision      "<<sizeof(double)*8<<"         "<<+numeric_limits<double>::min()<<"           "<<+numeric_limits<double>::max()<<endl;
            cout<<"---------------------------------------------------------------------------------\n"<<endl;
            }
    };

void menu() {
    cout<<"\tSeleccione una opcion:"<<endl;
    cout<<"a) Tamaño y rangos de los Tipos de Dato Primitivos"<<endl;
    cout<<"b) Ejemplo de uso de Tipo de dato Estructurado"<<endl;
    cout<<"c) Salir\n"<<endl;
    }

int main() {
    char opcMenu;
    do {
        menu();
        cin>>opcMenu;

        if(opcMenu=='a') {
            TiposDatosPrimitivos ejemplo;
            ejemplo.InfoData();

            }
        else if(opcMenu=='b') {
            int N = 0;
            do {
                cout<<"Tamaño de matriz (3 a 10): "<<endl;
                cin>>N;
                }
            while((N<3)||(N>10));

            Matriz A(N), B(N), C(N), D(N);
            A.fillMatriz();
            cout << "Matriz A:" << endl;
            cout << A.printMatriz() << endl << endl;

            B.fillMatriz();
            cout << "Matriz B:" << endl;
            cout << B.printMatriz() << endl << endl;

            C = A * B;
            cout << "Matriz C - Multiplicacion de las matrices:" << endl;
            cout << C.printMatriz() << endl << endl;

            D = A + B;
            cout << "Matriz D - Suma de las matrices:" << endl;
            cout << D.printMatriz() << endl << endl;

            }
        }
    while(opcMenu!='c');

    cout<<"Fin del programa\n"<<endl;
    return 0;
    }

