#include "Presentador.h"
#include "PrendaFactory.h"
#include "CalidadFactory.h"
#include <sstream>
#include <iomanip>

Presentador::Presentador(IVista* vista) {
	this->vista = vista;

	map<string, int> stockTienda{
		{ "Camisa - Manga corta - Cuello comun - Standard", 150 },
		{ "Camisa - Manga corta - Cuello comun - Premium", 150 },
		{ "Camisa - Manga corta - Cuello Mao - Standard", 100 },
		{ "Camisa - Manga corta - Cuello Mao - Premium", 100 },
		{ "Camisa - Manga larga - Cuello comun - Standard", 175 },
		{ "Camisa - Manga larga - Cuello comun - Premium", 175 },
		{ "Camisa - Manga larga - Cuello Mao - Standard", 75 },
		{ "Camisa - Manga larga - Cuello Mao - Premium", 75 },
		{ "Pantalon - Comun - Standard", 250 },
		{ "Pantalon - Comun - Premium", 250 },
		{ "Pantalon - Chupin - Standard", 750 },
		{ "Pantalon - Chupin - Premium", 750 },
	};

	tienda = new Tienda("Quark Academy", "Calle Falsa 1234", stockTienda);
	vendedor = new Vendedor("Matias", "Carasi", "ABC123");
}

Presentador::~Presentador() {
	delete vista;
	delete vendedor;
}

void Presentador::mostrarTienda() { 
	vista->mostrarTexto(tienda->getNombre() + " | " + tienda->getDireccion()); 
}

void Presentador::mostrarVendedor() {
	vista->mostrarTexto(vendedor->getNombre() + " " + vendedor->getApellido() + " | " + vendedor->getCodigoVendedor());
}

void Presentador::mostrarHistorialDeCotizaciones() {
	for (Cotizacion* cotizacion : vendedor->getHistorialCotizaciones()) {
		vista->mostrarTexto("Numero de identificacion: " + to_string(cotizacion->getId()));
		vista->mostrarTexto("Fecha y Hora de la cotizacion: " + cotizacion->getFecha()->toString());
		vista->mostrarTexto("Codigo del Vendedor: " + cotizacion->getCodigoVendedor());
		vista->mostrarTexto("Prenda cotizada: " + cotizacion->getPrenda()->toString());
		vista->mostrarTexto("Cantidad de unidades cotizadas: " + to_string(cotizacion->getCantidad()));
		vista->mostrarTexto("Precio unitario: $" + aStrDosDecimales(cotizacion->getPrenda()->getPrecioUnitario()));
		vista->mostrarTexto("Precio Final: $" + aStrDosDecimales(cotizacion->getResultado()) + "\n");
	}
}

void Presentador::getMapaPasosPrendas() {
	auto pasosPrendas = PrendaFactory::getPasosPrendaMap(vista);
	vista->setMapaPasosPrendas(pasosPrendas);
}

void Presentador::getMapaCalidades() {
	auto calidades = CalidadFactory::getCaracteristicaMap();
	vista->setMapaCalidades(calidades);
}

bool Presentador::cotizar(Prenda* prenda, int cantidad) {

	prenda->setStock(tienda->getStockDePrenda(prenda->toString()));

	return vendedor->cotizar(prenda, cantidad);
}

string Presentador::aStrDosDecimales(double n) {
	stringstream stream;
	stream << fixed << setprecision(2) << n;
	return stream.str();
}