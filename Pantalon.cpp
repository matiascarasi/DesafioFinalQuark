#include "Pantalon.h"

Pantalon::Pantalon(Caracteristica* calidad, double precioUnitario, int stock, Caracteristica* tipoPantalon) {
	this->calidad = calidad;
	this->precioUnitario = precioUnitario;
	this->stock = stock;
	this->tipoPantalon = tipoPantalon;
}

Pantalon::Pantalon(Caracteristica* tipoPantalon) {
	this->tipoPantalon = tipoPantalon;
}

Pantalon::~Pantalon() {
	delete tipoPantalon;
}

double Pantalon::precio() {
	double descuentoPantalon = tipoPantalon->descontar(precioUnitario);
	return calidad->descontar(descuentoPantalon);
}

string Pantalon::toString() {
	return nombre + " - " + tipoPantalon->getNombre() + " - " + this->calidad->getNombre();
}