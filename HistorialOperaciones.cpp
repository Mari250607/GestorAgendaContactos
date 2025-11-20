#include "HistorialOperaciones.h"

// Agrega una nueva operacion al historial
void HistorialOperaciones::agregarOperacion(const std::string &descripcion)
{
  Operacion op(descripcion);
  historial.push(op);
}

// Mostrar ultima (primera) operacion del historial
void HistorialOperaciones::mostrarUltimaOperacion()
{
  if (!historial.empty())
  {
    // Obtener la ultima operacion del historial
    Operacion ultimaOperacion = historial.top();
    std::cout << "Ultima operacion: " << std::endl;
    // Mostrar la descripcion de la ultima operacion
    std::cout << ultimaOperacion.getDescripcion() << std::endl;
  }
  else
  {
    std::cout << "El historial de operaciones esta vacio." << std::endl;
  }
}
