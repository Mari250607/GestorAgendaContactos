#include <iostream>
using namespace std;

// Incluimos vector como Array List
#include <vector>

// Importar la clase Contacto
#include "Contacto.h"

// Importar la clase AgendaContactos
#include "AgendaContactos.h"

int main()
{
  // Vector para almacenar los contactos
  AgendaContactos agendaContactos;

  cout << "---------------------------------------------\n\n";
  cout << "Bienvenid@ al Gestor de Agenda de Contactos!";
  cout << "\n\n---------------------------------------------";

  // Imprimir mensaje de opciones disponibles
  cout << "\n\nOpciones disponibles:\n";
  cout << "1. Agregar contacto\n";

  // Llamar a la funcion para agregar un contacto
  agendaContactos.agregarContacto();
  return 0;
}
