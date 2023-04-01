#pragma once
#include "IVista.h"
#include "Vendedor.h"
#include "Tienda.h"
#include <string>

class Vendedor;
class IVista;

class Presentador {
	IVista *vista = nullptr;
	Tienda *tienda = nullptr;
	Vendedor* vendedor = nullptr;
	string aStrDosDecimales(double);
public:
	Presentador(IVista*);
	~Presentador();
	void mostrarTienda();
	void mostrarVendedor();
	void mostrarHistorialDeCotizaciones();
	void getMapaPasosPrendas();
	void getMapaCalidades();
	bool cotizar(Prenda*, int);
};