#include <iostream>
using namespace std;
// Incluimos vector como Array List
#include <vector>
// Importar la clase Contacto
#include "Contacto.h"
// Importar la clase AgendaContactos
#include "AgendaContactos.h"
// Importar la clase HistorialOperaciones
#include "HistorialOperaciones.h"

int main()
{
  // Objeto para almacenar los contactos (realizado con un ArrayList de Contactos)
  AgendaContactos agendaContactos;

  // Objeto para manejar el historial de operaciones (realizado con una pila de Operaciones)
  HistorialOperaciones historialOperaciones;

  cout << "---------------------------------------------\n\n";
  cout << "Bienvenid@ al Gestor de Agenda de Contactos!";
  cout << "\n\n---------------------------------------------";

  // Imprimir mensaje de opciones disponibles
  cout << "\n\nOpciones disponibles:\n";
  cout << "1. Agregar contacto\n";
  cout << "2. Listar contactos\n";
  cout << "3. Buscar contacto\n";
  cout << "4. Eliminar contacto\n";
  cout << "5. Historial de operaciones\n";
  cout << "0. Salir\n";

  // Llamar a la funcion para agregar un contacto
  // agendaContactos.agregarContacto();

  // Agregar operacion al historial
  historialOperaciones.agregarOperacion("Se agrego un nuevo contacto.");
  // Mostrar la ultima operacion del historial
  historialOperaciones.mostrarUltimaOperacion();

  return 0;
}
