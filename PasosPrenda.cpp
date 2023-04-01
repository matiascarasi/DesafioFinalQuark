#include "PasosPrenda.h"

PasosPrenda::PasosPrenda(IVista *vista) {
	this->vista = vista;
}

PasosPrenda::~PasosPrenda() {
	delete vista;
	delete prenda;
}