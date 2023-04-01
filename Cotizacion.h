#pragma once
#include <string>
#include "Fecha.h"

using namespace std;

class Fecha;
class Prenda;

class Cotizacion {
	int id;
	Fecha *fecha = nullptr;
	string codigoVendedor;
	Prenda *prenda = nullptr;
	int cantidad;
	double resultado;
public:
	Cotizacion(int, string, Prenda*, int, double);
	~Cotizacion();
	int getId() { return id; };
	Fecha* getFecha() { return fecha; };
	string getCodigoVendedor() { return codigoVendedor; };
	Prenda* getPrenda() { return prenda; };
	int getCantidad() { return cantidad; };
	double getResultado() { return resultado; };
};