#include "Utilidades.h"
using namespace std;

// Leer un numero entero ingresado por el usuario con un mensaje personalizado
int Utilidades::leerNumUserEntero(const string &mensaje)
{
  int numero;
  while (true)
  {
    cout << mensaje;
    if (cin >> numero)
    {
      // Entrada valida, salir del bucle
      break;
    }
    else
    {
      cout << "\n *** Valor invalido.*** Debe ser un numero entero.\n\n";
      // Limpiar el error de la entrada
      cin.clear();
      // Ignorar el resto de la linea
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
  return numero;
}

// Limpiar el buffer de entrada
void Utilidades::limpiarBufferEntrada()
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}