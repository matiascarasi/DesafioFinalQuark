#pragma once
#include "Caracteristica.h"

class Caracteristica;

class Prenda {
protected:
	string nombre;
	Caracteristica *calidad = nullptr;
	double precioUnitario = 0;
	int stock = 0;
public:
	virtual double precio() = 0;
	virtual ~Prenda() { delete calidad; };
	int getStock() { return stock; };
	virtual string toString() = 0;
	double getPrecioUnitario() { return precioUnitario; };
	virtual string getNombre() = 0;
	void setCalidad(Caracteristica* calidad) { this->calidad = calidad; };
	void setPrecioUnitario(double precioUnitario) { this->precioUnitario = precioUnitario; };
	void setStock(int stock) { this->stock = stock; };
};