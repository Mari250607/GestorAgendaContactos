#include "ListaEnlazada.h"
#include "Nodo.h"
#include <iostream>

void ListaEnlazada::insertarFinal(Contacto &contacto)
{
  // Crear un nuevo nodo (puntero) para el nuevo contacto
  Nodo *nuevoNodo = new Nodo();
  // Asignar el contacto al nuevo nodo
  nuevoNodo->dato = contacto;
  nuevoNodo->siguiente = nullptr;

  // Si la lista esta vacia, insertar el nuevo nodo como cabeza
  if (cabeza == nullptr)
  {
    cabeza = nuevoNodo;
  }
  else
  {
    // Recorrer la lista hasta el ultimo nodo
    Nodo *actual = cabeza;
    while (actual->siguiente != nullptr) // Mientras no sea el ultimo nodo (es decir, su siguiente no es nullptr)
    {
      actual = actual->siguiente;
    }
    // Insertar el nuevo nodo al final de la lista
    actual->siguiente = nuevoNodo;
  }
}

int ListaEnlazada::mostrarLista()
{
  // Mostrar mensaje si la lista esta vacia
  if (cabeza == nullptr)
  {
    std::cout << "La lista se encuentra vacia.\n\n";
    return 0;
  }
  // Indice de elementos (para mostrar como posicion en la lista)
  int indice = 1;
  // Recorrer la lista y mostrar los contactos
  Nodo *actual = cabeza;
  while (actual != nullptr)
  {
    // Mostrar el contacto actual
    std::cout << indice << ". Nombre: " << actual->dato.nombre << ", Numero: " << actual->dato.numero << ", Email: " << actual->dato.email << std::endl;
    actual = actual->siguiente;
    // Incrementar el indice
    indice++;
  }
  return indice; // Retornar el numero total de elementos mostrados
}

// Eliminar un elemento de la lista por numero de posicion
void ListaEnlazada::eliminarElemento(int numeroPosicion)
{
  // Validar que la posicion sea mayor a 0
  if (numeroPosicion <= 0)
  {
    std::cout << "Posicion invalida. Debe ser mayor a 0.\n\n";
    return;
  }

  // Si la lista esta vacia, no hay nada que eliminar
  if (cabeza == nullptr)
  {
    std::cout << "La lista esta vacia. No hay elementos para eliminar.\n\n";
    return;
  }

  // Si se quiere eliminar el primer elemento (cabeza)
  if (numeroPosicion == 1)
  {
    Nodo *nodoAEliminar = cabeza;
    cabeza = cabeza->siguiente; // Actualizar la cabeza al siguiente nodo
    delete nodoAEliminar;       // Liberar memoria del nodo eliminado
    std::cout << "\n\n||| Elemento en la posicion " << numeroPosicion << " eliminado. |||\n\n";
    return;
  }

  // Recorrer la lista para encontrar el nodo anterior al que se quiere eliminar
  Nodo *actual = cabeza;
  Nodo *anterior = nullptr;

  // Indice para rastrear la posicion actual
  int indicePosicion = 1;

  // Recorrer hasta la posicion deseada o hasta el final de la lista
  while (actual != nullptr && indicePosicion < numeroPosicion)
  {
    anterior = actual;
    actual = actual->siguiente;
    indicePosicion++;
  }

  // Si actual es nullptr, significa que la posicion es invalida
  if (actual == nullptr)
  {
    std::cout << "Posición invalida. No existe un elemento en la posicion " << numeroPosicion << ".\n\n";
    return;
  }

  // Ajustar los punteros para eliminar el nodo
  anterior->siguiente = actual->siguiente;
  delete actual; // Liberar memoria del nodo eliminado
  std::cout << "\n\n||| Elemento en la posicion " << numeroPosicion << " eliminado. |||\n\n";
}