#pragma once
#include "Contacto.h"

class Nodo
{
public:
  Contacto dato;
  Nodo *siguiente;

  // Constructor por defecto
  Nodo() : siguiente(nullptr) {}
};
