#pragma once
#include "Prenda.h"

class Prenda;

class Camisa : public Prenda {
	const string nombre = "Camisa";
	Caracteristica* tipoManga = nullptr;
	Caracteristica* tipoCuello = nullptr;
public:
	Camisa(Caracteristica*, double, int, Caracteristica*, Caracteristica*);
	Camisa(Caracteristica*, Caracteristica*);
	Camisa() = default;
	~Camisa();
	double precio();
	void setTipoManga(Caracteristica* tipoManga) { this->tipoManga = tipoManga; }
	void setTipoCuello(Caracteristica* tipoCuello) { this->tipoCuello  = tipoCuello; }
	string toString();
	string getNombre() { return nombre; };
};