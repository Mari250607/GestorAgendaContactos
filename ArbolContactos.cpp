#include "ArbolContactos.h"

// Insertar Contacto (metodo publico simplificado)
void ArbolContactos::insertarContacto(Contacto c)
{
  // Si la raiz es nula, crear un nuevo nodo como raiz y setearlo
  if (ArbolContactos::raiz == nullptr)
  {
    ArbolContactos::setRaiz(new NodoArbolContactos(c));
    return;
  }
  // Llamar al metodo recursivo para insertar el contacto en el arbol
  insertarContactoBST(ArbolContactos::raiz, c);
}

// Insertar contacto en el arbol (BST - Binary Search Tree) en orden alfabetico y de manera recursiva
void ArbolContactos::insertarContactoBST(NodoArbolContactos *&nodo, Contacto c)
{
  // Si el nodo es nulo, crear un nuevo nodo
  if (nodo == nullptr)
  {
    nodo = new NodoArbolContactos(c);
    return;
  }

  // Si el nombre del contacto es menor, ir a la izquierda
  if (c.nombre < nodo->contacto.nombre)
  {
    insertarContactoBST(nodo->izquierdo, c);
  }
  else // Si el nombre es mayor o igual, ir a la derecha
  {
    insertarContactoBST(nodo->derecho, c);
  }
}

// Ordenar en inorden (recursivo)
void ArbolContactos::mostrarInorden(NodoArbolContactos *nodo)
{
  // Caso base: si el nodo es nulo, retornar
  if (nodo != nullptr)
  {
    // Recorrer el subarbol izquierdo
    mostrarInorden(nodo->izquierdo);
    // Imprimir el contacto del nodo actual
    cout << "Nombre: " << nodo->contacto.nombre << ", Numero: " << nodo->contacto.numero << ", Email: " << nodo->contacto.email << endl;
    // Recorrer el subarbol derecho
    mostrarInorden(nodo->derecho);
  }
}

// Ordenar en preorden (recursivo)
void ArbolContactos::mostrarPreorden(NodoArbolContactos *nodo)
{
  // Caso base: si el nodo es nulo, retornar
  if (nodo != nullptr)
  {
    // Imprimir el contacto del nodo actual
    cout << "Nombre: " << nodo->contacto.nombre << ", Numero: " << nodo->contacto.numero << ", Email: " << nodo->contacto.email << endl;
    // Recorrer el subarbol izquierdo
    mostrarPreorden(nodo->izquierdo);
    // Recorrer el subarbol derecho
    mostrarPreorden(nodo->derecho);
  }
}
