#include "AgendaContactosPendientes.h"
using namespace std;

// Agrega un contacto a la cola de pendientes con datos especificos
void AgendaContactosPendientes::agregarContactoPendiente(const Contacto &contacto)
{
  contactosPendientes.push(contacto);
}

// Transferir contactos pendientes a la agenda principal
void AgendaContactosPendientes::transferirContactosPendientes(AgendaContactos &agenda, HistorialOperaciones &historialOperaciones)
{
  // Validar si hay contactos pendientes
  if (contactosPendientes.empty())
  {
    cout << "\n\nNo hay contactos pendientes para transferir.\n";
    return;
  }

  while (!contactosPendientes.empty())
  {
    // Obtener el contacto en la parte frontal de la cola
    Contacto contacto = contactosPendientes.front();
    // Agregar el contacto a la agenda principal
    agenda.agregarContacto(contacto);
    // Eliminar el contacto ya transferido de la cola
    contactosPendientes.pop();
    // Agregar operacion al historial
    string descripcionOperacion = "Se agrego un nuevo contacto a la agenda de contactos (desde pendientes).";
    historialOperaciones.agregarOperacion(descripcionOperacion);
  }

  cout << "\n\nTodos los contactos pendientes han sido transferidos a la agenda principal.\n";
}
