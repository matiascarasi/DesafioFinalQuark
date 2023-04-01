#include "CalidadFactory.h"

map<int, Caracteristica*> CalidadFactory::getCaracteristicaMap() {
	return map<int, Caracteristica*> {
		{(int)CalidadType::STANDARD, new Caracteristica("Standard", 1)},
		{(int)CalidadType::PREMIUM, new Caracteristica("Premium", 1.3)}
	};
}