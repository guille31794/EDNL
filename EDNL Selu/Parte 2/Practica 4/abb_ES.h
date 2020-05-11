/*******************************/
/*          abb_ES.h           */
/*                             */
/*    E/S de �rboles Binarios  */
/*         de B�squeda         */
/*                             */
/*     Jes�s Rubio Gonz�lez    */
/*                             */
/*******************************/

#ifndef ABB_ES_H_
#define ABB_ES_H_

#include <iostream>

using namespace std;

// Post: Introduce los elementos le�dos de la entrada est�ndar en A, usando fin para terminar la lectura.
template <typename T>
void rellenarAbb(Abb<T>& A, const T& fin)
{
   T e;

   cout << "Insertar elemento (fin = " << fin << "): ";
   cin  >> e;

   while(e != fin)
   {
      A.insertar(e);
      cout << "Insertar elemento: ";
      cin  >> e;
   }

   cout << endl;
}

// Post: Muestra en preorden los elementos de A en la salida est�ndar.
template <typename T>
void imprimirAbb(const Abb<T>& A)
{
   if(!A.vacio())
   {
      cout <<"Raiz: "; 
      imprimirDescendientes(A);
      cout << endl;
   }

   else
   {
      cout << "Arbol vacio" << endl;
   }

}

template <typename T>
void imprimirDescendientes(const Abb<T>& A)
{
   if(!A.vacio())
   {
      cout << A.elemento() << endl;

      if(!(A.izqdo()).vacio())
      {
         cout << "Hijo izquierdo de " << A.elemento() << ": ";
         imprimirDescendientes(A.izqdo());
      }

      if(!(A.drcho()).vacio())
      {
         cout << "Hijo derecho de " << A.elemento() << ": ";
         imprimirDescendientes(A.drcho());
      }
   }
}

#endif   // ABIN_ES_H_
