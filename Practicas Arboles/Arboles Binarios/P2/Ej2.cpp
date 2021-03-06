#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
void AbinReflectedRec( typename Abin<T>::nodo n1, 
Abin<T> A, typename Abin<T>::nodo n2, Abin<T>& B)
{
    if(A.hijoIzqdo(n1) != Abin<T>::NODO_NULO
    && A.hijoDrcho(n1) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoDrcho(n2, A.elemento(A.hijoIzqdo(n1)));
        B.insertarHijoIzqdo(n2, A.elemento(A.hijoDrcho(n1)));
        AbinReflectedRec(A.hijoIzqdo(n1), A, B.hijoDrcho(n2), B);
        AbinReflectedRec(A.hijoDrcho(n1), A, B.hijoIzqdo(n2), B);
    }
    else if(A.hijoIzqdo(n1) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoDrcho(n2, A.elemento(A.hijoIzqdo(n1)));
        AbinReflectedRec(A.hijoIzqdo(n1), A, B.hijoDrcho(n2), B);
    }
    else
    {
        B.insertarHijoIzqdo(n2, A.elemento(A.hijoDrcho(n1)));
        AbinReflectedRec(A.hijoDrcho(n1), A, B.hijoIzqdo(n2), B);
    }
}

template <typename T>
Abin<T> AbinReflected(Abin<T> A)
{
    Abin<T> B;

    if(!A.arbolVacio())
    {
        B.insertarRaiz(A.raiz().elemento());

        AbinReflectedRec(A.raiz(), A, B.raiz(), B);
    }

    return B;
}

int main(int argc, char const *argv[])
{
    Abin<int> A, Ar;
    ifstream f("abin.dat");

    rellenarAbin(f, A);
    imprimirAbin(A);

    Ar = AbinReflected(A);
    imprimirAbin(Ar);

    return 0;
}
