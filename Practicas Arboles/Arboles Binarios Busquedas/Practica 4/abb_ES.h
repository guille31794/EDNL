#ifndef ABB_ES_H_
#define ABB_ES_H_

#include <iostream>
#include <fstream>

using namespace std;

// Post: Introduce los elementos le�dos de la entrada est�ndar en A, usando fin para terminar la lectura.
template <typename T>
void rellenarAbb(Abb<T> &A, const T &fin)
{
   T e;

   cout << "Insertar elemento (fin = " << fin << "): ";
   cin >> e;

   while (e != fin)
   {
      A.insertar(e);
      cout << "Insertar elemento: ";
      cin >> e;
   }

   cout << endl;
}

// Post: Introduce los elementos leidos de un fichero en A, usando fin para terminar la lectura.
template <typename T>
void rellenarAbb(Abb<T> &A, ifstream &fe, const T& fin)
{
   T e;
   fe >> e;
   
   while(fe.good())
   {
      if(e != fin)
         A.insertar(e);
      
      fe >> e;
   }
}

// Post: Muestra en preorden los elementos de A en la salida est�ndar.
template <typename T>
void imprimirAbb(const Abb<T> &A)
{
   if (!A.vacio())
   {
      cout << "Raiz: ";
      imprimirDescendientes(A);
      cout << endl;
   }

   else
   {
      cout << "Arbol vacio" << endl;
   }
}

template <typename T>
void imprimirDescendientes(const Abb<T> &A)
{
   if (!A.vacio())
   {
      cout << A.elemento() << endl;

      if (!(A.izqdo()).vacio())
      {
         cout << "Hijo izquierdo de " << A.elemento() << ": ";
         imprimirDescendientes(A.izqdo());
      }

      if (!(A.drcho()).vacio())
      {
         cout << "Hijo derecho de " << A.elemento() << ": ";
         imprimirDescendientes(A.drcho());
      }
   }
}

// Post: Guarda en preorden los elementos de A en un fichero
template <typename T>
void imprimirAbb(const Abb<T> &A, ofstream &fs, T& fin)
{
   if (!A.vacio())
      imprimirDescendientes(A, fs, fin);
   else
   {
      cout << "Arbol vacio" << endl;
   }
}

template <typename T>
void imprimirDescendientes(const Abb<T> &A, ofstream &fs, T& fin)
{
   if (!A.vacio())
   {
      fs << A.elemento() << " ";

      if (!(A.izqdo()).vacio())
         imprimirDescendientes(A.izqdo(), fs, fin);
      else
         fs << fin << " ";

      if (!(A.drcho()).vacio())
         imprimirDescendientes(A.drcho(), fs, fin);
      else
         fs << fin << " ";
   }
}

#endif // ABIN_ES_H_
