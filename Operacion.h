#pragma once
#include <iostream>
using namespace std;

class Operacion
{
private:
  std::string descripcion;

public:
  Operacion(const std::string &desc) : descripcion(desc) {}
  std::string getDescripcion();
};
