#pragma once
#include <iostream>
using namespace std;

class Utilidades
{

public:
  // Leer un numero entero ingresado por el usuario con un mensaje personalizado
  static int leerNumUserEntero(const string &mensaje);

  // Limpiar el buffer de entrada
  static void limpiarBufferEntrada();
};
