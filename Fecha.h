#pragma once
#include <string>
#include <time.h>

using namespace std;

class Fecha {
	char fecha[80];
public:
	Fecha();
	string toString() { return fecha; };
};