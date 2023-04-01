#include "Tienda.h"

Tienda::Tienda(string nombre, string direccion, map<string, int> stockPrendas) {
	this->nombre = nombre;
	this->direccion = direccion;
	this->stockPrendas = stockPrendas;
}