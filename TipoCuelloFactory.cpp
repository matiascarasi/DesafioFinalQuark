#include "TipoCuelloFactory.h"

map<int, Caracteristica*> TipoCuelloFactory::getCaracteristicaMap() {

	return map<int, Caracteristica*> {
		{ (int) TipoCuelloType::COMUN, new Caracteristica("Cuello comun", 1) },
		{ (int) TipoCuelloType::MAO, new Caracteristica("Cuello Mao", 1.03) }
	};
}