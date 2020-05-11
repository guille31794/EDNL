#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
int AbinHeightRec(Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + max(AbinHeightRec(A, A.hijoIzqdo(n)), 
        AbinHeightRec(A, A.hijoDrcho(n)));
}

template <typename T>
int AbinImbalanceRec(Abin<T>& A, 
typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + 
        max(abs(AbinHeightRec(A, A.hijoDrcho(n)) - 
        AbinHeightRec(A, A.hijoIzqdo(n))), 
        max(AbinImbalanceRec(A, A.hijoIzqdo(n)),
        AbinImbalanceRec(A, A.hijoDrcho(n))));
}

template <typename T>
int AbinImbalance(Abin<T>& A)
{
    return AbinImbalanceRec(A, A.raiz());
}

int main(int argc, char const *argv[])
{
    Abin<int> A;
    ifstream f("abin.dat");
    
    rellenarAbin(f, A);

    cout << "The imbalance of the tree is: " << 
    AbinImbalance(A) << endl;

    return 0;
}
