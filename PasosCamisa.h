#pragma once
#include "PasosPrenda.h"
#include "Caracteristica.h"

class Caracteristica;
class PasosPrenda;

class PasosCamisa : public PasosPrenda {
	const string nombre = "Camisa";
	Caracteristica* elegirTipoCuello();
	Caracteristica* elegirTipoManga();
public:
	PasosCamisa(IVista* vista) : PasosPrenda(vista) {  };
	void elegirTipos();
	string getNombre() { return nombre; };
};