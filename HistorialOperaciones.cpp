#include "HistorialOperaciones.h"
using namespace std;

// Agrega una nueva operacion al historial
void HistorialOperaciones::agregarOperacion(const string &descripcion)
{
  Operacion op(descripcion);
  historial.push(op);
}

// Mostrar historial de operaciones (en LIFO)
void HistorialOperaciones::mostrarHistorial()
{
  if (!historial.empty())
  {
    // Se copia la pila para no modificar el historial original
    stack<Operacion> copiaHistorial = historial;
    cout << "\nHistorial de operaciones:\n";
    // Iterar sobre la pila y mostrar cada operacion
    while (!copiaHistorial.empty())
    {
      // Obtener la operacion superior
      Operacion op = copiaHistorial.top();
      // Mostrar la descripcion de la operacion
      cout << "- " << op.getDescripcion() << endl;
      // Eliminar la operacion ya mostrada
      copiaHistorial.pop();
    }
  }
  else
  {
    cout << "El historial de operaciones esta vacio.\n";
  }
}
