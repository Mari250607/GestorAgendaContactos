#pragma once
#include "NodoArbolContactos.h"
#include "iostream"
using namespace std;

class ArbolContactos
{
private:
  NodoArbolContactos *raiz;

public:
  // Constructor por defecto
  ArbolContactos() : raiz(nullptr) {}
  // Getter para la raiz
  NodoArbolContactos *getRaiz() { return raiz; }
  // Setter para la raiz
  void setRaiz(NodoArbolContactos *nuevaRaiz) { raiz = nuevaRaiz; }
  // Insertar Contacto (metodo publico simplificado)
  void insertarContacto(Contacto c);
  // Imprimir arbol de contactos en inorden (recursivo)
  void mostrarInorden(NodoArbolContactos *nodo);
  // Imprimir arbol de contactos en preorden (recursivo)
  void mostrarPreorden(NodoArbolContactos *nodo);

private:
  // Insertar contacto (BST - Binary Search Tree) en orden alfabetico y de manera recursiva
  void insertarContactoBST(NodoArbolContactos *&Nodo, Contacto c);
};
