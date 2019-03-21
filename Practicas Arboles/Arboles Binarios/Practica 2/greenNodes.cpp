#include "../abin.h"
#include "../abin_E-S.h"

template<typename T>
int cuentaHijos(typename Abin<T>::nodo n, Abin<T>& A)
{
  int cont = 0;

  if(A.hijoIzqdoB(n) != Abin<T>::NODO_NULO)
    cont ++;
  if(A.hijoDrchoB(n) != Abin<T>::NODO_NULO)
    cont ++;

  return cont;
}

template<typename T>
int recurNodoVerde(typename Abin<T>::nodo n, Abin<T>& A)
{
  int cont = 0;

  if(n == Abin<T>::NODO_NULO)
    return cont;
  else
  {
    int numeroNietos = 0;

    if(A.hijoIzqdoB(n) != Abin<T>::NODO_NULO)
      numeroNietos += cuentaHijos(A.hijoIzqdoB(n), A);
    if(A.hijoDrchoB(n) != Abin<T>::NODO_NULO)
      numeroNietos += cuentaHijos(A.hijoDrchoB(n), A);
    if(numeroNietos == 3)
      cont++;

    return cont + recurNodoVerde(A.hijoIzqdoB(n), A) + recurNodoVerde(A.hijoDrchoB(n), A);
  }
}

template<typename T>
int nodoVerde(Abin<T>& A)
{
  return recurNodoVerde(A.raizB(), A);
}

int main(int argc, char const *argv[])
{
    Abin<int> T;
    int fin = -1;

    rellenarAbin(T, fin);

    cout << "There are: " << nodoVerde(T) << endl;

    return 0;
}
