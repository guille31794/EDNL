#ifndef ABIN_E_S_H
#define ABIN_E_S_H

#include <cassert>
#include <iostream>
#include <fstream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

template <typename T>
void rellenarAbin(Abin<T>& A, const T& fin)
// Pre: A esta vacio.
// Post: Rellena el arbol A con la estructura y elementos
//       leidos en preorden de la entrada estandar, usando
//       fin como elemento especial para introducir nodos nulos.
{
   T e;

   assert(A.arbolVacioB());
   cout << "Raiz (Fin = " << fin << "): "; cin >> e;
   if (e != fin) 
   {
      A.insertarRaiz(e);
      rellenarDescendientes(A.raiz(), A, fin);
   }
}

template <typename T>
void rellenarDescendientes(typename Abin<T>::nodo r, Abin<T>& A, const T& fin)
// Pre: r es un nodo hoja de A.
// Post: Lee de la entrada estandar y en preorden los descendientes de r,
//       usando fin para introducir nodos nulos.
{
   T ehi, ehd;

   assert(A.hijoIzqdo(r) == Abin<T>::NODO_NULO &&
          A.hijoDrcho(r) == Abin<T>::NODO_NULO);
   cout << "Hijo izqdo. de " << A.elemento(r) <<
                " (Fin = " << fin << "): ";
   cin >> ehi;
   if (ehi != fin) 
   {
      A.insertarHijoIzqdo(r, ehi);
      rellenarDescendientes(A.hijoIzqdo(r), A, fin);
   }
   cout << "Hijo drcho. de " << A.elemento(r) <<
                " (Fin = " << fin << "): ";
   cin >> ehd;
   if (ehd != fin) 
   {
      A.insertarHijoDrcho(r, ehd);
      rellenarDescendientes(A.hijoDrcho(r), A, fin);
   }
}

template <typename T>
void rellenarAbin(istream& is, Abin<T>& A)
// Pre: A esta vacio.
// Post: Extrae los nodos de A del flujo de entrada is,
//       que contendra el elemento especial que denota
//       un nodo nulo seguido de los elementos en preorden,
//       incluyendo los correspondientes a nodos nulos.
{
   T e, fin;

   assert(A.arbolVacio());
   if (is >> fin && is >> e && e != fin) 
   {
      A.insertarRaiz(e);
      rellenarDescendientes(is, A.raiz(), A, fin);
   }
}

template <typename T>
void rellenarDescendientes(istream& is, typename Abin<T>::nodo r, Abin<T>& A, const T& fin)
// Pre: r es un nodo hoja de A.
// Post: Lee del flujo de entrada is y en preorden los descendientes de r,
//       usando fin para los nodos nulos.
{
   T ehi, ehd;

   assert(A.hijoIzqdo(r) == Abin<T>::NODO_NULO &&
          A.hijoDrcho(r) == Abin<T>::NODO_NULO);
   if (is >> ehi && ehi != fin) 
   {
      A.insertarHijoIzqdo(r, ehi);
      rellenarDescendientes(is, A.hijoIzqdo(r), A, fin);
   }
   if (is >> ehd && ehd != fin) 
   {
      A.insertarHijoDrcho(r, ehd);
      rellenarDescendientes(is, A.hijoDrcho(r), A, fin);
   }
}

template <typename T>
void imprimirAbin (const Abin<T>& A)
// Post: Muestra los nodos de A en la salida estandar
{
   if (!A.arbolVacio())
   {
      cout << "Raiz del Arbol: "
                << A.elemento(A.raiz()) << endl;
      imprimirDescendientes(A.raiz(), A);
   }
   else
      cout << "Arbol vacio\n";
}

template <typename T>
void imprimirDescendientes (typename Abin<T>::nodo r, const Abin<T>& A)
// Post: Muestra los descendientes de r en la salida estandar.
{
   if (A.hijoIzqdo(r) != Abin<T>::NODO_NULO)
   {
      cout << "Hijo izqdo de " << A.elemento(r) << ": "
                << A.elemento(A.hijoIzqdo(r)) << endl;
      imprimirDescendientes(A.hijoIzqdo(r), A);
   }
   if (A.hijoDrcho(r) != Abin<T>::NODO_NULO)
   {
      cout << "Hijo derecho de " << A.elemento(r) << ": "
                << A.elemento(A.hijoDrcho(r)) << endl;
      imprimirDescendientes(A.hijoDrcho(r), A);
   }
}

template <typename T>
void imprimirAbin (ostream& os, const Abin<T>& A, const T& fin)
// Post: Inserta en el flujo de salida os los nodos de A en preorden,
//       precedidos del elemento especial usado para denotar un nodo nulo.
{
   if (!A.arbolVacio())
   {
      os << fin << endl
         << A.elemento(A.raiz()) << ' ';
      imprimirDescendientes(os, A.raiz(), A, fin);
      os << endl;
   }
}

template <typename T>
void imprimirDescendientes (ostream& os, typename Abin<T>::nodo r, const Abin<T>& A, const T& fin)
// Post: Inserta en el flujo de salida os y en preorden
//       los descendientes de r, usando fin como nodo nulo.
{
   if (A.hijoIzqdo(r) != Abin<T>::NODO_NULO)
   {
      os << A.elemento(A.hijoIzqdo(r)) << ' ';
      imprimirDescendientes(os, A.hijoIzqdo(r), A, fin);
   }
   else
      os << fin << ' ';
   if (A.hijoDrcho(r) != Abin<T>::NODO_NULO)
   {
      os << A.elemento(A.hijoDrcho(r)) << ' ';
      imprimirDescendientes(os, A.hijoDrcho(r), A, fin);
   }
   else
      os << fin << ' ';
}

#endif   // ABIN_E_S_H
