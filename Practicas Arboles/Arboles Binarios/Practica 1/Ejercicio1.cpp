#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
int nodeRec(typename Abin<T>::nodo n, Abin<T> A)
{
    if( n == Abin<T>::NODO_NULO) 
        return 0;
    else
        return 1 + nodeRec(A.hijoIzqdoB(n), A) + nodeRec(A.hijoDrchoB(n), A);
    
}

template <typename T>
int nodeNumber(Abin<T> A)
{
    return nodeRec(A.raizB(), A);
}

int main(int argc, char const *argv[])
{
    Abin<int> A;
    int fin = -1;
    
    rellenarAbin(A, fin);
    imprimirAbin(A);

    cout << nodeNumber(A) << endl;

    return 0;
}
