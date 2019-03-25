#include "../agen.h"
#include "../agen_E-S.h"

template <typename T>
int depth(Agen<T> A, typename Agen<T>::nodo n)
{
    if (A.padre(n) != Agen<T>::NODO_NULO)
        return 1 + depth(A, A.padre(n));
}

int main()
{
    Agen<int> T;
    int fin = -1;

    rellenarAgen(T, fin);
    imprimirAgen(T);

    Agen<int>::nodo n = A.raiz();
    while(n != Agen<T>::NODO_NULO)
        n = A.hijoIzqdo(n);
    
    cout << "The depth is: " << depth(A, n) << endl;

    return 0;
}