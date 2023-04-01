#pragma once
#include <string>
#include <map>
#include "Vendedor.h"

using namespace std;

class Prenda;
class Vendedor;

class Tienda {
	string nombre;
	string direccion;
	map<string, int> stockPrendas;
	string codigoTienda;
	list<Vendedor*> vendedores;
public:
	Tienda(string, string, map<string, int>);
	string getNombre() { return nombre; };
	string getDireccion() { return direccion; };
	int getStockDePrenda(string nombrePrenda) { return stockPrendas[nombrePrenda]; };
	void agregarVendedor(Vendedor* vendedor) { vendedores.push_back(vendedor); };
};