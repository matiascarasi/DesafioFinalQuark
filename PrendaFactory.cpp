#include "PrendaFactory.h"
#include "Camisa.h"
#include "Pantalon.h"
#include "PasosCamisa.h"
#include "PasosPantalon.h"

Prenda* PrendaFactory::getPrenda(char prenda) {
	auto prendas = getPrendaMap();
	if (prendas.count(prenda) == 0) {
		return nullptr;
	}
	return prendas[prenda];
}

map<int, Prenda*> PrendaFactory::getPrendaMap() {
	return map<int, Prenda*> {
		{ (int)PrendaType::CAMISA, new Camisa()},
		{ (int)PrendaType::PANTALON, new Pantalon() }
	};
}

map<int, PasosPrenda*> PrendaFactory::getPasosPrendaMap(IVista *vista) {
	return map<int, PasosPrenda*> {
		{ (int)PrendaType::CAMISA, new PasosCamisa(vista)},
		{ (int)PrendaType::PANTALON, new PasosPantalon(vista) }
	};
}