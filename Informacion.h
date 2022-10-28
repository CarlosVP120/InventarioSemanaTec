//Guardas
#ifndef INFORMACION_H
#define INFORMACION_H
#include <string>
#include "Orden.h"

class Informacion
{
public:
  // Los constructores nos permite inicializar los productos
  Informacion(Orden, int);
	float getSubtotal();
  void imprime();

private:
  string numProducto;
  int cantidad;
	float subtotal;
  ProductoAlmacen producto;

};

#endif //INFORMACION_H