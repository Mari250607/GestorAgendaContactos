#pragma once
// Incluye la definición de la clase Operacion
#include "Operacion.h"
// Incluye la definición de stack (para el historial de operaciones en una pila)
#include <stack>

class HistorialOperaciones
{
public:
  // Agrega una nueva operacion al historial
  void agregarOperacion(const std::string &descripcion);
  // Mostrar ultima (primera) operacion del historial
  void mostrarHistorial();

private:
  // Pila para almacenar las operaciones realizadas
  std::stack<Operacion> historial;
};
