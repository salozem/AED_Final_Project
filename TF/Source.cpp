#include "Controller.hpp"

int main() 
{
	Tarjeta* oTarjeta = new Tarjeta();
	Efectivo* oEfectivo = new Efectivo();
	Files* oFiles = new Files(oTarjeta,oEfectivo);
	oFiles->cargarGastos();
	oFiles->cargarIngresos();
	Controlador* oControlador = new Controlador(oTarjeta, oEfectivo, oFiles);
	int opc;
	system("CLS");
	srand(time(NULL));
	do
	{
		system("CLS");
		oControlador->menuPrincipal();
		std::cin >> opc;
		oControlador->procesar(opc);

	} while (opc != 6);
	return 0;
}