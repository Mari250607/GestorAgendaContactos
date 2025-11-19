#pragma once
#include <string>
using namespace std;

// Clase que representa un contacto en la agenda
class Contacto
{
public:
  string nombre;
  int numero;
  string email;

  // Constructor de la clase Contacto
public:
  Contacto(string nom, int num, string mail)
      : nombre(nom), numero(num), email(mail) {}
};
