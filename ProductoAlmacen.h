/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Definición de la clase ProductoAlmacen*/

#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H 
#include <string>

using namespace std;

class ProductoAlmacen{
    private:
        string id;
        string nombre;
        double precio;
        int existencia;
    public: 
        ProductoAlmacen();
        ProductoAlmacen(string caracteristicas[]);
        string getNombre();
        double getPrecio();
        int getExistencia();
        string getId();
        void mostrar();
        bool verificaId(string id);
        bool verificaExist(int cant);
        void descExistencia(int cantDesc);
};

#endif