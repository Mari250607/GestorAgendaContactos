#include "HistorialOperaciones.h"
// Agrega una nueva operacion al historial
void HistorialOperaciones::agregarOperacion(const std::string &descripcion)
{
  Operacion op(descripcion);
  historial.push(op);
}

// Mostrar ultima (primera) operacion del historial
void HistorialOperaciones::mostrarHistorial()
{
  if (!historial.empty())
  {
    // Se copia la pila para no modificar el historial original
    std::stack<Operacion> copiaHistorial = historial;
    std::cout << "\nHistorial de operaciones:\n";
    // Iterar sobre la pila y mostrar cada operacion
    while (!copiaHistorial.empty())
    {
      // Obtener la operacion superior
      Operacion op = copiaHistorial.top();
      // Mostrar la descripcion de la operacion
      std::cout << "- " << op.getDescripcion() << std::endl;
      // Eliminar la operacion ya mostrada
      copiaHistorial.pop();
    }
  }
  else
  {
    std::cout << "El historial de operaciones esta vacio.\n";
  }
}
