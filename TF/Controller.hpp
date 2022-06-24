#pragma once
#include "DataSetGenerator.hpp"
#include "Files.hpp"

class Controlador
{
public:
	Controlador(Tarjeta* oTarjeta, Efectivo* oEfectivo, Files* oFiles) 
	{
		this->oTarjeta = oTarjeta;
		this->oEfectivo = oEfectivo;
		this->oFiles = oFiles;
	}
	~Controlador() {}

	void menuPrincipal()
	{
		cout << "**************MENU**************";
		cout << "\n";
		cout << "\n											Cuenta: ";
		if (cuenta == 1)
			cout << "Efectivo";
		else if (cuenta == -1)
			cout << "Tarjeta";
		cout << "\n1)BALANCE";
		cout << "\n2)GASTOS";
		cout << "\n3)INGRESOS";
		cout << "\n4)CAMBIO DE CUENTA";
		cout << "\n5)GENERAR DATOS ALEATORIOS";
		cout << "\n6)SALIR";
		cout << "\nIngresa una opcion: ";
	}

	void procesar(int opc)
	{
		switch (opc)
		{
		case 1:
			int op;
			do
			{
				system("cls");
				cout << "---------------BALANCE--------------\n";
				cout << "\nEl balance total es : S/. " << "\n" << oFiles->getBalance(cuenta);
				cout << endl;
				cout << "\n---------------------------------------\n";
				cout << "1)Mostrar ahorros\n";
				cout << "2)Mostrar depositos\n";
				cout << "3)Mostrar salarios\n";
				cout << "4)Mostrar gastos de comida\n";
				cout << "5)Mostrar gastos de salud\n";
				cout << "6)Mostrar gastos de entretenimiento\n";
				cout << "7)Menu principal\n";
				cout << "Ingrese opcion:"; cin >> op;
				oFiles->leerIngresos(cuenta);
				oFiles->leerGastos(cuenta);
				oFiles->procesarCola(op);
				system("pause");
			} while (op != 7);		
			break;
		case 2:
			int opc;
			system("cls");
			cout << "**************MENU GASTOS***************\n";
			if (cuenta == 1) {
				for (int i = 0; i < oEfectivo->getGastos()->longitud(); i++)
				{
					cout << i + 1 << ")" << oEfectivo->getGastos()->posicion(i)->toString() << endl;
				}
			}
			else {
				for (int i = 0; i < oTarjeta->getGastos()->longitud(); i++)
				{
					cout << i + 1 << ")" << oTarjeta->getGastos()->posicion(i)->toString() << endl;
				}
			}

			cout << "\n---------------------------------------\n";
			cout << "1)NUEVO GASTO\n";
			cout << "2)SALIR\n";
			cout << "Ingrese opcion:"; cin >> opc;

			if (opc == 1)
				oFiles->archivoGasto(cuenta);
			else if (opc == 2)
			{
				cout << "REGRESANDO AL MENU PRINCIPAL :)\n";
				system("pause");
			}
			break;
		case 3:
			int opc1;
			system("cls");
			cout << "**************MENU INGRESOS**************\n";
			if (cuenta == 1) {
				for (int i = 0; i < oEfectivo->getIngresos()->longitud(); i++)
				{
					cout << i + 1 << ")" << oEfectivo->getIngresos()->posicion(i)->toString() << endl;
				}
			}
			else {
				for (int i = 0; i < oTarjeta->getIngresos()->longitud(); i++)
				{
					cout << i + 1 << ")" << oTarjeta->getIngresos()->posicion(i)->toString() << endl;
				}
			}
			cout << "\n---------------------------------------\n";
			cout << "1)NUEVO INGRESO\n";
			cout << "2)SALIR\n";
			cout << "Ingrese opcion:"; cin >> opc1;

			if (opc1 == 1)
				oFiles->archivoIngreso(cuenta);

			if (opc1 == 2)
			{
				cout << "REGRESANDO AL MENU PRINCIPAL :)\n";
				system("pause");
			}
			break;
		case 4:
			char x;
			cout << "�Esta seguro de cambiar la cuenta ";
			if (cuenta == 'E') cout << "Efectivo a Tarjeta?";
			else if (cuenta == 'T') cout << "Tarjeta a Efectivo?";
			cout << "\nSi(S) | No(N)";
			cin >> x;

			if (x == 'S' || x == 's') {
				cuenta = cuenta * -1;
				cout << "\n\nCambio realizado correctamente.";
				system("pause");
			}
			break;
		case 5:
			int xI, xG;
			cout << "Ingrese la cantidad de montos que quiere generar para los ingresos: ";
			cin >> xI;
			cout << "Ingrese la cantidad de montos que quiere generar para los gastos: ";
			cin >> xG;
			oDataGen->generarDatos(xI, xG, cuenta);
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "OPCION NO VALIDA!, POR FAVOR INGRESE UNA OPCION ENTRE 1 Y 5\n";
			system("pause");
			break;
		}
	}

private:
	DataSet* oDataGen = new DataSet();
	Tarjeta* oTarjeta;
	Efectivo* oEfectivo;
	Files* oFiles;
	float balanceI = 0.0, balanceG = 0.0;
	int cuenta = 1;
};