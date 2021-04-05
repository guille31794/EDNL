#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "../agen.h"
#include "../agen_E-S.h"

using namespace std;

template <typename A>
int altura(typename Agen<A>::nodo n, Agen<A> T)
{
    if(Agen<A>::NODO_NULO == n)
        return -1;
    else
    {
        int hmax = 1 + altura(T.hijoIzqdo(n), T);

        while(Agen<A>::NODO_NULO != n)
        {
            hmax = max(hmax, altura(T.hermDrcho(n), T));
            n = T.hermDrcho(n);
        }
        
        return hmax;
    }
}

template <typename A>
int desequilibrio(Agen<A> T)
{
    if(T.arbolVacio())
        return 0;
    else
        return desequilibrioRec(T.raiz(), T);
}

template <typename A>
int desequilibrioRec(typename Agen<A>::nodo n, Agen<A> T)
{
    if(Agen<A>::NODO_NULO == n)
        return 0;
    else
    {
        typename Agen<A>::nodo hijo = T.hijoIzqdo(n);
        int rama_larga, rama_corta, desequilibrio = 0;

        rama_larga = rama_corta = altura(hijo, T);
        while(hijo != Agen<A>::NODO_NULO)
        {
            desequilibrio = max(rama_larga-rama_corta, desequilibrioRec(hijo, T));
            hijo = T.hermDrcho(hijo);
            rama_larga = max(rama_larga, altura(hijo, T));
            rama_corta = min(rama_corta, altura(hijo, T));
        }

        return 1 + desequilibrio;
    }
}

int main()
{
    Agen<int> T;
    ifstream inf("agen.dat");

    rellenarAgen(inf, T);
    inf.close();
    imprimirAgen(T);

    cout << "The altura of the tree is: " << altura(T.raiz(), T) << endl;
    cout << "The desequilibrio of the tree is: " << desequilibrio(T) << endl;
    
    return 0;
}