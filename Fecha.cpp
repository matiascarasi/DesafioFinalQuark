#include "Fecha.h"

Fecha::Fecha() {
	time_t rawtime;
	tm timeinfo {};

	time(&rawtime);
	localtime_s(&timeinfo , &rawtime);

	strftime(fecha, 80, "%x %X", &timeinfo);
}