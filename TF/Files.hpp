#pragma once
#include "DataSetGenerator.hpp"
#include <iostream>

using namespace std;

class Files
{
private:
	Efectivo* efectivo;
	Tarjeta* tarjeta;

public:
	Files (Tarjeta* tarjeta, Efectivo* efectivo) 
	{
		this->tarjeta = tarjeta;
		this->efectivo = efectivo;
	}
	~Files() {}

	void archivoIngreso(int cuenta) 
	{
		double total;
		string tipo;
		Ingreso* oIngreso;
		fstream file;

		if (cuenta == 1) {
			file.open("ingresoE.txt", ios::out | ios::app);
		}
		else {
			file.open("ingresoT.txt", ios::out | ios::app);
		}
		cout << "Ingrese un monto: "; cin >> total;
		cout << "Ingrese tipo de ingreso: "; cin >> tipo;
		file << total << "," << tipo << endl;
		oIngreso = new Ingreso(total, tipo);
		if (cuenta == 1) {
			efectivo->getIngresos()->agregar(oIngreso);
		}
		else {
			tarjeta->getIngresos()->agregar(oIngreso);
		}
		file.close();
	}

	void archivoGasto(int cuenta)
	{
		double total;
		string tipo;
		Gasto* oGasto;

		fstream file;

		if (cuenta == 1) {
			file.open("gastoE.txt", ios::out | ios::app);
		}
		else {
			file.open("gastoT.txt", ios::out | ios::app);
		}
		cout << "Ingrese un monto: "; cin >> total;
		cout << "Ingrese tipo de gasto: "; cin >> tipo;
		file << total << "," << tipo << endl;
		oGasto = new Gasto(total, tipo);
		if (cuenta == 1) {
			efectivo->getGastos()->agregar(oGasto);
		}
		else {
			tarjeta->getGastos()->agregar(oGasto);
		}
		file.close();
	}
	float leerIngresos(int cuenta, float balance)
	{
		int i, pos;
		double bal = 0.0, aumento = 0.0;
		Ingreso* aux;
		if (cuenta == 1) {
			for (i = 0; i < efectivo->getIngresos()->longitud(); i++)
			{
				pos = i;
				aux = new Ingreso(efectivo->getIngresos()->posicion(i)->getTotal(), efectivo->getIngresos()->posicion(i)->getTipo());

				while ((pos > 0) && (efectivo->getIngresos()->posicion(i)->getTotal() > aux->getTotal()))
				{
					efectivo->getIngresos()->posicion(pos)->setTotal(efectivo->getIngresos()->posicion(pos - 1)->getTotal());
					efectivo->getIngresos()->posicion(pos)->setTipo(efectivo->getIngresos()->posicion(pos - 1)->getTipo());
					pos--;
				}
				efectivo->getIngresos()->posicion(pos)->setTotal(aux->getTotal());
				efectivo->getIngresos()->posicion(pos)->setTipo(aux->getTipo());
			}

			for (i = 0; i < efectivo->getIngresos()->longitud(); i++)
			{
				aumento = efectivo->getIngresos()->posicion(i)->getTotal();
				//cout << i << ")" << efectivo->getIngresos()->posicion(i)->getTipo() << " - S/." << aumento << endl;
				[&bal](int x) {return bal = bal + x; }(aumento);
			}
		}
		else {
			for (i = 0; i < tarjeta->getIngresos()->longitud(); i++)
			{
				pos = i;
				aux = new Ingreso(tarjeta->getIngresos()->posicion(i)->getTotal(), tarjeta->getIngresos()->posicion(i)->getTipo());

				while ((pos > 0) && (tarjeta->getIngresos()->posicion(i)->getTotal() > aux->getTotal()))
				{
					tarjeta->getIngresos()->posicion(pos)->setTotal(tarjeta->getIngresos()->posicion(pos - 1)->getTotal());
					tarjeta->getIngresos()->posicion(pos)->setTipo(tarjeta->getIngresos()->posicion(pos - 1)->getTipo());
					pos--;
				}
				tarjeta->getIngresos()->posicion(pos)->setTotal(aux->getTotal());
				tarjeta->getIngresos()->posicion(pos)->setTipo(aux->getTipo());
			}

			for (i = 0; i < tarjeta->getIngresos()->longitud(); i++)
			{
				aumento = tarjeta->getIngresos()->posicion(i)->getTotal();
				//cout << i << ")" << tarjeta->getIngresos()->posicion(i)->getTipo() << " - S/." << aumento << endl;
				[&bal](int x) {return bal = bal + x; }(aumento);
			}
		}
		return balance = balance + bal;
	}
	float leerGastos(int cuenta, float balance)
	{
		int i, pos;
		double bal = 0.0, resta = 0.0;
		Gasto* aux;
		if (cuenta == 1) {
			for (i = 0; i < efectivo->getGastos()->longitud(); i++)
			{
				pos = i;
				aux = new Gasto(efectivo->getGastos()->posicion(i)->getTotal(), efectivo->getGastos()->posicion(i)->getTipo());

				while ((pos > 0) && (efectivo->getGastos()->posicion(i)->getTotal() > aux->getTotal()))
				{
					efectivo->getGastos()->posicion(pos)->setTotal(efectivo->getGastos()->posicion(pos - 1)->getTotal());
					efectivo->getGastos()->posicion(pos)->setTipo(efectivo->getGastos()->posicion(pos - 1)->getTipo());
					pos--;
				}
				efectivo->getGastos()->posicion(pos)->setTotal(aux->getTotal());
				efectivo->getGastos()->posicion(pos)->setTipo(aux->getTipo());
			}

			for (i = 0; i < efectivo->getGastos()->longitud(); i++)
			{
				resta = efectivo->getGastos()->posicion(i)->getTotal();
				//cout << i << ")" << efectivo->getGastos()->posicion(i)->getTipo() << " - S/." << resta << endl;
				[&bal](int x) {return bal = bal + x; }(resta);
			}
		}
		else {
			for (i = 0; i < tarjeta->getGastos()->longitud(); i++)
			{
				pos = i;
				aux = new Gasto(tarjeta->getGastos()->posicion(i)->getTotal(), tarjeta->getGastos()->posicion(i)->getTipo());

				while ((pos > 0) && (tarjeta->getGastos()->posicion(i)->getTotal() > aux->getTotal()))
				{
					tarjeta->getGastos()->posicion(pos)->setTotal(tarjeta->getGastos()->posicion(pos - 1)->getTotal());
					tarjeta->getGastos()->posicion(pos)->setTipo(tarjeta->getGastos()->posicion(pos - 1)->getTipo());
					pos--;
				}
				tarjeta->getGastos()->posicion(pos)->setTotal(aux->getTotal());
				tarjeta->getGastos()->posicion(pos)->setTipo(aux->getTipo());
			}

			for (i = 0; i < tarjeta->getGastos()->longitud(); i++)
			{
				resta = tarjeta->getGastos()->posicion(i)->getTotal();
				//cout << i << ")" << tarjeta->getGastos()->posicion(i)->getTipo() << " - S/." << resta << endl;
				[&bal](int x) {return bal = bal + x; }(resta);
			}
		}
		return balance = balance - bal;
	}
	void cargarIngresos()
	{
		string cadenaI, cadena2, ingUno, ingDos;
		double totalT = 0.0,totalE= 0.0;
		ifstream arch1("ingresoE.txt");
		while (getline(arch1, cadenaI)) {
			stringstream archMemoria1(cadenaI);
			getline(archMemoria1, ingUno, ',');
			getline(archMemoria1, ingDos, ',');
			totalE = stod(ingUno);
			efectivo->getIngresos()->agregar(new Ingreso(totalE, ingDos));
		}
		arch1.close();

		ingUno = "";
		ingDos = "";
		ifstream arch2("ingresoT.txt");
		while (getline(arch2, cadena2)) {
			stringstream archMemoria2(cadena2);
			getline(archMemoria2, ingUno, ',');
			getline(archMemoria2, ingDos, ',');
			totalT = stod(ingUno);
			tarjeta->getIngresos()->agregar(new Ingreso(totalT, ingDos));
		}
		arch2.close();
	}
	void cargarGastos()
	{
		string cadena1, cadena2, gasUno, gasDos;
		double total = 0.0;
		ifstream arch1("gastoE.txt");
		while (getline(arch1, cadena1)) {
			stringstream archMemoria1(cadena1);
			getline(archMemoria1, gasUno, ',');
			getline(archMemoria1, gasDos, ',');
			total = stod(gasUno);
			efectivo->getGastos()->agregar(new Gasto(total, gasDos));
		}
		arch1.close();

		gasUno = "";
		gasDos = "";
		total = 0.0;
		ifstream arch2("gastoT.txt");
		while (getline(arch2, cadena2)) {
			stringstream archMemoria2(cadena2);
			getline(archMemoria2, gasUno, ',');
			getline(archMemoria2, gasDos, ',');
			total = stod(gasUno);
			tarjeta->getGastos()->agregar(new Gasto(total, gasDos));
		}
		arch2.close();
	}
};