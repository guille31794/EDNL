#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
int depth(Abin<T> A, typename Abin<T>::nodo n)
{
    int depth = 0;

    while(A.padreB(n) != Abin<T>::NODO_NULO)
    {
        ++depth;
        n = A.padreB(n);
    }

    return depth;
}

int main(int argc, char const *argv[])
{
    int fin = -1;
    Abin<int> A;
    rellenarAbin(A, fin);

    cout << "Root node depth is: " << depth(A, A.raizB()) << endl;

    Abin<int>::nodo n = A.raizB();
    
    while(A.hijoIzqdoB(n) != Abin<int>::NODO_NULO)
      n = A.hijoIzqdoB(n); 
    
    cout << "Left branch depth is: " << depth(A, n) << endl;

    return 0;
}
