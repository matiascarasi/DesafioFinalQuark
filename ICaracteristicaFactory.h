#pragma once
#include "Caracteristica.h"
#include <map>

using namespace std;

class Caracteristica;

class ICaracteristicaFactory {
public:
	Caracteristica* getCaracteristica(int);
	virtual map<int, Caracteristica*> getCaracteristicaMap() = 0;
};