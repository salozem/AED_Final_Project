#pragma once
#include "DataSetGenerator.hpp"	 
#include "Cola.hpp"
#include <iostream>

using namespace std;

class Files
{
private:
	Efectivo* efectivo;
	Tarjeta* tarjeta;
	Cola<double> ahorros;
	Cola<double> depositos;
	Cola<double> salarios;
	Cola<double> comidas;
	Cola<double> salud;
	Cola<double> entrenimientos;

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
	void leerIngresos(int cuenta)
	{
		int i;
		if (cuenta == 1) {
			for (i = 0; i < efectivo->getIngresos()->longitud(); i++)
			{
				if (efectivo->getIngresos()->posicion(i)->getTipo() == "ahorro")
				{
					ahorros.push(efectivo->getIngresos()->posicion(i)->getTotal());
				}
				else if (efectivo->getIngresos()->posicion(i)->getTipo() == "deposito") {
					depositos.push(efectivo->getIngresos()->posicion(i)->getTotal());
				}
				else if (efectivo->getIngresos()->posicion(i)->getTipo() == "salario") {
					salarios.push(efectivo->getIngresos()->posicion(i)->getTotal());
				}
			}
		}
		else {
			for (i = 0; i < tarjeta->getIngresos()->longitud(); i++)
			{
				if (tarjeta->getIngresos()->posicion(i)->getTipo() == "ahorro")
				{
					ahorros.push(tarjeta->getIngresos()->posicion(i)->getTotal());
				}
				else if (tarjeta->getIngresos()->posicion(i)->getTipo() == "deposito") {
					depositos.push(tarjeta->getIngresos()->posicion(i)->getTotal());
				}
				else if (tarjeta->getIngresos()->posicion(i)->getTipo() == "salario") {
					salarios.push(tarjeta->getIngresos()->posicion(i)->getTotal());
				}
			}
		}
	}
	void leerGastos(int cuenta)
	{
		int i;
		if (cuenta == 1) {
			for (i = 0; i < efectivo->getGastos()->longitud(); i++)
			{
				if (efectivo->getGastos()->posicion(i)->getTipo() == "comida")
				{
					comidas.push(efectivo->getGastos()->posicion(i)->getTotal());
				}
				else if (efectivo->getGastos()->posicion(i)->getTipo() == "salud") {
					salud.push(efectivo->getGastos()->posicion(i)->getTotal());
				}
				else if (efectivo->getGastos()->posicion(i)->getTipo() == "entretenimiento") {
					entrenimientos.push(efectivo->getGastos()->posicion(i)->getTotal());
				}
			}
		}
		else {
			for (i = 0; i < tarjeta->getGastos()->longitud(); i++)
			{
				if (tarjeta->getGastos()->posicion(i)->getTipo() == "comida")
				{
					comidas.push(tarjeta->getGastos()->posicion(i)->getTotal());
				}
				else if (tarjeta->getGastos()->posicion(i)->getTipo() == "salud") {
					salud.push(tarjeta->getGastos()->posicion(i)->getTotal());
				}
				else if (tarjeta->getGastos()->posicion(i)->getTipo() == "entretenimiento") {
					entrenimientos.push(tarjeta->getGastos()->posicion(i)->getTotal());
				}
			}
		}
	}
	double getBalance(int cuenta) {
		double bal = 0, aumento = 0.0, resta = 0.0;
		if (cuenta == 1) {
			for (int i = 0; i < efectivo->getIngresos()->longitud(); i++)
			{
				aumento = efectivo->getIngresos()->posicion(i)->getTotal();
				[&bal](int x) {return bal = bal + x; }(aumento);
			}
			for (int i = 0; i < efectivo->getGastos()->longitud(); i++)
			{
				resta = efectivo->getGastos()->posicion(i)->getTotal();
				[&bal](int x) {return bal = bal - x; }(resta);
			}
			return bal;
		}
		else {
			for (int i = 0; i < tarjeta->getIngresos()->longitud(); i++)
			{
				aumento = tarjeta->getIngresos()->posicion(i)->getTotal();
				[&bal](int x) {return bal = bal + x; }(aumento);
			}
			for (int i = 0; i < tarjeta->getGastos()->longitud(); i++)
			{
				resta = tarjeta->getGastos()->posicion(i)->getTotal();
				[&bal](int x) {return bal = bal - x; }(resta);
			}
			return bal;
		}
	}
	void procesarCola(int op) 
	{
		if (op == 1) {
			while (!ahorros.empty()) {
				cout << ahorros.front() << endl;
				ahorros.pop();
			}
			while (!depositos.empty()) depositos.pop();
			while (!salarios.empty()) salarios.pop();
			while (!comidas.empty()) comidas.pop();
			while (!salud.empty()) salud.pop();
			while (!entrenimientos.empty()) entrenimientos.pop();
		}
		else if (op == 2)
		{
			while (!depositos.empty()) {
				cout << depositos.front() << endl;
				depositos.pop();
			}
			while (!ahorros.empty()) ahorros.pop();
			while (!salarios.empty()) salarios.pop();
			while (!comidas.empty()) comidas.pop();
			while (!salud.empty()) salud.pop();
			while (!entrenimientos.empty()) entrenimientos.pop();
		}
		else if (op == 3)
		{
			while (!salarios.empty()) {
				cout << salarios.front() << endl;
				salarios.pop();
			}
			while (!ahorros.empty()) ahorros.pop();
			while (!depositos.empty()) depositos.pop();
			while (!comidas.empty()) comidas.pop();
			while (!salud.empty()) salud.pop();
			while (!entrenimientos.empty()) entrenimientos.pop();
		}
		else if (op == 4)
		{
			while (!comidas.empty()) {
				cout << comidas.front() << endl;
				comidas.pop();
			}
			while (!ahorros.empty()) ahorros.pop();
			while (!depositos.empty()) depositos.pop();
			while (!salarios.empty()) salarios.pop();
			while (!salud.empty()) salud.pop();
			while (!entrenimientos.empty()) entrenimientos.pop();
		}
		else if (op == 5)
		{
			while (!salud.empty()) {
				cout << salud.front() << endl;
				salud.pop();
			}
			while (!ahorros.empty()) ahorros.pop();
			while (!depositos.empty()) depositos.pop();
			while (!salarios.empty()) salarios.pop();
			while (!comidas.empty()) comidas.pop();
			while (!entrenimientos.empty()) entrenimientos.pop();
		}
		else if (op == 6)
		{
			while (!entrenimientos.empty()) {
				cout << entrenimientos.front() << endl;
				entrenimientos.pop();
			}
			while (!ahorros.empty()) ahorros.pop();
			while (!depositos.empty()) depositos.pop();
			while (!salarios.empty()) salarios.pop();
			while (!comidas.empty()) comidas.pop();
			while (!entrenimientos.empty()) salud.pop();
		}
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