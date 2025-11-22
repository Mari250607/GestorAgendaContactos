#include <iostream>
using namespace std;
// Incluimos vector como Array List
#include <vector>
// Importar la clase Utilidades
#include "Utilidades.h"
// Importar la clase Contacto
#include "Contacto.h"
// Importar la clase AgendaContactos
#include "AgendaContactos.h"
// Importar la clase AgendaContactosPendientes
#include "AgendaContactosPendientes.h"
// Importar la clase HistorialOperaciones
#include "HistorialOperaciones.h"
// Importar la lista enlazada
#include "ListaEnlazada.h"

// Menu de opciones de la agenda de contactos pendientes
void mostrarMenuAgendaContactosPendientes()
{
  cout << "\n\n--- Menu de Agenda de Contactos Pendientes ---\n";
  cout << "1. Transferir contactos pendientes a la agenda principal\n";
  cout << "0. Volver al menu principal\n";
  cout << "----------------------------------------------\n";
}

// Funcion gestionar agenda pendientes
void gestionarAgendaContactosPendientes(AgendaContactosPendientes &agendaPendientes, AgendaContactos &agendaPrincipal)
{
  while (true)
  {
    // Mostrar el menu de la agenda de contactos pendientes
    mostrarMenuAgendaContactosPendientes();

    // Obtener la opcion del usuario para la agenda de contactos pendientes
    int opcion = Utilidades::leerNumUserEntero("\nIngrese una opcion: ");

    // Procesar la opcion seleccionada
    switch (opcion)
    {
    case 0:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Opcion para volver al menu principal
      return;
    case 1:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Opcion para transferir contactos pendientes a la agenda principal
      {
        // Transferir los contactos pendientes a la agenda principal
        agendaPendientes.transferirContactosPendientes(agendaPrincipal);
      }
      break;
    }
  }
}

// Funcion para gestionar la eliminacion de un contacto de la lista enlazada
void gestionarEliminacionContacto(ListaEnlazada &listaContactos)
{
  // Mostrar la lista de contactos antes de eliminar
  cout << "\nLista de contactos antes de eliminar:\n";
  int numeroElementos = listaContactos.mostrarLista();

  // Validar si hay contactos para eliminar
  if (numeroElementos == 0)
  {
    cout << "\n||| No hay contactos para eliminar. |||\n";
    return;
  }

  // Leer el numero de contacto a eliminar
  int numeroContacto = Utilidades::leerNumUserEntero("\nIngrese el numero de posicion en la lista del contacto a eliminar: ");

  // Eliminar el contacto de la lista enlazada
  listaContactos.eliminarElemento(numeroContacto);

  // Mostrar la lista de contactos despues de eliminar
  cout << "\nLista de contactos despues de eliminar:\n";
  listaContactos.mostrarLista();
}

int main()
{
  // Objeto para almacenar los contactos (realizado con un ArrayList de Contactos)
  AgendaContactos agendaContactos;

  // Crear objeto de agenda de contactos pendientes
  AgendaContactosPendientes agendaPendientes;

  // Crear contactos pendientes de ejemplo
  Contacto contacto1("Juan Perez", 77778888, "juan@gmail.com");
  Contacto contacto2("Maria Gomez", 87654321, "maria@gmail.com");
  Contacto contacto3("Luis Rodriguez", 23456789, "luis@gmail.com");
  Contacto contacto4("Ana Martinez", 98765432, "ana@gmail.com");

  // Agregar contactos pendientes a la agenda de pendientes
  agendaPendientes.agregarContactoPendiente(contacto1);
  agendaPendientes.agregarContactoPendiente(contacto2);
  agendaPendientes.agregarContactoPendiente(contacto3);
  agendaPendientes.agregarContactoPendiente(contacto4);

  // Lista enlazada para gestionar contactos
  ListaEnlazada listaEnlazadaContactos;

  // Agregar algunos contactos a la lista enlazada (reutilizar los mismos que en la agenda de pendientes)
  listaEnlazadaContactos.insertarFinal(contacto1);
  listaEnlazadaContactos.insertarFinal(contacto2);
  listaEnlazadaContactos.insertarFinal(contacto3);
  listaEnlazadaContactos.insertarFinal(contacto4);

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
    cout << "\n\nOpciones disponibles en el Gestor de Agenda de Contactos:\n";
    cout << "1. Agregar contacto\n";
    cout << "2. Listar contactos\n";
    cout << "3. Buscar contacto\n";
    cout << "4. Eliminar contacto\n";
    cout << "5. Historial de operaciones\n";
    cout << "6. Contactos pendientes\n";
    cout << "0. Salir\n";

    // Obtener la opcion del usuario
    int opcion = Utilidades::leerNumUserEntero("\nIngrese una opcion: ");

    // Procesar la opcion seleccionada
    switch (opcion)
    {
    case 0:
      // Opcion para salir
      return 0;
    case 1:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Opcion para agregar contacto
      agendaContactos.agregarContacto();
      historialOperaciones.agregarOperacion("Se agrego un nuevo contacto.");
      break;
    case 2:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Opcion para listar contactos
      // agendaContactos.listarContactos();
      break;
    case 3:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Opcion para buscar contacto
      // agendaContactos.buscarContacto();
      break;
    case 4:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Opcion para eliminar contacto
      gestionarEliminacionContacto(listaEnlazadaContactos);
      break;
    case 5:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Opcion para mostrar historial de operaciones
      historialOperaciones.mostrarHistorial();
      break;
    case 6:
      // Limpiar el buffer de entrada antes de leer una cadena
      Utilidades::limpiarBufferEntrada();
      // Llamar a la funcion para gestionar la agenda de contactos pendientes
      gestionarAgendaContactosPendientes(agendaPendientes, agendaContactos);
      break;
    default:
      // Si es cualquier otra opcion, limpiar el buffer de entrada
      cin.clear();
      Utilidades::limpiarBufferEntrada();
      cout << "Opcion invalida. Por favor, seleccione una opcion valida de las mostradas.\n\n";
      break;
    }
  }

  return 0;
}
