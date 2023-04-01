#include "PasosPantalon.h"
#include "Pantalon.h"
#include "TipoPantalonFactory.h"

Caracteristica* PasosPantalon::elegirTipoPantalon() {
	string strOpcion;
	system("cls");
	vista->mostrarTexto("COTIZADOR EXPTRESS - COTIZAR");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("Presione 3 para volver al menu principal");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("PASO 2: El pantalon a cotizar, ¿es Chupin?");
	vista->mostrarTexto("1) Si");
	vista->mostrarTexto("2) No");
	vista->mostrarTexto("----------------------------------------------");

	cin >> strOpcion;

	try {
		int opcion = stoi(strOpcion);

		if (opcion == 3) {
			return NULL;
		}

		auto tipoPantalones = TipoPantalonFactory::getCaracteristicaMap();
		return opcion == 1 ? tipoPantalones[(int)TipoPantalonType::CHUPIN] : tipoPantalones[(int)TipoPantalonType::COMUN];
	}
	catch (invalid_argument)
	{
		return NULL;
	}

}

void PasosPantalon::elegirTipos() {

	Caracteristica* tipoPantalon = elegirTipoPantalon();
	
	if (tipoPantalon == NULL) {
		vista->opcionInvalida();
		return;
	}


	vista->setPrenda(new Pantalon(tipoPantalon));

}