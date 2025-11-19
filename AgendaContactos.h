#pragma once
#include <vector>
#include "Contacto.h"

// Clase que representa una agenda de contactos
class AgendaContactos
{
public:
  // Agrega un nuevo contacto a la agenda
  void agregarContacto();

private:
  // Vector para almacenar los contactos
  std::vector<Contacto> contactos;
};
