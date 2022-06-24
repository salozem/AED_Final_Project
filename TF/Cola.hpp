#pragma once
#include <iostream>
#include <cstdlib>
#include <functional>
#define NULO 0
using namespace std;
template <typename Tipo>
struct Nod {
	Tipo ele;
	Nod<Tipo>* sig;
	Nod<Tipo>* ant;
	Nod(Tipo e) {
		ele = e;
		sig = ant = nullptr;
	}
};
template <typename Tipo>
class Cola {
	Nod<Tipo>* inicial;
	Nod<Tipo>* final;
	long cantidad;
public:
	Cola() {
		final = inicial = nullptr;
		cantidad = 0;
	}
	void push(Tipo e) {    //O(1)    
		Nod<Tipo>* n = new Nod<Tipo>(e);
		if (inicial == nullptr)
			inicial = final = n;
		else {
			final->sig = n;
			n->ant = final;
			final = n;
		}
		++cantidad;
	}
	void pop() {
		if (inicial == nullptr) return;
		Nod<Tipo>* aux = inicial;
		if (cantidad == 1)
			inicial = final = nullptr;
		else {
			inicial = inicial->sig;
			inicial->ant = nullptr;
		}
		delete aux;
		--cantidad;
	}
	Tipo front() {
		if (cantidad > 0) return inicial->ele;
		else return NULO;
	}
	void front(function<void(Tipo)> fFront) {
		if (cantidad > 0)
			fFront(inicial->ele);
	}
	bool empty() {
		return cantidad == 0;
	}
	int size() { return cantidad; }
};