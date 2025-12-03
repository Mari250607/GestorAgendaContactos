#pragma once
#include <vector>
#include "Contacto.h"
using namespace std;

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

  // Buscar contacto por numero (lineal)
  void buscarContacto(int numero);

  // Buscar contacto por nombre (binaria)
  void buscarContacto(string nombre);

  // Validar si la agenda esta vacia
  bool isVacia();

private:
  // Vector para almacenar los contactos
  vector<Contacto> contactos;
};
