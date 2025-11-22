#include "AgendaContactos.h"
#include <iostream>

// Agrega un nuevo contacto a la agenda solicitando datos al usuario
void AgendaContactos::agregarContacto()
{
  // Solicitar datos del contacto al usuario
  string nombre;
  int numero;
  string email;

  std::cout << "\n\nIngrese el nombre del contacto: ";
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
      std::cout << "\n Ingrese nuevamente el nombre del contacto: ";
    }
  }

  std::cout << "\n\nIngrese el numero del contacto: ";
  // Hasta que el numero no sea valido (de tipo numero y debe tener 8 digitos), seguir pidiendo
  while (true)
  {
    if (!(std::cin >> numero))
    { // No es un número
      std::cout << "\n ***Valor invalido.*** Debe ser un numero.\n";
      std::cout << "\n Ingrese nuevamente el numero del contacto: ";
      // Limpiar el error de la entrada
      std::cin.clear();
      // Ignorar el resto de la linea
      std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Reintentar leer el numero
      continue;
    }

    // Obtener la longitud del número
    int len = to_string(numero).length();
    // Validar que tenga exactamente 8 dígitos
    if (len == 8)
      // Número válido, salir del bucle
      break;

    std::cout << "\n *** Valor invalido.*** El numero debe ser de 8 digitos.\n ";
    std::cout << "\n Ingrese nuevamente el numero del contacto: ";
  }

  std::cout << "\n\nIngrese el email del contacto: ";
  // Hasta que el email no sea valido (contenga @ y .), seguir pidiendo
  while (true)
  {
    if (!(std::cin >> email))
    { // No es una entrada válida como string
      std::cout << "\n ***Valor invalido.*** Debe ser un email valido que contenga '@' y '.'.\n";
      std::cout << "\n Ingrese nuevamente el email del contacto: ";
      // Limpiar el error de la entrada
      std::cin.clear();
      // Ignorar el resto de la linea
      std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Reintentar leer el email
      continue;
    }

    // Validación mínima de email
    if (email.find('@') != string::npos && email.find('.') != string::npos)
      break; // Email válido

    std::cout << "\n ***Valor invalido.*** Debe ser un email valido que contenga '@' y '.'.\n";
    std::cout << "\n Ingrese nuevamente el email del contacto: ";
  }

  Contacto nuevoContacto(nombre, numero, email);
  contactos.push_back(nuevoContacto);

  // Imprimir el contacto agregado
  std::cout << "\n\nContacto agregado:\n";
  std::cout << "Nombre: " << contactos.back().nombre << "\n";
  std::cout << "Numero: " << contactos.back().numero << "\n";
  std::cout << "Email: " << contactos.back().email << "\n";
}

// Agrega contacto con datos especificos (usado para transferir desde pendientes)
void AgendaContactos::agregarContacto(const Contacto &contacto)
{
  contactos.push_back(contacto);
}

// Ordenar los contactos por nombre
void AgendaContactos::ordenarContactosPorNombre()
{
  // Ordenar los contactos por nombre
  for (size_t i = 0; i < contactos.size(); ++i) // Bucle externo sera el numero de pasadas
  {
    for (size_t j = 0; j < contactos.size() - i - 1; ++j) // Bucle interno para comparaciones
    {
      // Comparar nombres (si el actual es mayor que el siguiente, intercambiar)
      if (contactos[j].nombre > contactos[j + 1].nombre)
      {
        std::swap(contactos[j], contactos[j + 1]); // Intercambiar contactos
      }
    }
  }
}

// Mostrar todos los contactos en la agenda (ordenados por nombre)
void AgendaContactos::listarContactos()
{
  // Si no hay contactos, mostrar mensaje
  if (contactos.empty())
  {
    std::cout << "\n\n||| No hay contactos en la agenda principal para mostrar. |||\n";
    return;
  }

  // Ordenar los contactos por nombre antes de mostrar
  ordenarContactosPorNombre();

  std::cout << "\n\nLista de Contactos (ordenados por nombre):\n";
  for (const auto &contacto : contactos)
  {
    std::cout << "- Nombre: " << contacto.nombre << ", Numero: " << contacto.numero << ", Email: " << contacto.email << "\n";
  }
}