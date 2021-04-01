#include <iostream>
#include <fstream>
#include "../agen.h"
#include "../agen_E-S.h"

using namespace std;

template <typename T>
int deepth(Agen<T> A, typename Agen<T>::nodo n)
{
    if(Agen<T>::NODO_NULO == n)
        return -1;
    else 
        return 1 + deepth(A, A.padre(n));
}

int main()
{
    Agen<int> T;
    ifstream inf("agen.dat");

    rellenarAgen(inf, T);
    inf.close();
    imprimirAgen(T);

    Agen<int>::nodo n = T.raiz();
    n = T.hijoIzqdo(n);
    n = T.hermDrcho(n);
    n = T.hijoIzqdo(n);
    n = T.hermDrcho(n);
    n = T.hijoIzqdo(n);

    cout << "The deepth of the node is: " << deepth(T, n) << endl;

    return 0;
}