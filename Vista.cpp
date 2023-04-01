#include "Vista.h"

const string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.\n";
const string INVALID_OPTION_MESSAGE = "La opcion ingresada es invalida, por favor reintente.\n";

Vista::Vista() {
	this->presentador = new Presentador(this);
	pantallaPrincipal();
}

Vista::~Vista(){
	delete presentador;
}

void Vista::pantallaPrincipal() {

	system("cls");
	mostrarTexto("COTIZADOR EXPTRESS - MENU PRINCIPAL");
	mostrarTexto("----------------------------------------------");
	presentador->mostrarTienda();
	mostrarTexto("----------------------------------------------");
	presentador->mostrarVendedor();
	mostrarTexto("----------------------------------------------\n");

	mostrarMenu();
}

void Vista::mostrarMenu() {
	
	char opcion;

	mostrarTexto("SELECCIONAR UNA OPCION DEL MENU\n");
	mostrarTexto("1) Historial de Cotizaciones");
	mostrarTexto("2) Realizar Cotizacion");
	mostrarTexto("3) Salir");

	cin >> opcion;

	elegirOpcion(opcion);

}

void Vista::elegirOpcion(char opcion) {

	switch (opcion) {
	case '1':
		historialDeCotizaciones();
		break;
	case '2':
		realizarCotizacion();
	case '3':
		exit(EXIT_SUCCESS);
	default:
		opcionInvalida();
		break;
	}
}

void Vista::opcionInvalida() {
	string sig;
	system("cls");
	mostrarTexto(INVALID_OPTION_MESSAGE);
	mostrarTexto(ANY_KEY_MESSAGE);
	cin >> sig;
	pantallaPrincipal();
}

void Vista::historialDeCotizaciones() {
	string opcion;
	titulo("HISTORIAL DE COTIZACIONES");
	presentador->mostrarHistorialDeCotizaciones();
	cin >> opcion;

	pantallaPrincipal();

}

void Vista::realizarCotizacion() {
	string strOpcion;
	bool opcionValida = false;
	presentador->getMapaPasosPrendas();
	titulo("COTIZAR");
	for (auto prendaPair : mapaPasosPrendas) {
		mostrarTexto(to_string(prendaPair.first) + ") " + prendaPair.second->getNombre());
	}
	mostrarTexto("----------------------------------------------");

	cin >> strOpcion;

	try {
		int opcion = stoi(strOpcion);

		for (auto prendaPair : mapaPasosPrendas) {
			if (opcion == 3) {
				pantallaPrincipal();
				return;
			}
			else if (prendaPair.first == opcion) {
				opcionValida = true;
				mapaPasosPrendas[opcion]->elegirTipos();
				seleccionarCalidad();
				break;
			}
		}

		if (!opcionValida) {
			opcionInvalida();
			return;
		}
	}
	catch (invalid_argument)
	{
		opcionInvalida();
		return;
	}

}

void Vista::seleccionarCalidad() {
	string strOpcion;
	bool opcionValida = false;
	presentador->getMapaCalidades();
	titulo("COTIZAR");
	mostrarTexto("PASO 3: Seleccione la calidad de la prenda");
	for (auto calidadPair : mapaCalidades) {
		mostrarTexto(to_string(calidadPair.first) + ") " + calidadPair.second->getNombre());
	}
	mostrarTexto("----------------------------------------------");

	cin >> strOpcion;

	try {
		int opcion = stoi(strOpcion);

		for (auto calidadPair : mapaCalidades) {
			if (opcion == 3) {
				pantallaPrincipal();
				return;
			}
			else if (calidadPair.first == opcion) {
				opcionValida = true;
				prenda->setCalidad(mapaCalidades[opcion]);
				elegirPrecio();
				break;
			}
		}

		if (!opcionValida) {
			opcionInvalida();
			return;
		}
	}
	catch (invalid_argument)
	{
		opcionInvalida();
		return;
	}

};

void Vista::elegirPrecio() {
	string strPrecioUnitario;
	titulo("COTIZAR");
	mostrarTexto("PASO 4: Ingrese el precio unitario de la prenda a cotizar");
	cin >> strPrecioUnitario;
	mostrarTexto("----------------------------------------------");

	try {
		double precioUnitario = stod(strPrecioUnitario);
		prenda->setPrecioUnitario(precioUnitario);
		elegirCantidad();
	}
	catch (invalid_argument)
	{
		opcionInvalida();
		return;
	}


}

void Vista::elegirCantidad() {
	string strCantidad;
	titulo("COTIZAR");
	mostrarTexto("PASO 5: Ingrese la cantidad de unidades a cotizar");
	cin >> strCantidad;
	mostrarTexto("----------------------------------------------");

	try {

		int cantidad = stoi(strCantidad);

		if (presentador->cotizar(prenda, cantidad)) {
			mostrarTexto("Se realizo la cotizacion correctamente");
		}
		else {
			mostrarTexto("No se pudo cotizar el producto");
		}
		mostrarTexto(ANY_KEY_MESSAGE);
		cin >> strCantidad;
		pantallaPrincipal();
	}
	catch (invalid_argument)
	{
		opcionInvalida();
		return;
	}

}


void Vista::titulo(string titulo) {
	system("cls");
	mostrarTexto("COTIZADOR EXPTRESS - " + titulo);
	mostrarTexto("----------------------------------------------");
	mostrarTexto("Presione 3 para volver al menu principal");
	mostrarTexto("----------------------------------------------");
}