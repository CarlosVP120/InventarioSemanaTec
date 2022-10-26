/*Autores:
Ekaterina Schoofiled Sepúlveda A01641148
Alan Antonio Ruelas Robles A01641426
Diciembre 3, 2021
Main en donde se presentan las opciones al usuario y se interactúa con él*/

#include <iostream>
#include "Almacen.h"
#include "Carrito.h"
#include <cctype>

using namespace std;

int main(){
    int opcion = 0,
        cant = 0;
    string id,
           nomUsuario;
    char resp;
    Almacen almacen1;
    Carrito carrito1;

    cout << "Ingrese su nombre: ";
    cin >> nomUsuario;
    carrito1.setCliente(nomUsuario);

    do{
        cout << "-------------------"<<endl;
        cout << "MENU DE OPCIONES:" << endl;
        cout << "-------------------"<<endl;
        cout << "1) Ver productos" << endl;
        cout << "2) Comprar" << endl;
        cout << "3) Ver carrito" << endl;
        cout << "4) Editar" << endl;
        cout << "5) Pagar" << endl;
        cout << "6) Salir" << endl;
        cout << "-------------------"<< endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "-------------------"<< endl;

        if (opcion == 1){
            cout << "       PRODUCTOS DE ALMACEN:"<< endl;
            cout << endl;
            almacen1.verProductos();
        }
        else if (opcion == 2){
            resp = 'N';
            while (toupper(resp) == 'N'){
                cout << "ID: ";
                cin >> id; 
                cout << endl;
                cant = -1;
                while (cant <= 0){
                    cout << "Cantidad: ";
                    cin >> cant;
                    if (cant <= 0){
                        cout << "\tCantidad no valida" << endl;
                    }
                }
                cout << endl;
                cout << "Ha pedido " << cant << " articulos del producto " << id << endl;
                cout << "Es correcto (S/N)? ";
                cin >> resp;
                cout << "-------------------"<< endl;
            }
            if (almacen1.verificaProductoAlmacen(id, cant, carrito1)){
                cout << "Accion realizada" << endl;
                cout << "-------------------"<< endl;
            }
            else{
                cout << "Producto no disponible" << endl << endl;
            }
        }
        else if (opcion == 3){
            carrito1.verCarrito();
        }
        else if (opcion == 4){
            resp = 'N';
            while (toupper(resp) == 'N'){
                cout << "ID: ";
                cin >> id;
                cout << endl;
                cant = -1;
                while (cant < 0){
                    cout << "Cantidad (ingrese 0 para eliminar): ";
                    cin >> cant;
                    if (cant < 0){
                        cout << "\tCantidad no valida" << endl;
                    }
                }
                cout << endl;
                cout << "Ha pedido " << cant << " articulos del producto " << id << endl;
                cout << "Es correcto (S/N)? ";
                cin >> resp;
                cout << "-------------------"<< endl;     
            }
            if (almacen1.editarCarrito(id, cant, carrito1)){
                cout << "Producto modificado" << endl << endl;;
            }
            else{
                cout << "Accion invalida" << endl << endl;;
            }
        }
        else if (opcion == 5){
            cout << "       PROCESO DE PAGO:"<< endl;
            cout << endl;
            if (carrito1.getSize() == 0){
                cout << "No hay nada por pagar" << endl;
            }
            else{
                almacen1.pagarCarrito(carrito1);
                cout << endl << "   Gracias por su compra!" << endl;
            }
        }
        else if (opcion == 6){
            cout << "-------------------"<< endl;
            cout << "Hasta luego!" << endl;
            cout << "-------------------"<< endl;
        }
        else{
            cout << "-------------------"<< endl;
            cout << "Opcion invalida, intentelo de nuevo" << endl;
            cout << "-------------------"<< endl;
        }
    } while (opcion != 6);
    return 0;
}