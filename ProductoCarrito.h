/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Definición de la clase ProductoCarrito*/

#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H
#include <string>

using namespace std;

class ProductoCarrito{
    private:
        string id;
        string nombre;
        double precio;
        int cantidad;
    public:
        ProductoCarrito();
        ProductoCarrito(string id, string nombre, double precio, int cant);
        void setCantidad(int cantidad);
        int getCantidad();
        void aumentaCantidad(int cantidad);
        string getId();
        void mostrar();
        bool verificaId(string id);
        bool verificarCant(int cantidad, int existencia, int indicador);
        double subtotal();
};

#endif
