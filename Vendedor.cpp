#include "Vendedor.h"

Vendedor::Vendedor(string nombre, string apellido, string codigoVendedor){
	this->nombre = nombre;
	this->apellido = apellido;
	this->codigoVendedor = codigoVendedor;
}

bool Vendedor::cotizar(Prenda *prenda, int cantidad) {

	if (prenda->getStock() < cantidad) {
		return false;
	}

	int id = historialCotizaciones.size() + 1;
	double resultado = prenda->precio() * cantidad;

	Cotizacion* cotizacion = new Cotizacion(id, codigoVendedor, prenda, cantidad, resultado);
	historialCotizaciones.push_back(cotizacion);

	return true;

};