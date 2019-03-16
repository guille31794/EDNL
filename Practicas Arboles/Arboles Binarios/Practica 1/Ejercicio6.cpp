#include "../abin.h"
#include "../abin_E-S.h"

int max(int a, int b)
{
    if(a >= b)
        return a;
    else
        return b;
}

template <typename T>
int heightRec(Abin<T> A, typename Abin<T>::nodo n)
{
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else 
        return 1 + max(heightRec(A, A.hijoIzqdoB(n)), heightRec(A, A.hijoDrchoB(n)));
}

template <typename T>
int maxImbalance(Abin<T> A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return max(abs(heightRec(A, A.hijoIzqdoB(n)) - 
        heightRec(A, A.hijoDrchoB(n))),
        max(maxImbalance(A, A.hijoIzqdoB(n)), 
        maxImbalance(A, A.hijoDrchoB(n))));
}

template <typename T>
int imbalance(Abin<T> A)
{
    int imbalance;

    if(!A.arbolVacioB())
    {
        typename Abin<T>::nodo root = A.raizB();

        if(A.hijoIzqdoB(root) != Abin<T>::NODO_NULO ||
        A.hijoDrchoB(root) != Abin<T>::NODO_NULO)
           imbalance = maxImbalance(A, root);
        else
            imbalance = 0;
    }    
    else
        imbalance = -1;

    return imbalance;
}

int main(int argc, char const *argv[])
{
    Abin<int> A;
    int fin = -1;

    rellenarAbin(A, fin);

    cout << "The imbalance is :" << imbalance(A) << endl;

    return 0;
}
