#include "PasosPantalon.h"
#include "Pantalon.h"
#include "TipoPantalonFactory.h"

void PasosPantalon::elegirTipos() {

	int opcion;
	Caracteristica* tipoPantalon{};

	system("cls");
	vista->mostrarTexto("COTIZADOR EXPTRESS - COTIZAR");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("Presione 3 para volver al menu principal");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("PASO 2.a: El pantalon a cotizar, ¿es Chupin?");
	vista->mostrarTexto("1) Si");
	vista->mostrarTexto("2) No");
	vista->mostrarTexto("----------------------------------------------");

	cin >> opcion;

	auto tipoPantalones = TipoPantalonFactory::getCaracteristicaMap();

	opcion == 1 ? tipoPantalon = tipoPantalones[(int)TipoPantalonType::CHUPIN] : tipoPantalones[(int)TipoPantalonType::COMUN];

	vista->setPrenda(new Pantalon(tipoPantalon));

}