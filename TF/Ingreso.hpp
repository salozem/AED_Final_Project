#pragma once
#include <string>

using namespace std;

class Ingreso
{
	double total = 0.0;
	string tipo;
public:
	Ingreso(double total, string tip) :total(total), tipo(tip) {}
	~Ingreso() {};

	void setTotal(double T) { total = T; }
	double getTotal() { return total; }
	void setTipo(string tip) { tipo = tip; }
	string getTipo() { return tipo; }
	string toString()
	{
		return "Monto: " + to_string(total) + "\t Tipo: " + tipo;
	}
};