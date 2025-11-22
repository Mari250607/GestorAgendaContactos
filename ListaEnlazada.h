#pragma once
#include "Nodo.h"

class ListaEnlazada
{
private:
  Nodo *cabeza;

  // Constructor por defecto
public:
  ListaEnlazada() : cabeza(nullptr) {}

public:
  void insertarFinal(Contacto &c);
  int mostrarLista();
  void eliminarElemento(int numeroPosicion);
};
