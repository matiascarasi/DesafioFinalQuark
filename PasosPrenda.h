#pragma once
#include "IVista.h"
#include "Prenda.h"

class IVista;
class Prenda;

class PasosPrenda {
protected:
	IVista* vista = nullptr;
	Prenda* prenda = nullptr;
public:
	PasosPrenda(IVista*);
	virtual ~PasosPrenda();
	virtual void elegirTipos() = 0;
	virtual string getNombre() = 0;
};