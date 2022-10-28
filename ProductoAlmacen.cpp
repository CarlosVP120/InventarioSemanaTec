/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Implementación de los métodos de la clase ProductoAlamcen*/

#include <iostream>
#include <string>
#include "ProductoAlmacen.h"

using namespace std;

/*Constructor por default de los productos del almacén, con información vacía*/
ProductoAlmacen::ProductoAlmacen(){
    this->id = "";
    this->nombre = "";
    this->precio = 0;
    this->existencia = 0;
}

/*Constructor con parámetros de los productos almacén
Parámetros:
caracteristicas: arreglo con las características obtenidas del txt*/
ProductoAlmacen::ProductoAlmacen(string caracteristicas[]){
    // se guarda en cada propiedad el elemento de la lista caracteristicas correspondiente
    this->id = caracteristicas[0];
    this->nombre = caracteristicas[1];
    this->precio = stod(caracteristicas[2]);
    this->existencia = stoi(caracteristicas[3]);
}

/*Método getter que devuelve la propiedad nombre del producto almacén
Sin parámetros
Valor de retorno: nombre del producto almacén*/
string ProductoAlmacen::getNombre(){
    return this->nombre;
}

/*Método getter que devuelve la propiedad precio del producto almacén
Sin parametros
Valor de retorno: precio del producto almacén*/
double ProductoAlmacen::getPrecio(){
    return this->precio;
}

/*Método que devuelve la propiedad existencia del producto almacén
Sin parámetros
Valor de retorno: existencia del producto almacén*/
int ProductoAlmacen::getExistencia(){
    return this->existencia;
}

/*Método que imprime en pantalla cada propiedad del producto almacén separándola por comas
Sin parámetros
Sin valor de retorno*/
void ProductoAlmacen::mostrar(){
    cout << "---------------------------" <<endl;
    cout << "Producto: " << this->nombre << endl;
    cout << "Precio: $"<< this->precio << endl;
    cout << "ID: " << this->id << endl;
    cout << "Existencia: " << this->existencia << endl;
}

/*Método que verifica si el id que se esta pasando coincide con el id del producto almacén
Parámetros:
id: id dado 
Valor de retorno: valor booleano*/
bool ProductoAlmacen::verificaId(string id){
    if (this->id == id){
        return true;
    }
    else{
        return false;
    }
}

string ProductoAlmacen::getId(){
    return this->id;
}

/*Método que verifica si la cantidad ingresada no sobrepasa la existencia del producto en almacén
Parámetros: 
cant: cantidad ingresada por el usuario
Valor de retorno: valor booleano*/
bool ProductoAlmacen::verificaExist(int cant){
    if (this->existencia - cant >= 0){
        return true;
    }
    else{
        return false;
    }
}

/*Método que le resta a la existencia del producto en almacén la cantidad del mismo en el carrito
Parámetros: 
cantDesc: cantidad a desocontarle a la existencia
Sin valor de retorno*/
void ProductoAlmacen::descExistencia(int cantDesc){
    this->existencia -= cantDesc;
}
