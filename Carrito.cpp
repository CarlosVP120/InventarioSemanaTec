/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Implementación de los métodos de la clase Carrito*/

#include <iostream>
#include <string>
#include "Carrito.h"
#include "Almacen.h"

using namespace std;

/*Constructor default del almacén con información vacía*/
Carrito::Carrito(){
    this->cliente = "";
    this->productos[10];
    this->size = 0;
}

/*Metodo setter que le asigna a la propiedad cliente del carrito el nombre del usuario
Parámetros:
nomUsuario: nombre del usuario
Sin valor de retorno*/
void Carrito::setCliente(string nomUsuario){
    this->cliente = nomUsuario;
}

/*Método que consulta la propiedad size del carrito
Sin párametros
Valor de retorno: tamaño del carrito (número de artículos)*/
int Carrito::getSize(){
    return this->size;
}

/*Método que le agrega un producto al carrito y aumenta el tamaño de éste
Parámetros:
prodCarrito: objeto producto carrito con la información ingresada
Sin valor de retorno*/
void Carrito::agregarProducto(ProductoCarrito prodCarrito){
    this->productos[this->size] = prodCarrito;
    this->size += 1;
}

/*Método que muestra en pantalla la información de cada producto del carrito
Sin párametros
Sin valor de retorno*/
void Carrito::verCarrito(){
    cout << "       CARRITO:"<<endl;
    cout << endl;
    cout << "Carrito de compras de " << this->cliente << endl;
    cout << endl;
    cout << "Id,nombre,precio,cantidad,subtotal" << endl;
    if (this->size == 0){
        cout << "  Carrito vacio" << endl;
    }
    else{
        for (int i = 0; i < this->size; i++){
            cout << "  ";
            this->productos[i].mostrar();
            cout << "\t\t\t$" << this->productos[i].subtotal() << endl;
        }
    }
}

/*Método que revisa todos los productos del carrito en busca de si el id ingresado ya estaba en el carrito
Parámetros: id ingresado por el usuario
Valor de retorno: valor booleano*/
bool Carrito::verificaProductoRepetido(string id){
    bool bandera = false;
    for (int i = 0; i < this->size; i++){
        if(this->productos[i].verificaId(id)){
            bandera = true;
        }
    }
    return bandera;
}

/*Método que revisa los productos del carrito para modificar su cantidad
Parámetros:
id: id del producto ingresado por el usuario
cant: cantidad de articulos del producto ingresado por el usuario
existencia: existencia del producto en almacén
indicador: (1 ó 2) indicador de qué tipo de cambio se le hará a la cantidad del producto en el carrito
Valor de retorno: valor booleano*/
bool Carrito::verificaIdExistencia(string id, int cant, int existencia, int indicador){
    bool bandera = false;
    for (int i = 0; i < this->size; i++){ //revisar cada producto del carrito
        if (this->productos[i].verificaId(id) && this->productos[i].verificarCant(cant, existencia, indicador)){
            if (indicador == 1){
                this->productos[i].aumentaCantidad(cant);
            }
            else if (indicador == 2){
                this->productos[i].setCantidad(cant);
            }
            bandera = true;
            break;
        }
    }
    return bandera;
}

/*Método que consulta el id del producto en cierta posición
Parámetros:
indice: índice del elemento del arreglo de productos carrito
Valor de retorno: id del producto en la posición índice*/
string Carrito::consultaIdProducto(int indice){
    return this->productos[indice].getId();
}

/*Método que consulta la cantidad de artículos del producto en cierta posición
Parámetros:
indice: índice del elemento del arreglo de productos carrito
Valor de retorno: cantidad de articulos del producto en la posicion índice*/
int Carrito::consultaCantProducto(int indice){
    return this->productos[indice].getCantidad();
}

/*Método que le asigna a cada producto del carrito información vacía (por default)
Sin parámetros
Sin valor de retorno*/
void Carrito::vaciarCarrito(){
    for (int i = 0; i < this->size; i++){
        ProductoCarrito productoVacio;
        this->productos[i] = productoVacio;
    }
    this->size = 0;
}

/*Método que suma los subtotales de cada producto del carrito
Sin párametros
Valor de retorno: precio total del carrito*/
double Carrito::total(){
    double totalNeto = 0;
    for (int i = 0; i < this->size; i++){
        totalNeto += this->productos[i].subtotal();
    }
    return totalNeto;
}

/*Método que identifica la posición del producto a eliminar y empieza a recorrer hacia atrás los productos despues de este,
así como disminuir el tamaño del carrito
Parámetros:
id: id ingresado por el usuario del producto a eliminar
Sin valor de retorno*/
void Carrito::eliminarProducto(string id){
    int n = 0;
    for (int i = 0; i < this->size; i++){
        if (this->productos[i].verificaId(id)){
            n = i;
            while (n < this->size-1){
                this->productos[n] = this->productos[n+1];
                n++;
            }
            break;
        }
    }
    this->size -= 1;
}
