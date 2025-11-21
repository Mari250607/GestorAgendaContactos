#pragma once
using namespace std;
#include <iostream>
#include <queue>
// Importar la clase Contacto
#include "Contacto.h"
// Importar la clase AgendaContactos
#include "AgendaContactos.h"

class AgendaContactosPendientes
{
private:
  // Cola para almacenar los contactos pendientes
  queue<Contacto> contactosPendientes;

public:
  // Agrega un contacto a la cola de pendientes
  void agregarContactoPendiente(const Contacto &contacto);

  // Transferir contactos pendientes a la agenda principal
  void transferirContactosPendientes(AgendaContactos &agenda);
};
