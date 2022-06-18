#pragma once
#include <string>

using namespace std;

class Gasto
{
	double total = 0.0;
	string tipo; //casa, comida, entretenimiento, transporte, salud
public:
	Gasto(double total = 0, string tipo = " ") :total(total), tipo(tipo) {}
	~Gasto() {}

	void setTotal(double x) { total = x; }
	double getTotal() { return total; }
	void setTipo(string x) { tipo = x; }
	string getTipo() { return tipo; }

	string toString()
	{
		return "Monto: " + to_string(total) + "\t Tipo: " + tipo;
	}
};