#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

template <typename T>
bool pseudoComplete(Abin<T>& A)
{
    return A.arbolVacio() ? false : pseudoComplete(A, A.hijoIzqdo(A.raiz())) && pseudoComplete(A, A.hijoDrcho(A.raiz()));
}

template <typename T>
bool pseudoComplete(Abin<T>& A, typename Abin<T>::nodo n)
{
    if (Abin<T>::NODO_NULO == A.hijoIzqdo(n) && Abin<T>::NODO_NULO == A.hijoDrcho(n))
        if ((Abin<T>::NODO_NULO != A.hijoIzqdo(A.padre(n)) && Abin<T>::NODO_NULO != A.hijoDrcho(A.padre(n))) 
        || (Abin<T>::NODO_NULO == A.hijoIzqdo(A.padre(n)) && Abin<T>::NODO_NULO == A.hijoDrcho(A.padre(n))))
            return true;
        else
            return false;
    else if (Abin<T>::NODO_NULO != A.hijoIzqdo(n) && Abin<T>::NODO_NULO == A.hijoDrcho(n))
        return pseudoComplete(A, A.hijoIzqdo(n));
    else if (Abin<T>::NODO_NULO != A.hijoIzqdo(n) && Abin<T>::NODO_NULO == A.hijoDrcho(n))
        return pseudoComplete(A, A.hijoDrcho(n));
    else
        return pseudoComplete(A, A.hijoIzqdo(n)) && pseudoComplete(A, A.hijoDrcho(n));
}

int main(int argc, char const *argv[])
{
    ifstream ef("abin.dat");
    Abin<uint_fast8_t> T;
    rellenarAbin(ef, T);
    ef.close();

    imprimirAbin(T);

    cout << "The tree is: ";
    pseudoComplete(T) ? cout << "pseudocomplete" : cout << "not pseudocomplete";
    cout << endl;

    return 0;
}