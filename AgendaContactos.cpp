#include "AgendaContactos.h"
#include <iostream>

void AgendaContactos::agregarContacto()
{
  // Solicitar datos del contacto al usuario
  string nombre;
  int numero;
  string email;

  cout << "\n\nIngrese el nombre del contacto: ";
  // Hasta que el nombre no sea valido (no nulo), seguir pidiendo
  while (true)
  {
    // Se toma toda la linea para permitir nombres con espacios
    if (!std::getline(std::cin, nombre))
    {
      // Limpiar el error de la entrada
      std::cin.clear();
      // Reintentar leer el nombre
      continue;
    }

    // Validar que el nombre no este vacio
    if (!nombre.empty())
    {
      break; // Nombre valido, salir del bucle
    }
    else
    {
      std::cout << "\n *** Valor invalido.*** El nombre no puede estar vacio.\n";
      cout << "\n Ingrese nuevamente el nombre del contacto: ";
    }
  }

  cout << "\n\nIngrese el numero del contacto: ";
  // Hasta que el numero no sea valido (de tipo numero y debe tener 8 digitos), seguir pidiendo
  while (true)
  {
    if (!(cin >> numero))
    { // No es un número
      cout << "\n ***Valor invalido.*** Debe ser un numero.\n";
      cout << "\n Ingrese nuevamente el numero del contacto: ";
      // Limpiar el error de la entrada
      cin.clear();
      // Ignorar el resto de la linea
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Reintentar leer el numero
      continue;
    }

    // Obtener la longitud del número
    int len = to_string(numero).length();
    // Validar que tenga exactamente 8 dígitos
    if (len == 8)
      // Número válido, salir del bucle
      break;

    cout << "\n *** Valor invalido.*** El numero debe ser de 8 digitos.\n ";
    cout << "\n Ingrese nuevamente el numero del contacto: ";
  }

  cout << "\n\nIngrese el email del contacto: ";
  // Hasta que el email no sea valido (contenga @ y .), seguir pidiendo
  while (true)
  {
    if (!(cin >> email))
    { // No es una entrada válida como string
      cout << "\n ***Valor invalido.*** Debe ser un email valido que contenga '@' y '.'.\n";
      cout << "\n Ingrese nuevamente el email del contacto: ";
      // Limpiar el error de la entrada
      cin.clear();
      // Ignorar el resto de la linea
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Reintentar leer el email
      continue;
    }

    // Validación mínima de email
    if (email.find('@') != string::npos && email.find('.') != string::npos)
      break; // Email válido

    cout << "\n ***Valor invalido.*** Debe ser un email valido que contenga '@' y '.'.\n";
    cout << "\n Ingrese nuevamente el email del contacto: ";
  }

  Contacto nuevoContacto(nombre, numero, email);
  contactos.push_back(nuevoContacto);

  // Imprimir el contacto agregado
  cout << "\n\nContacto agregado:\n";
  cout << "Nombre: " << contactos.back().nombre << "\n";
  cout << "Numero: " << contactos.back().numero << "\n";
  cout << "Email: " << contactos.back().email << "\n";
}
