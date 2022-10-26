/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Implementación de los métodos de la clase Almacen*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Almacen.h"

using namespace std;
    
/*Constructor del almacén que obtiene la información de un txt*/
Almacen::Almacen(){
    ifstream lector("productos.txt"); 
    string linea,
           campo;
    int num = 0;
    while (!lector.eof()){   
        getline(lector, linea);
        stringstream ss(linea);
        int cont = 0;
        string caracteristicas[4] = {}; 
        while(getline(ss, campo, ',')){  
            caracteristicas[cont] = campo; 
            cont += 1;
        }
        ProductoAlmacen produc(caracteristicas);
        this->productos[num] = produc;  // se reescribe la informacion por default que tiene el objeto en cuestion por la informacion del objeto previamente creado 
        num += 1;
        if (num == 20){
            break;
        }
    }
    lector.close();  
    this->size = num; // la propiedad size toma el valor de cuantos productos tenga el txt (cantidad de iteraciones del while)
}

/*Método para mostrar la información de cada producto del almacén
Sin párametros
Sin valor de retorno*/
void Almacen::verProductos(){
    for (int i = 0; i < this->size; i++){ 
        this->productos[i].mostrar(); 
    }
}

/*Método que verifica si el producto con el id ingresado existe en el almacén y si su cantidad es válida
Parámetros:
id: id ingresado por el usuario
cant: cantidad de artículos ingreados para el producto
carrito1: carrito del usuario
Valor de retorno: valor booleano*/
bool Almacen::verificaProductoAlmacen(string id, int cant, Carrito &carrito1){
    bool bandera = false;
    string nombre;
    double precio;
    int existencia;
    for (int i = 0; i < this->size; i++){ //revisar cada producto del almacen
        if (this->productos[i].verificaId(id) && this->productos[i].verificaExist(cant)){
            nombre = this->productos[i].getNombre();
            precio = this->productos[i].getPrecio();
            existencia = this->productos[i].getExistencia();
            if (carrito1.verificaProductoRepetido(id)){ // si esta repetido
                if (carrito1.verificaIdExistencia(id, cant, existencia, 1)){
                    cout << "Cantidad agregada al producto" << endl;
                    bandera = true;
                }
            }
            else if (carrito1.getSize() < 10){    // no esta repetido
                ProductoCarrito prodCarrito(id,nombre,precio,cant);
                carrito1.agregarProducto(prodCarrito);
                cout << "Producto agregado al carrito" << endl;
                bandera = true; 
            }
            else{
                cout << "El carrito esta lleno" << endl;
            }
            break;
        }
    }
    return bandera;
}

/*Metodo que edita las cantidades de los productos puestos en el carrito
Parámetros:
id: id ingresado del producto a editar
cant: cantidad nueva de artículos del producto a editar
carrito: carrito del usuario
Valor de retorno: valor booleano*/
bool Almacen::editarCarrito(string id, int cant, Carrito &carrito1){
    bool bandera = false;
    string nombre;
    double precio;
    int existencia;
    for (int i = 0; i < this->size; i++){ //revisar cada producto del almacen
        if (this->productos[i].verificaId(id) && this->productos[i].verificaExist(cant)){
            nombre = this->productos[i].getNombre();
            precio = this->productos[i].getPrecio();
            existencia = this->productos[i].getExistencia();
            if (carrito1.verificaProductoRepetido(id)){ // si esta repetido
                if (cant == 0){
                    carrito1.eliminarProducto(id);
                    cout << "Producto eliminado del carrito" << endl;
                    bandera = true;
                }
                else if (carrito1.verificaIdExistencia(id, cant, existencia, 2)){
                    cout << "La cantidad sobrepasa la existencia en almacen" << endl;
                    bandera = true;
                }
                else{
                    cout << "Este producto no viene en el carrito" << endl;
                }
            }
            break;
        }
    }
    return bandera;
}

/*Método para descontar de la existencia en almacén, la cantidad de artículos de cada producto en el carrito
Parámetros:
id: id del producto puesto en el carrito
cantDesc: cantidad a descontar en la existencia en almacén de dicho producto
Sin valor de retorno*/
void Almacen::descuentaArticulo(string id, int cantDesc){
    for (int i = 0; i < this->size; i++){
        if (this->productos[i].verificaId(id)){
            this->productos[i].descExistencia(cantDesc);
            break;
        }
    }
}

/*Método que muestra el total a pagar y vacía el carrito
Parámetros:
carrito: carrito del usuario
Sin valor de retorno*/
void Almacen::pagarCarrito(Carrito &carrito1){
    int cantDesc;
    string id;
    for (int i = 0; i < carrito1.getSize(); i++){
        id = carrito1.consultaIdProducto(i);
        cantDesc = carrito1.consultaCantProducto(i);
        descuentaArticulo(id, cantDesc);
    }
    cout << "Total a pagar: $" << carrito1.total() << endl;
    cout << "-------------------"<<endl;
    cout << "Su pago ha sido realizado" << endl;
    carrito1.vaciarCarrito();
}
