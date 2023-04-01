#pragma once
#include <string>
#include <list>
#include "Cotizacion.h"
#include "Prenda.h"

using namespace std;

class Prenda;
class Cotizacion;

class Vendedor {
	string nombre;
	string apellido;
	string codigoVendedor;
	list<Cotizacion*> historialCotizaciones;
	string codigoTienda;
public:
	Vendedor(string, string, string);
	bool cotizar(Prenda*, int);
	string getNombre() { return nombre; };
	string getApellido() { return apellido; };
	string getCodigoVendedor() { return codigoVendedor; };
	list<Cotizacion*> getHistorialCotizaciones() { return historialCotizaciones; };
};