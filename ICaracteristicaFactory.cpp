#include "ICaracteristicaFactory.h"

Caracteristica* ICaracteristicaFactory::getCaracteristica(int caracteristica) {
	auto caracteristicas = getCaracteristicaMap();
	if (caracteristicas.count(caracteristica) == 0) {
		return nullptr;
	}
	return caracteristicas[caracteristica];
}