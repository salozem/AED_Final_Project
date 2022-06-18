#pragma once
#include "Lista.hpp"
#include "Ingreso.hpp"
#include "Gasto.hpp"
#include <string>

class Tarjeta {
private:
	Lista<Ingreso>* ingreso;
	Lista<Gasto>* gasto;
public:
	Tarjeta() {
		ingreso = new Lista<Ingreso>;
		gasto = new Lista<Gasto>;
	}
	~Tarjeta() {}
	Lista<Ingreso>* getIngresos() {
		return ingreso;
	}
	Lista<Gasto>* getGastos() {
		return gasto;
	}
};
