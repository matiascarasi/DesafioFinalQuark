#include "PasosCamisa.h"
#include "TipoCuelloFactory.h"
#include "TipoMangaFactory.h"
#include "Camisa.h"

Caracteristica* PasosCamisa::elegirTipoManga() {
	string strOpcion;
	system("cls");
	vista->mostrarTexto("COTIZADOR EXPTRESS - COTIZAR");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("Presione 3 para volver al menu principal");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("PASO 2.a: La camisa a cotizar, ¿es manga corta?");
	vista->mostrarTexto("1) Si");
	vista->mostrarTexto("2) No");
	vista->mostrarTexto("----------------------------------------------");

	cin >> strOpcion;

	try {
		int opcion = stoi(strOpcion);

		if (opcion == 3) {
			return NULL;
		}

		auto tipoMangas = TipoMangaFactory::getCaracteristicaMap();
		return opcion == 1 ? tipoMangas[(int)TipoMangaType::CORTA] : tipoMangas[(int)TipoMangaType::LARGA];
	} 
	catch (invalid_argument)
	{
		return NULL;
	}

}

Caracteristica* PasosCamisa::elegirTipoCuello() {
	string strOpcion;
	system("cls");
	vista->mostrarTexto("COTIZADOR EXPTRESS - COTIZAR");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("Presione 3 para volver al menu principal");
	vista->mostrarTexto("----------------------------------------------");
	vista->mostrarTexto("PASO 2.b: La camisa a cotizar, ¿es cuello Mao?");
	vista->mostrarTexto("1) Si");
	vista->mostrarTexto("2) No");
	vista->mostrarTexto("----------------------------------------------");

	cin >> strOpcion;

	try {
		int opcion = stoi(strOpcion);

		if (opcion==3) {
			return NULL;
		}

		auto tipoCuellos = TipoCuelloFactory::getCaracteristicaMap();
		return opcion == 1 ? tipoCuellos[(int)TipoCuelloType::MAO] : tipoCuellos[(int)TipoCuelloType::COMUN];
	}
	catch (invalid_argument)
	{
		return NULL;
	}

}

void PasosCamisa::elegirTipos() {

	Caracteristica* tipoManga = elegirTipoManga();

	if (tipoManga == NULL) {
		vista->opcionInvalida();
		return;
	}

	Caracteristica* tipoCuello = elegirTipoCuello();

	if (tipoCuello == NULL) {
		vista->opcionInvalida();
		return;
	}

	vista->setPrenda(new Camisa(tipoManga, tipoCuello));

}