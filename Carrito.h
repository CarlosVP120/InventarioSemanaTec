/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Definición de la clase Carrito*/

#ifndef CARRITO_H
#define CARRITO_H
#include <string>
#include "ProductoCarrito.h"
#include "Usuario.h"    

using namespace std;

class Carrito{
    private:
        Usuario cliente;
        ProductoCarrito productos[100];
        int size;
    public:
        Carrito(Usuario user);
        void setCliente(string nomUsuario);
        int getSize();
        void agregarProducto(ProductoCarrito prodCarrito);
        void verCarrito();
        bool verificaProductoRepetido(string id);
        bool verificaIdExistencia(string id, int cant, int existencia, int indicador);
        string consultaIdProducto(int indice);
        string consultaNombreProducto(int indice);
        int consultaCantProducto(int indice);
        int consultaPrecioProducto(int indice);
        ProductoCarrito getProducto(int indice);
        void vaciarCarrito();
        double total();
        void eliminarProducto(string id);
};

#endif