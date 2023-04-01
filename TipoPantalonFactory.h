#pragma once
#include "Caracteristica.h"
#include "ICaracteristicaFactory.h"
#include <map>

using namespace std;

class Caracteristica;
class ICaracteristicaFactory;

enum class TipoPantalonType { COMUN = 1, CHUPIN = 2};

class TipoPantalonFactory : public ICaracteristicaFactory {
public:
	static map<int, Caracteristica*> getCaracteristicaMap();
};
