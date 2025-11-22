#pragma once
#include <vector>
#include "Contacto.h"

// Clase que representa una agenda de contactos
class AgendaContactos
{
public:
  // Agrega un nuevo contacto a la agenda
  void agregarContacto();

  // Agrega contacto con datos especificos (usado para transferir desde pendientes)
  void agregarContacto(const Contacto &contacto);

  // Void ordenar contactos por nombre
  void ordenarContactosPorNombre();

  // Mostrar todos los contactos en la agenda (ordenados por nombre)
  void listarContactos();

private:
  // Vector para almacenar los contactos
  std::vector<Contacto> contactos;
};
