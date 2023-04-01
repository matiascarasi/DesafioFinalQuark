#pragma once
#include "Caracteristica.h"
#include "ICaracteristicaFactory.h"
#include <map>

using namespace std;

class Caracteristica;
class ICaracteristicaFactory;

enum class TipoMangaType { CORTA = 1, LARGA = 2 };

class TipoMangaFactory : public ICaracteristicaFactory {
public:
	static map<int, Caracteristica*> getCaracteristicaMap();
};