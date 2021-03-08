#include <fstream>
#include <iostream>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

template <typename T>
Abin<T> reflectedTree(Abin<T>& A)
{
    Abin<T> R;
    if(A.arbolVacio()) 
        return R;
    
    R.insertarRaiz(A.elemento(A.raiz()));
    reflectedTree(A, A.raiz(), R, R.raiz());
    return R;
}

template <typename T>
void reflectedTree(Abin<T>& A, typename Abin<T>::nodo n1, Abin<T>& R,  typename Abin<T>::nodo n2)
{
    if(Abin<T>::NODO_NULO != A.hijoIzqdo(n1))
    {
        R.insertarHijoDrcho(n2, A.elemento(A.hijoIzqdo(n1)));
        reflectedTree(A, A.hijoIzqdo(n1), R, R.hijoDrcho(n2));
    }

    if(Abin<T>::NODO_NULO != A.hijoDrcho(n1))
    {
        R.insertarHijoIzqdo(n2, A.elemento(A.hijoDrcho(n1)));
        reflectedTree(A, A.hijoDrcho(n1), R, R.hijoIzqdo(n2));
    }

}

int main(int argc, char const *argv[])
{
    ifstream ef("abin.dat");
    Abin<int> T;
    rellenarAbin(ef, T);
    ef.close();

    imprimirAbin(T);

    cout << "The reflected tree is: \n";
    imprimirAbin(reflectedTree(T));
    cout << endl;

    return 0;
}
