#include "Camisa.h"

Camisa::Camisa(Caracteristica* calidad, double precioUnitario, int stock, Caracteristica* tipoManga, Caracteristica* tipoCuello) {
	this->calidad = calidad;
	this->precioUnitario = precioUnitario;
	this->stock = stock;
	this->tipoManga = tipoManga;
	this->tipoCuello = tipoCuello;
}

Camisa::Camisa(Caracteristica* tipoManga, Caracteristica* tipoCuello) {
	this->tipoManga = tipoManga;
	this->tipoCuello = tipoCuello;
}

Camisa::~Camisa() {
	delete tipoManga;
	delete tipoCuello;
}

double Camisa::precio() {
	double descuentoManga = tipoManga->descontar(precioUnitario);
	double descuentoCuello = tipoCuello->descontar(descuentoManga);
	return calidad->descontar(descuentoCuello);
}

string Camisa::toString() {
	return nombre + " - " + tipoManga->getNombre() + " - " + tipoCuello->getNombre() + " - " + this->calidad->getNombre();
}