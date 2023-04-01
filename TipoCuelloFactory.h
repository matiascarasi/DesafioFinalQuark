#pragma once
#include "Caracteristica.h"
#include "ICaracteristicaFactory.h"
#include <map>

using namespace std;

class Caracteristica;
class ICaracteristicaFactory;

enum class TipoCuelloType  { COMUN = 1, MAO = 2 };

class TipoCuelloFactory : public ICaracteristicaFactory {
public:
	static map<int, Caracteristica*> getCaracteristicaMap();
};