#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Prenda.h"
#include "PasosPrenda.h"

using namespace std;

class Prenda;
class PasosPrenda;

class IVista
{
public:
	virtual ~IVista() = default;
	virtual void mostrarTexto(const string text) { cout << text << endl; };
	virtual void setMapaPasosPrendas(map<int, PasosPrenda*>) = 0;
	virtual void setMapaCalidades(map<int, Caracteristica*> ) = 0;
	virtual void setPrenda(Prenda* prenda) = 0;
	virtual void seleccionarCalidad() = 0;
	virtual void opcionInvalida() = 0;
};
