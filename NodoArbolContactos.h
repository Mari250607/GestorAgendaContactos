#pragma once
#include "Contacto.h"

class NodoArbolContactos
{
public:
  Contacto contacto;
  NodoArbolContactos *izquierdo;
  NodoArbolContactos *derecho;

public:
  // Constructor de la clase NodoArbolContactos
  NodoArbolContactos(Contacto c)
      : contacto(c), izquierdo(nullptr), derecho(nullptr) {}
};
