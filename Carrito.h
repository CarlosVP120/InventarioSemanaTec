/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Definición de la clase Carrito*/

#ifndef CARRITO_H
#define CARRITO_H
#include <string>
#include "ProductoCarrito.h"

using namespace std;

class Carrito{
    private:
        string cliente;
        ProductoCarrito productos[10];
        int size;
    public:
        Carrito();
        void setCliente(string nomUsuario);
        int getSize();
        void agregarProducto(ProductoCarrito prodCarrito);
        void verCarrito();
        bool verificaProductoRepetido(string id);
        bool verificaIdExistencia(string id, int cant, int existencia, int indicador);
        string consultaIdProducto(int indice);
        int consultaCantProducto(int indice);
        void vaciarCarrito();
        double total();
        void eliminarProducto(string id);
};

#endif