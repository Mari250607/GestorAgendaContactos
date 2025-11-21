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

  // Agregar operacion al historial
  historialOperaciones.agregarOperacion("Se agrego un nuevo contacto.");
  historialOperaciones.agregarOperacion("Se elimino un contacto.");
  historialOperaciones.agregarOperacion("Se agrego un contacto.");

  // Saludo del sistema
  cout << "---------------------------------------------\n\n";
  cout << "Bienvenid@ al Gestor de Agenda de Contactos!";
  cout << "\n\n---------------------------------------------";

  // Bucle principal del programa
  while (true)
  {
    // Imprimir mensaje de opciones disponibles
    cout << "\n\nOpciones disponibles:\n";
    cout << "1. Agregar contacto\n";
    cout << "2. Listar contactos\n";
    cout << "3. Buscar contacto\n";
    cout << "4. Eliminar contacto\n";
    cout << "5. Historial de operaciones\n";
    cout << "0. Salir\n";

    cout << "\nIngrese una opcion: ";
    int opcion;
    cin >> opcion;

    // Si la lectura falla
    if (cin.fail())
    {
      // limpiar el error de cin
      cin.clear();
      // limpiar buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "*** Entrada invalida. *** Por favor ingrese un numero de las opciones disponibles.\n";
      // volver al inicio del while
      continue;
    }

    switch (opcion)
    {
    case 0:
      // Opcion para salir
      return 0;
    case 1:
      // Limpiar el buffer de entrada antes de leer una cadena
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Opcion para agregar contacto
      agendaContactos.agregarContacto();
      historialOperaciones.agregarOperacion("Se agrego un nuevo contacto.");
      break;
    case 2:
      // Limpiar el buffer de entrada antes de leer una cadena
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Opcion para listar contactos
      // agendaContactos.listarContactos();
      break;
    case 3:
      // Limpiar el buffer de entrada antes de leer una cadena
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Opcion para buscar contacto
      // agendaContactos.buscarContacto();
      break;
    case 4:
      // Limpiar el buffer de entrada antes de leer una cadena
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Opcion para eliminar contacto
      // agendaContactos.eliminarContacto();
      break;
    case 5:
      // Limpiar el buffer de entrada antes de leer una cadena
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Opcion para mostrar historial de operaciones
      historialOperaciones.mostrarHistorial();
      break;
    default:
      // Si es cualquier otra opcion, limpiar el buffer de entrada
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opcion invalida. Por favor, seleccione una opcion valida de las mostradas.\n\n";
      break;
    }
  }

  return 0;
}
