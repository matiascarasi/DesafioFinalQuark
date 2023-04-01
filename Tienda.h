#pragma once
#include <string>
#include <map>

using namespace std;

class Prenda;

class Tienda {
	string nombre;
	string direccion;
	map<string, int> stockPrendas;
public:
	Tienda(string, string, map<string, int>);
	string getNombre() { return nombre; };
	string getDireccion() { return direccion; };
	int getStockDePrenda(string nombrePrenda) { return stockPrendas[nombrePrenda]; };
};