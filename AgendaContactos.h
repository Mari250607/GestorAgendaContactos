#pragma once
#include <vector>
#include "Contacto.h"

// Clase que representa una agenda de contactos
class AgendaContactos
{
public:
  // Agrega un nuevo contacto a la agenda
  void agregarContacto();

  // Mostrar todos los contactos en la agenda (ordenados por nombre)
  void listarContactosNombre();

  // Mostrar todos los contactos en la agenda (ordenados por numero)
  void listarContactosNumero();

private:
  // Vector para almacenar los contactos
  std::vector<Contacto> contactos;
};
