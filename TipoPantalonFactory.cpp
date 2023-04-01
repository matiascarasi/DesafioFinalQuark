#include "TipoPantalonFactory.h"

map<int, Caracteristica*> TipoPantalonFactory::getCaracteristicaMap() {
	return map<int, Caracteristica*> {
		{(int)TipoPantalonType::COMUN, new Caracteristica("Comun", 1)},
		{(int)TipoPantalonType::CHUPIN, new Caracteristica("Chupin", 0.88)}
	};
}