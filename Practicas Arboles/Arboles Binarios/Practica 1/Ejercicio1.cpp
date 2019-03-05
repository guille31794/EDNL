#include "abinEn.hpp"
#include "abin_E-S.hpp"

int nodeRec(nodo n, Abin<T> A)
{
    if( n == NODO_NULO) 
        return 0;
    else
        return 1 + nodeRec(A.hijoIzqdoB(n) + A.hijoDrchoB(n), A);
    
}

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
