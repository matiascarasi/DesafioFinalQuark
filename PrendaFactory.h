#pragma once
#include <map>
#include "Prenda.h"
#include "PasosPrenda.h"

using namespace std;

class Prenda;
class PasosPrenda;

enum class PrendaType {
	CAMISA=1,
	PANTALON=2
};

class PrendaFactory {
public:
	Prenda* getPrenda(char);
	static map<int, Prenda*> getPrendaMap();
	static map<int, PasosPrenda*> getPasosPrendaMap(IVista*);
};