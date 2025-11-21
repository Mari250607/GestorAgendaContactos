#include "Utilidades.h"

// Leer un numero entero ingresado por el usuario con un mensaje personalizado
int Utilidades::leerNumUserEntero(const std::string &mensaje)
{
  int numero;
  while (true)
  {
    std::cout << mensaje;
    if (std::cin >> numero)
    {
      // Entrada valida, salir del bucle
      break;
    }
    else
    {
      std::cout << "\n *** Valor invalido.*** Debe ser un numero entero.\n\n";
      // Limpiar el error de la entrada
      std::cin.clear();
      // Ignorar el resto de la linea
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return numero;
}

// Limpiar el buffer de entrada
void Utilidades::limpiarBufferEntrada()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}