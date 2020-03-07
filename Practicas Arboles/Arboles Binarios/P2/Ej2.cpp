#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
Abin<T> AbinReflectedRec(Abin<T>& A, 
typename Abin<T>::nodo n1, typename 
Abin<T>::nodo n2)
{
    auto aux = A.elemento(n1);
    A.elemento(n1) = A.elemento(n2);
    A.elemento(n2) = aux;

    if(n1 == Abin<T>::NODO_NULO 
    && n2 == Abin<T>::NODO_NULO)
        return A;
    else if(n1 != Abin<T>::NODO_NULO
    && n2 == Abin<T>::NODO_NULO)
        return AbinReflectedRec(A,
        A.hijoIzqdoB(n1), A.hijoDrchoB(n1));
    else if (n1 == Abin<T>::NODO_NULO
    && n2 != Abin<T>::NODO_NULO)
        return AbinReflectedRec(A,
        A.hijoIzqdoB(n2), A.hijoDrchoB(n2));
    else
    {
        A = AbinReflectedRec(A, A.hijoIzqdoB(n1),
        A.hijoDrchoB(n1));
        A = AbinReflectedRec(A, A.hijoDrchoB(n2),
        A.hijoDrchoB(n2));
        return A;
    }

}

template <typename T>
Abin<T> AbinReflected(Abin<T> A)
{
    assert(!A.arbolVacioB());
    return AbinReflectedRec(A, A.hijoIzqdoB(A.raizB()),
    A.hijoDrchoB(A.raizB()));
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
