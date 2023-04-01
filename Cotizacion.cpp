#include "Cotizacion.h"

Cotizacion::Cotizacion(int id, string codigoVendedor, Prenda* prenda, int cantidad, double resultado) {
	this->id = id;
	this->codigoVendedor = codigoVendedor;
	this->prenda = prenda;
	this->cantidad = cantidad;
	this->resultado = resultado;
	this->fecha = new Fecha();
}

Cotizacion::~Cotizacion() {
	delete fecha;
	delete prenda;
}