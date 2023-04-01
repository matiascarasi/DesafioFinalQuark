#pragma once
#include "Caracteristica.h"
#include "ICaracteristicaFactory.h"
#include <map>

using namespace std;

class Caracteristica;
class ICaracteristicaFactory;

enum class CalidadType { STANDARD=1, PREMIUM=2 };

class CalidadFactory : public ICaracteristicaFactory {
public:
	static map<int, Caracteristica*> getCaracteristicaMap();
};