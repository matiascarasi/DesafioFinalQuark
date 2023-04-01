#pragma once
#include <string>

using namespace std;

class Caracteristica {
	string nombre;
	double descuento;
public:
	Caracteristica(string nombre, double descuento);
	double descontar(double precio) { return precio * descuento; };
	string getNombre() { return nombre; };
};