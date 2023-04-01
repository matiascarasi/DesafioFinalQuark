#include "TipoMangaFactory.h"

map<int, Caracteristica*> TipoMangaFactory::getCaracteristicaMap() {
	return map<int, Caracteristica*> {
		{ (int) TipoMangaType::CORTA, new Caracteristica("Manga corta", 0.9)},
		{ (int) TipoMangaType::LARGA, new Caracteristica("Manga larga", 1) }
	};
}