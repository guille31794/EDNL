#include "iostream"
#include "fstream"
#include "../agen.h"
#include "../agen_E-S.h"

using namespace std;

template <typename T>
unsigned degree(Agen<T>& A)
{
    if(A.arbolVacio())
        return 0;
    else
        return degree(A, A.raiz());
}

template <typename T>
unsigned degree(Agent<T>& A, typename Agen<T>::nodo n)
{
    if(Agen<T>::NODO_NULO == n)
        return 0;
    else
    {
        unsigned n_sons = numberOfSons(A, A.hijoIzqdo(n));

        n = A.hijoIzqdo(n);

        while(Agen<T>::NODO_NULO != n)
        {
            n_sons = max(n_sons, degree(A, A.hijoIzqdo(n)));
            n = A.hermanoDrcho(n);
        }

        return n_sons;
    }
}

template <typename T>
unsigned numberOfSons(Agen<T>& A, typename Agen<T>::nodo n)
{
    unsigned n_sons = 0;

    while(Agen<T>::NODO_NULO != n)
    { 
        ++n_sons;
        n = A.hermanoDrcho(n);
    }

    return n_sons;
}

int main(int argc, char const *argv[])
{
    Agen<int> T;
    ifstream inf("agen.dat");

    rellenarAgen(inf, T);
    inf.close();
    imprimirAgen(T);
    
    cout << "The degree of the tree is: " << degree(T) << endl;

    return 0;
}