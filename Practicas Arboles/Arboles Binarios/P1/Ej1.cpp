#include "../abin.h"
#include "../abin_E-S.h"

template<typename T>
int countAbinNodes(Abin<T>& A)
{
    return countAbinNodesRecursive(A.raiz(), A);
}

template<typename T>
int countAbinNodesRecursive(typename Abin<T>::nodo n, Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + countAbinNodesRecursive(A.hijoIzqdo(n), A) 
        + countAbinNodesRecursive(A.hijoDrcho(n), A);
}

int main(int argc, char const *argv[])
{
    Abin<int> A;

    rellenarAbin(A, -1);
    imprimirAbin(A);

    cout << "The tree has " << countAbinNodes(A)
    << " nodes" << endl;

    return 0;
}
