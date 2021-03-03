#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

template< typename T>
int unbalance(Abin<T>& A)
{
    if(A.arbolVacio())
        return -1;
    else
        return unbalanceRec(A, A.raiz());
}

template <typename T>
int unbalanceRec(Abin<T>& A, typename Abin<T>::nodo n)
{
    if(Abin<T>::NODO_NULO == n)
        return 0;
    else
        return max(max(unbalanceRec(A, A.hijoIzqdo(n)), unbalanceRec(A, A.hijoDrcho(n))), abs(A.altura(A.hijoIzqdo(n)) - A.altura(A.hijoDrcho(n))));
}

int main(int argc, char const *argv[])
{
    ifstream ef("abin.dat");
    Abin<int> T;
    rellenarAbin(ef, T);
    ef.close();

    imprimirAbin(T);

    cout << "Unbalance in this tree is: " << unbalance(T) << endl;
    return 0;
}
