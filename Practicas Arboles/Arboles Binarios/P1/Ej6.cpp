#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
int AbinHeightRec(Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + max(AbinHeightRec(A, A.hijoIzqdoB(n)), 
        AbinHeightRec(A, A.hijoDrchoB(n)));
}

template <typename T>
int AbinImbalanceRec(Abin<T>& A, 
typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + 
        max(abs(AbinHeightRec(A, A.hijoDrchoB(n)) - 
        AbinHeightRec(A, A.hijoIzqdoB(n))), 
        max(AbinImbalanceRec(A, A.hijoIzqdoB(n)),
        AbinImbalanceRec(A, A.hijoDrchoB(n))));
}

template <typename T>
int AbinImbalance(Abin<T>& A)
{
    return AbinImbalanceRec(A, A.raizB());
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
