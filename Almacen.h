/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Definición de la clase Almacen*/

#ifndef ALMACEN_H
#define ALMACEN_H
#include "ProductoAlmacen.h"
#include "Carrito.h"

class Almacen{
    private:
        ProductoAlmacen productos[20];
        int size;
    public:
        Almacen();
        void verProductos();
        bool verificaProductoAlmacen(string id, int cant, Carrito &carrito1);
        bool editarCarrito(string id, int cant, Carrito &carrito1);
        void descuentaArticulo(string id, int cantDesc);
        void pagarCarrito(Carrito &carrito1);
        void imprimeVertical();
        int buscarIndice(string id);
        ProductoAlmacen getProducto(int indice);
};

#endif