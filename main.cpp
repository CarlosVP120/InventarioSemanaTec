#include <iostream>
#include "Almacen.h"
#include "Carrito.h"
#include "Usuario.h"
#include "Orden.h"
#include "Informacion.h"
#include <limits>
#include <cctype>

using namespace std;

int main(){
    system("clear");
    int opcion = 0,
    cant = 0;
    string id,
    nomUsuario;
    char resp;
    Almacen almacen1;
    
    int subtotCarrito = 0;

    int registro, tarjeta;
    char opc, nom[30], direccion[30];
    string email, contra;
    Usuario usuario;
    Carrito carrito1(usuario);
    int indices[100];
    int numIndices = 0;
    int total = 0;
    
    // create an array of undefined size
    Orden ordenes[100];

	cout << "\nPROYECTO INTEGRADOR: COMERCIO ELECTRONICO\nA01641147\nA01641113";
	cout << "\n- - - - - - - - - - - - -" << endl;

	cout << "¿Deseas registrarte?  [1] Si / [2] No" << endl;
	cin >> registro;

    while (registro > 2 || registro < 1){
		cout << "\n- - - - - - - - - - - - -" << endl;
        cout << "Ingrese una opcion valida..." << endl;
        cout << "¿Deseas registrarte?  [1] Si / [2] No" << endl;
	    cin >> registro;
    }    

	if (registro == 1) {
        cin.ignore(numeric_limits<int>::max(),'\n');
		cout <<  "Ingresa tu nombre: ";
		cin.getline(nom,30);
        carrito1.setCliente(nom);
		cout <<  "Ingresa tu email: " ;
		cin >> email;
        cout <<  "Ingresa tu contrasena: " ;
		cin >> contra;
		cout <<  "Ingresa tu direccion: " ;
        cin.ignore(numeric_limits<int>::max(),'\n');
		cin.getline(direccion,30);
		cout <<  "Ingresa tu numero tarjeta: " ;
		cin >> tarjeta;
        usuario = Usuario (nom,email,contra,direccion,tarjeta);
        system("clear"); 
        cout << "- - - - - - - - - - - - -" << endl;
		cout <<  "¡Bienvenid@ "<< usuario.getNombre() << "!" << endl;
        cout <<  "Tu ID es... "<< usuario.getNumUsuario() << endl;
		cout << "Te recomendamos guardar tu ID para poder realizar compras mas tarde";
    }  
        
    else if (registro == 2) {
        cout << "- - - - - - - - - - - - -" << endl;
        cout <<  "¡Bienvenid@! has iniciado sesión como "<< usuario.getNombre() << "!" << endl;
        cout <<  "El modo invitado no permite realizar compras, te recomendamos registrarte..." << endl;
    }

    do{

        // cout << "-------------------"<<endl;
        // cout << "MENU DE OPCIONES:" << endl;
        // cout << "-------------------"<<endl;
        // cout << "1) Ver productos" << endl;
        // cout << "2) Comprar" << endl;
        // cout << "3) Ver carrito" << endl;
        // cout << "4) Editar" << endl;
        // cout << "5) Pagar" << endl;
        // cout << "6) Salir" << endl;
        // cout << "-------------------"<< endl;
        // cout << "Seleccione una opcion: ";
        // cin >> opcion;
        // cout << "-------------------"<< endl;

        cout << "\n- - - - - - - - - - - - -" << endl;
		cout << "MENÚ DE OPCIONES\n\n\t[1] Ver catalogo de productos\n\t[2] Mi Usuario\n\t[3] Comprar producto\n\t[4] Ver carrito\n\t[5] Editar\n\t[6] Confirmar\n\n\t[7] Salir";
		cout << "\n\nIngresa la opción que deseas ejecutar: ";
		cin >> opcion;
		cout << "- - - - - - - - - - - - -" << endl;

        if (opcion == 1){
            system("clear");

            cout << "- - CATALOGO DE PRODUCTOS - -\n" << endl;
			cout << "| ID | PRODUCTO | PRECIO | CANTIDAD |\n" << endl;
            almacen1.verProductos();
        } 

        else if (opcion == 2) {
            int actUsuario;
            system("clear");
            cout << "- - MI USUARIO - -" << endl;
            usuario.imprime();

            if (usuario.getNumUsuario() != 0) {

                cout << "¿Deseas actualizar tu usuario?  [1] Si / [2] No" << endl ;
                cin >> actUsuario;
                if (actUsuario == 1) {

                string email;
                string contra;
                int tarjeta;
                char opc, nombre[30],direccion[30];
                
                do {
                    cout << "Actualizar usuario\n\n\t[1] Nombre\n\t[2] Email\n\t[3] Contraseña\n\t[4] Direccion\n\t[5] Numero de tarjeta\n\n\t[6] Salir" ;
                    cout << "\n\nIngresa la opción que deseas ejecutar: ";
                    cin >> opc;

                    switch (opc) {
                    
                    case '1':
                        cout << "- - - - - - - - - - - - -" << endl;
                        cout << "Ingrese su nuevo nombre de usuario..." << endl;
                        cin.ignore(numeric_limits<int>::max(),'\n');
                        cin.getline(nombre,30);
                        usuario.setNombre(nombre);
                        carrito1.setCliente(nombre);
                        cout << "- - - - - - - - - - - - -" << endl;
                        break;

                    case '2':
                        cout << "- - - - - - - - - - - - -" << endl;
                        cout << "Ingrese su nuevo email..." << endl;
                        cin >> email;
                        usuario.setEmail(email);
                        cout << "- - - - - - - - - - - - -" << endl;
                        break;

                    case '3':
                        cout << "- - - - - - - - - - - - -" << endl;
                        cout << "Ingrese su nueva contrasena..." << endl;
                        cin >> contra;
                        usuario.setContrasena(contra);
                        cout << "- - - - - - - - - - - - -" << endl;
                        break;

                    case '4':
                        cout << "- - - - - - - - - - - - -" << endl;
                        cout << "Ingrese su nueva direccion..." << endl;
                        cin.ignore(numeric_limits<int>::max(),'\n');
                        cin.getline(direccion,40);
                        usuario.setDireccion(direccion);
                        cout << "- - - - - - - - - - - - -" << endl;
                        break;

                    case '5':
                        cout << "- - - - - - - - - - - - -" << endl;
                        cout << "Ingrese su nuevo numero de tarjeta..." << endl;
                        cin >> tarjeta;
                        usuario.setNumTarjeta(tarjeta);
                        cout << "- - - - - - - - - - - - -" << endl;
                        break;
                    
                    case '6':
                        cout << "- - - - - - - - - - - - -" << endl;
                        cout << "Saliendo..." << endl;
                        break;

                    default:
                        cout << "Ingrese una opción válida\n" << endl;
                    }
                } while (opc != '6');
            }
        }
        
        else {
            cout << "No puede actualizar su informacion siendo invitado...\n" << endl;
        }
        
        }

        else if (opcion == 3){
            int cont, confirmarOrdenes,IDeliminarProducto, eliminados, cant;
            string idP;
            eliminados = 0;
            cont = 0;
            idP = 1;
            IDeliminarProducto = 1;

            system("clear");
            cout << "- - COMPRAR PRODUCTO - -" << endl;
            if (usuario.getNumUsuario() != 0) {
                almacen1.imprimeVertical();
                
                cout << "\nIngresa '0' cuando ya no desees comprar otro producto\n" << endl;
                cout << "- - - - - - - - - - - - -" << endl;

                while ( true ) {
                    cout << "Ingresa el 'ID' del producto que deseas comprar: ";
                    cin >> idP;
                    if ( idP == "0" ) {
                        break;
                    }
                    cout << endl;
                    cant = -1;
                    while (cant <= 0){
                        cout << "Cantidad: ";
                        cin >> cant;
                        if (cant <= 0){
                            cout << "\tCantidad no valida" << endl;
                        }
                    }
                    cout << "\n- - - - - - - - - - - - -" << endl;
                    cout << "¿Desea confirmar su orden?  [1] Si / [2] Cancelar orden"<< endl;
                    cin >> confirmarOrdenes;
                    if (almacen1.verificaProductoAlmacen(idP, cant, carrito1) && confirmarOrdenes == 1){
                        cout << "- - - - - - - - - - - - -"<< endl;
                        indices[cont] = almacen1.buscarIndice(idP);
                        numIndices++;
                        subtotCarrito += carrito1.consultaPrecioProducto(cont) * cant;
                        cont++;
                    }
                    else{
                        cout << "Producto no disponible" << endl << endl;
                    }
                }
            
                system("clear");

                cout << "\n- - LISTA DE TUS PRODUCTOS - -\n" << endl;

                cout << "| PRODUCTO | ID | PRECIO | CANTIDAD |\n" << endl;
                for(int i = 0; i < cont; i = i + 1) {
                    cout << "| "  << carrito1.consultaNombreProducto(i) << " | " << carrito1.consultaIdProducto(i) << " | $" << carrito1.consultaPrecioProducto(i) << " | " << carrito1.consultaCantProducto(i) << endl;
                }

                cout <<  endl << "¡Excelente "<< usuario.getNombre() <<"! se han generado las siguientes ordenes..." << endl;

                for(int i = 0; i < cont; i = i + 1) {
                    ordenes[i] = Orden (almacen1.getProducto(indices[i]), usuario);
                    ordenes[i].ordenar();
                }

                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Subtotal de compra:  $ "<< subtotCarrito << endl;
                cout << "\n- - - - - - - - - - - - -" << endl;
            }
            
            else {
                cout << "\nNo puede comprar productos siendo invitado...\n" << endl;
            }    
    
        }
        else if (opcion == 4){
            carrito1.verCarrito();
        }
    
        else if (opcion == 5){
            string idP;
            int confirmarEdicion, cant;

            system("clear");
            cout << "- - EDITAR CARRITO - -" << endl;

            carrito1.verCarrito();

            cout << "\nIngresa '0' cuando ya no desees comprar otro producto\n" << endl;
            cout << "- - - - - - - - - - - - -" << endl;

            while ( true ) {
                cout << "Ingresa el 'ID' del producto que deseas modificar: ";
                cin >> idP;
                if ( idP == "0" ) {
                    break;
                }
                cout << endl;
                cant = -1;
                while (cant <= 0){
                    cout << "Cantidad: ";
                    cin >> cant;
                    if (cant <= 0){
                        cout << "\tCantidad no valida" << endl;
                    }
                }
                cout << "\n- - - - - - - - - - - - -" << endl;
                cout << "¿Desea confirmar la edición su orden?  [1] Si / [2] No"<< endl;
                cin >> confirmarEdicion;
                if (almacen1.editarCarrito(idP, cant, carrito1) && confirmarEdicion == 1){
                    cout << "- - - - - - - - - - - - -"<< endl;
                    cout << "Modificacion exitosa" << endl << endl;
                }
                else{
                    cout << "No se pudo realizar la modificacion..." << endl << endl;
                }
            }
        }

        else if (opcion == 6){
            float total;
            int confirmarPago;
            total = 0;
            if (usuario.getNumUsuario() != 0) {
                system("clear");
                cout << "- - ORDEN Y DETALLES - -" << endl;
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Estas son sus ordenes a pagar...\n" << endl;

                for(int i = 0; i < numIndices; i = i + 1) {
                    ordenes[i] = Orden (almacen1.getProducto(indices[i]), usuario);
                    ordenes[i].ordenar();
                }
                

                cout << endl << "Total a pagar: $" << subtotCarrito << endl;
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Para confirmar y pagar ingrese su ID... (si olvidaste tu ID recuerda que puedes verlo en la opcion 'Mi Usuario') " << usuario.getNumUsuario() << endl;
                cout << "Para seguir comprando ingrese 0" << endl;
                cin >> confirmarPago;

                if (confirmarPago == usuario.getNumUsuario()) {
                system("clear");
                cout << "\n- - - - - - - - - - - - -" << endl;
                cout << "¡Felicidades " << usuario.getNombre() << "!" << endl;
                cout << "El siguiente pedido será enviado a " << usuario.getDireccion() << " en 2-5 días hábiles...\n" << endl;
                carrito1.verCarrito();
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Pago de $" << subtotCarrito << " realizado correctamente, a la tarjeta " << "***" << to_string(usuario.getNumTarjeta()).substr(to_string(usuario.getNumTarjeta()).length() - 3, 3) << "\n¡Gracias por su compra!" << endl;
                opc = '7';
                }
                else if (confirmarPago != 0) {
                cout << "\nOpcion invalida... Regresando al menu...\n" << endl;
                }
            }

            else {
                cout << "\nNo puede ver sus ordenes siendo invitado...\n" << endl;
            } 
        }
        

        else if (opcion == 7){
            cout << "- - - - - - - - - - - - -"<< endl;
            cout << "Hasta luego!" << endl;
            cout << "- - - - - - - - - - - - -"<< endl;
        }
        else{
            cout << "- - - - - - - - - - - - -"<< endl;
            cout << "Opcion invalida, intentelo de nuevo" << endl;
            cout << "- - - - - - - - - - - - -"<< endl;
        }
        cin.ignore();
		cout << "\nPresiona enter para continuar...";
		cin.get();
        system("clear");
    } while (opcion != 7);
    return 0;
}