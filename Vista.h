#pragma once
#include "IVista.h"
#include "Presentador.h"
#include <string>

using namespace std;

class Presentador;

class Vista : public IVista
{
private:
	Presentador* presentador;
	void pantallaPrincipal();
	void mostrarMenu();
	void elegirOpcion(char);
	void historialDeCotizaciones();
	void realizarCotizacion();
	void elegirPrecio();
	void elegirCantidad();
	void titulo(string);
	map<int, PasosPrenda*> mapaPasosPrendas;
	map<int, Caracteristica*> mapaCalidades;
	Prenda* prenda;
public:
	Vista();
	~Vista() override;
	void setMapaPasosPrendas(map<int, PasosPrenda*> mapaPasosPrendas) { this->mapaPasosPrendas = mapaPasosPrendas; };
	void setMapaCalidades(map<int, Caracteristica*> mapaCalidades) { this->mapaCalidades = mapaCalidades; };
	void setPrenda(Prenda* prenda) { this->prenda = prenda; };
	void opcionInvalida();
	void seleccionarCalidad();
};
