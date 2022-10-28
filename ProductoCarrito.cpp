/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Implementación de los métodos de la clase ProductoCarrito*/

#include <iostream>
#include <string>
#include "ProductoCarrito.h"

using namespace std;

/*Constructor default de un producto del carrito con información vacía*/
ProductoCarrito::ProductoCarrito(){
    this->id = "";
    this->nombre = "";
    this->precio = 0;
    this->cantidad = 0;
}

/*Constructor con parámetros de un producto del carrito
Parámetros:
id: id ingresado por el usuario
nombre: nombre del producto con el id ingresado
precio: precio del producto con el id ingresado
cant: cantidad de artículos ingresados para ese producto*/
ProductoCarrito::ProductoCarrito(string id, string nombre, double precio, int cant){
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cant;
}

/*Método que le asigna a la propiedad cantidad, del producto carrito, la cantidad ingresada
Parámetros: 
cantidad: cantidad ingresada por el usuario
Sin valor de retorno*/
void ProductoCarrito::setCantidad(int cantidad){
    this->cantidad = cantidad;
}

string ProductoCarrito::getNombre(){
    return this->nombre;
}

int ProductoCarrito::getPrecio(){
    return this->precio;
}

/*Método getter que consulta la propiedad cantidad del producto carrito
Sin parámetros
Valor de retorno: cantidad (número de artículos) del producto carrito*/
int ProductoCarrito::getCantidad(){
    return this->cantidad;
}

/*Método que aumenta la cantidad de artículos del producto carrito
Parámetros:
cantidad: cantidad de artículos ingresada por el usuario
Sin valor de retorno*/
void ProductoCarrito::aumentaCantidad(int cantidad){
    this->cantidad += cantidad;
}

/*Método getter que consulta la propiedad id del producto carrito
Sin parámetros
Valor de retorno: id del producto carrito*/
string ProductoCarrito::getId(){
    return this->id;
}

/*Método que despliega en pantalla las propiedades del producto carrito separándolas por comas
Sin parámetros
Sin valor de retorno*/
void ProductoCarrito::mostrar(){
    cout << "| " << this->id << " | " << this->nombre << " | " << this->precio << " |  " << this->cantidad << "  | ";
}

/*Método que verifica si el id que se está pasando coincide con el id del producto carrito
Parámetros:
id: id dado
Valor de retorno: valor booleano*/
bool ProductoCarrito::verificaId(string id){
    if (this->id == id){
        return true;
    }
    else{
        return false;
    }
}

/*Método que verifica (dependiendo el caso) si la cantidad que se está ingresando no sobrepasa a la existencia del producto en almacén
Parámetros:
cantidad: cantidad de artículos del producto ingresada por el usuario
existencia: cantidad de artículos en existencia del producto en almacén
indicador: (1 o 2) indicador de qué tipo de verificación se hará con la existencia
Valor de retorno: valor booleano*/
bool ProductoCarrito::verificarCant(int cantidad, int existencia, int indicador){
    bool revision;
    if (indicador == 1){
        if (this->cantidad + cantidad <= existencia){
            revision = true;
        }
        else {
            cout << "Su pedido sobrepasa la cantidad en almacen" << endl;
            cout << "- - - - - - - - - - - - -"<<endl;
            revision = false;
        }
    }
    else if(indicador == 2){
        if (cantidad <= existencia){
            revision = true;
        }
        else {
            cout << "La nueva cantidad sobrepasa la cantidad en almacen" << endl;
            cout << "- - - - - - - - - - - - -"<<endl;
            revision = false;
        }
    }
    return revision;
}

/*Método que devuelve la multiplicación del precio unitario por la cantidad del producto carrito
Sin parámetros
Valor de retorno: subtotal del producto carrito*/
double ProductoCarrito::subtotal(){
    return this->precio * this->cantidad;
}
