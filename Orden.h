//Guardas
#ifndef ORDEN_H
#define ORDEN_H
#include <string>
#include "Usuario.h"
#include "ProductoAlmacen.h"

class Orden
{
public:
  // Los constructores nos permite inicializar los productos
  Orden();
  Orden(ProductoAlmacen,Usuario);
  ProductoAlmacen getProducto();
  void ordenar();


private:
  int numProducto;
  std::string fechaCreacion;
  std::string fechaEnvio;
	int numUsuario;
  Usuario cliente;
  ProductoAlmacen producto;
};

#endif //ORDEN_H