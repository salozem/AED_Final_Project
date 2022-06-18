#pragma once
#include <string>
#include "Lista.hpp"
#include "Ingreso.hpp"
#include "Gasto.hpp"

class Efectivo {
private:
	Lista<Ingreso>* ingreso;
	Lista<Gasto>* gasto;
public:
	Efectivo() 
	{
		ingreso = new Lista<Ingreso>;
		gasto = new Lista<Gasto>;
	}
	~Efectivo() {}
	Lista<Ingreso>* getIngresos() {
		return ingreso;
	}
	Lista<Gasto>* getGastos() {
		return gasto;
	}
};