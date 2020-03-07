#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
int AbinDeepthRec(Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + AbinDeepthRec(A, A.padreB(n));
}

template <typename T>
int AbinDeepth(Abin<T>& A, typename Abin<T>::nodo n)
{
    return AbinDeepthRec(A, n);
}

int main(int argc, char const *argv[])
{
    Abin<int> A;
    ifstream file("abin.dat");

    rellenarAbin(file, A);
    imprimirAbin(A);

    Abin<int>::nodo n = A.raizB();
    n = A.hijoDrchoB(n);
    n = A.hijoDrchoB(n);
    n = A.hijoDrchoB(n);

    cout << "The deepth of the node is: " << 
    AbinDeepth(A, n) << endl;

    return 0;
}
