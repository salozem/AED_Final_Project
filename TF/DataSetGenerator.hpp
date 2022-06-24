#pragma once
#include <fstream>
#include "Ingreso.hpp"
#include "Gasto.hpp"
#include "Efectivo.hpp"
#include "Tarjeta.hpp"
#include <sstream>
#include <conio.h>
#include <string>
#include <ctime>

using namespace std;

class DataSet
{
public:
	DataSet() {}
	~DataSet() {}

	void generarDatos(int nIn, int nGa, int cuenta) 
	{
		Efectivo* efectivo = new Efectivo();
		Tarjeta* tarjeta = new Tarjeta();
		if (nIn > 0)
		{
			double num;
			int nTipo;
			string tipo;
			Ingreso* oIngreso;
			fstream file;
			if (cuenta == 1)
			{
				file.open("ingresoE.txt", ios::out | ios::app);
			}
			else
			{
				file.open("ingresoT.txt", ios::out | ios::app);
			}
			for (int i = 0; i < nIn; i++)
			{
				num = 10 + rand() % 100;
				nTipo = 1 + rand() % 3;
				if (nTipo == 1)
					tipo = "deposito";
				else if (nTipo == 2)
					tipo = "ahorro";
				else if (nTipo == 3)
					tipo = "salario";

				file << num << "," << tipo << endl;
				oIngreso = new Ingreso(num, tipo);
				if (cuenta == 1)
					efectivo->getIngresos()->agregar(oIngreso);
				else
					tarjeta->getIngresos()->agregar(oIngreso);
			}
			file.close();
		}
		if (nGa > 0) {
			double num;
			int nTipo;
			string tipo;
			Gasto* oGasto;

			fstream file;

			if (cuenta == 1) 
				file.open("gastoE.txt", ios::out | ios::app);
			else 
				file.open("gastoT.txt", ios::out | ios::app);
			for (int i = 0; i < nGa; i++)
			{
				num = 10 + rand() % 100;
				nTipo = 1 + rand() % 5;
				switch (nTipo)
				{
				case 1:
					tipo = "salud"; break;
				case 2:
					tipo = "comida"; break;
				case 3:
					tipo = "entretenimiento"; break;
				case 4:
					tipo = "casa"; break;
				case 5:
					tipo = "transporte"; break;
				}
				file << num << "," << tipo << endl;
				oGasto = new Gasto(num, tipo);
				if (cuenta == 1) 
					efectivo->getGastos()->agregar(oGasto);
				else
					tarjeta->getGastos()->agregar(oGasto);
			}
			file.close();
		}
	}
};