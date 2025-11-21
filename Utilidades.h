#pragma once
#include <iostream>

class Utilidades
{

public:
  // Leer un numero entero ingresado por el usuario con un mensaje personalizado
  static int leerNumUserEntero(const std::string &mensaje);

  // Limpiar el buffer de entrada
  static void limpiarBufferEntrada();
};
