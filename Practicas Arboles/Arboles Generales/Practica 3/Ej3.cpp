#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "../agen.h"
#include "../agen_E-S.h"

using namespace std;

template <typename A>
int height(Agen<A> T, typename Agen<A>::nodo n)
{
    if(Agen<A>::NODO_NULO == n)
        return -1;
    else
    {
        int hmax = 1 + height(T, T.hijoIzqdo(n));
        
        while(Agen<A>::NODO_NULO != n)
        {
            hmax = max(hmax, height(T, T.hermDrcho(n)));
            n = T.hermDrcho(n);
        }
        
        return hmax;
    }
}

template <typename A>
int unbalance(Agen<A> T)
{
    if(T.arbolVacio())
        return 0;
    else
        return unbalance(T, T.raiz());
}

template <typename A>
int unbalance(Agen<A> T, typename Agen<A>::nodo n)
{
    if(Agen<A>::NODO_NULO == n)
        return -1;
    else
    {
        int umax = max(abs(height(T, n) - height(T, T.hermDrcho(n))), 
        unbalance(T, T.hijoIzqdo(n)));
        n = T.hermDrcho(n);

        while (Agen<A>::NODO_NULO != n)
        {
            umax = max(umax, unbalance(T, T.hermDrcho(n)));
            n = T.hermDrcho(n);
        }

        return umax;
    }
}

int main()
{
    Agen<int> T;
    ifstream inf("agen.dat");

    rellenarAgen(inf, T);
    inf.close();
    imprimirAgen(T);

    cout << "The height of the tree is: " << height(T, T.raiz()) << endl;
    cout << "The unbalance of the tree is: " << unbalance(T) << endl;
    
    return 0;
}