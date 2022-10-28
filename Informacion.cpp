#include "Informacion.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>

Informacion::Informacion(Orden _orden, int _cantidad) {
  producto = _orden.getProducto();
  cantidad = _cantidad;
  subtotal = producto.getPrecio() + producto.getPrecio()*0.16;
  numProducto = producto.getId();
}

float Informacion::getSubtotal() {
  return subtotal;
}

void Informacion::imprime() {
  std::cout << "\n---Detalles de Orden---\n" << std::endl;
  std::cout << "Numero de producto: " << numProducto << std::endl;
	std::cout << "Cantidad: " << cantidad << std::endl;
  std::cout << "Subtotal con IVA: " << subtotal << std::endl;
  std::cout << "Producto: " << producto.getNombre() << std::endl;
  std::cout << "----------------------------" << std::endl;
}
  