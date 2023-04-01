#pragma once
#include "Prenda.h"

class Prenda;

class Pantalon : public Prenda {
	const string nombre = "Pantalon";
	Caracteristica* tipoPantalon = nullptr;
public:
	Pantalon(Caracteristica*, double, int, Caracteristica*);
	Pantalon(Caracteristica*);
	Pantalon() = default;
	~Pantalon();
	double precio();
	void setTipoPantalon(Caracteristica*) { this->tipoPantalon = tipoPantalon; };
	string toString();
	string getNombre() { return nombre; };
};