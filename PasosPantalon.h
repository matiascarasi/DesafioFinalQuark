#pragma once
#include "PasosPrenda.h"
#include "Caracteristica.h"

class Caracteristica;
class PasosPrenda;

class PasosPantalon : public PasosPrenda {
	const string nombre = "Pantalon";
	Caracteristica* elegirTipoPantalon();
public:
	PasosPantalon(IVista* vista) : PasosPrenda(vista) {  };
	void elegirTipos();
	string getNombre() { return nombre; };
};