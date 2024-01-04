#include "menu.h"

using namespace std;

int Menu::buscarIdProducto(const Coleccion& otro) {
    string codigo;
    int idCodigo;

    limpiarPantalla();
    cout<<"Ingrese codigo de barras a buscar: "<<endl;
    cin>>codigo;
    idCodigo = otro.buscarProducto(codigo);

    return idCodigo;
    }

Producto Menu::agregarProductoNuevo() const {
    limpiarPantalla();

//Inicializacion de Objetos
    Producto nuevoProducto;
    Fecha nuevaFecha;

//Variables temporales
    string myStr;
    float myfloat;
    int myInt;

//Pedir Datos
    cout<<"Ingrese codigo de barras (13 caracteres maximo): ";
    cin.ignore();
    getline(cin,myStr);
    nuevoProducto.setcodigoBarrasP(myStr);

    cout<<"Ingrese nombre: ";
    getline(cin,myStr);
    nuevoProducto.setNombreP(myStr);

    cout<<"Ingrese peso en kg: ";
    cin>>myfloat;
    nuevoProducto.setPesoP(myfloat);

    cout<<"Ingrese fecha de entrada "<<endl;
    cout<<"Ingrese dia: ";
    cin>>myInt;
    nuevaFecha.setDia(myInt);
    cout<<"Ingrese mes: ";
    cin>>myInt;
    nuevaFecha.setMes(myInt);
    cout<<"Ingrese año: ";
    cin>>myInt;
    nuevaFecha.setAnio(myInt);
    nuevoProducto.setFechaIn(nuevaFecha);

    cout<<"Ingrese precio de mayoreo: $";
    cin>>myfloat;
    nuevoProducto.setPrecioMayoreoP(myfloat);

    cout<<"Ingrese precio de menudeo: $";
    cin>>myfloat;
    nuevoProducto.setPrecioMenudeoP(myfloat);

    cout<<"Ingrese existencia actual: ";
    cin>>myInt;
    nuevoProducto.setExistP(myInt);

    return nuevoProducto;
    }

void Menu::imprimirMenu() const {
    limpiarPantalla();
    cout << "\tMenu" << endl;
    cout << "1) Agregar Productos" << endl;
    cout << "2) Aumentar existencia ya registrados" << endl;
    cout << "3) Decrementar existencia ya registrados" << endl;
    cout << "4) Ver todos los productos registrados" << endl;
    cout << "5) Salir" << endl;
    cout << "Ingrese una opcion: ";
    }


void Menu::limpiarPantalla() const {
    system("cls");//Limpia pantalla
    }

void Menu::enterMenu() const {
    cout << "\nPresiona cualquier tecla para continuar ";
    getch();//  Detecta un teclazo
    }

Menu::Menu() {
    Coleccion nuevaColeccion;
    int opc(0);
    while (opc!=5) {
        int indice, cantidad;
        char opcionNuevoP;

        imprimirMenu();
        cin>>opc;

        switch(opc) {
            case 1:
                do {
                    nuevaColeccion.agregarProducto(agregarProductoNuevo());
                    cout<<"Quiere agregar otro producto (S/N): "<<endl;
                    cin>> opcionNuevoP;
                    opcionNuevoP = toupper(opcionNuevoP);
                    }
                while(opcionNuevoP == 'S');

                if(nuevaColeccion.getIndexInventario() >= 500) {
                    cout<<"Ya no hay espacio en la memoria (arreglo Inventario)"<<endl;
                    }
                break;

            case 2:
                indice = buscarIdProducto(nuevaColeccion);
                if (indice!=-5) {
                    cout<< nuevaColeccion.toString(indice);
                    cout<< "\nIngrese la cantidad a agregar: ";
                    cin>>cantidad;
                    cout<<endl;
                    nuevaColeccion.incrementaExistencia(indice,cantidad);
                    cout<<nuevaColeccion.toString(indice);
                    }
                else {
                    cout<< "NO EXISTE codigo de barras";
                    }
                enterMenu();
                break;

            case 3:
                indice = buscarIdProducto(nuevaColeccion);
                if (indice!=-5) {
                    cout<< nuevaColeccion.toString(indice);
                    cout<< "Ingrese la cantidad a quitar: ";
                    cin>>cantidad;
                    cout<<endl;
                    nuevaColeccion.decrementaExistencia(indice,cantidad);
                    cout<<nuevaColeccion.toString(indice);
                    }
                else {
                    cout<< "NO EXISTE codigo de barras";
                    }
                enterMenu();
                break;

            case 4:
                limpiarPantalla();
                cout<<endl;
                for(int i(0); i < nuevaColeccion.getIndexInventario(); i++) {
                    cout<<nuevaColeccion.toString(i);
                    }
                enterMenu();
                break;

            case 5:
                limpiarPantalla();
                cout << "Fin del programa" << endl;
                break;

            default:
                limpiarPantalla();
                cout << "VALOR INVALIDO: Ingrese valor valida" << endl;
                enterMenu();
            }
        }
    }
