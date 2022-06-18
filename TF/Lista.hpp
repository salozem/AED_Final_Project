#pragma once
#include <functional>

using namespace std;

//Clase lista
template <typename T>
class Lista
{
	class Nodo;
	typedef function<int(T, T)> Compare;

	Nodo* inicial;
	int size = 0;

	//Compare comparar; //lambda para comparar

public:
	Lista() 
	{
		inicial = nullptr;
	}
	~Lista() {}

	int longitud();

	T* posicion(int pos);

	//M�todos para agregar elementos a la lista
	void agregar(T* elem);
};

//Nodo
template<typename T>
class Lista<T>::Nodo {
public:
	T* elem;
	Nodo* siguiente; // puntero apunta al siguiente nodo

	Nodo() {}
	Nodo(T* elem, Nodo* siguiente = nullptr) : elem(elem), siguiente(siguiente) {}
};

//IMPLEMENTACI�N DE LOS M�TODOS
template <typename T>
int Lista<T>::longitud()
{
	return size;
}

template <typename T>
T* Lista<T>::posicion(int pos)
{
	if (pos >= 0 && pos < size) {
		Nodo* aux = inicial;
		for (int i = 0; i < pos; i++) {
			aux = aux->siguiente;
		}
		return aux->elem;
	}
	else {
		return nullptr;
	}
}

template <typename T>
void Lista<T>::agregar(T* elem)
{
	Nodo* nuevo = new Nodo(elem, inicial);
	if (nuevo != nullptr)
	{
		inicial = nuevo;
		size++;
	}
}