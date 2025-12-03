#pragma once
#include <iostream>
using namespace std;

class Operacion
{
private:
  string descripcion;

public:
  Operacion(const string &desc) : descripcion(desc) {}
  string getDescripcion();
};
