#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
bool AbinSimilarRec(Abin<T>& A1, Abin<T>& A2,
typename Abin<T>::nodo n1, typename Abin<T>::nodo n2)
{
    if(n1 != Abin<T>::NODO_NULO 
    && n2 != Abin<T>::NODO_NULO)
        return AbinSimilarRec(A1, A2, A1.hijoIzqdo(n1),
        A2.hijoIzqdo(n2)) && AbinSimilarRec(A1, A2, 
        A1.hijoDrcho(n1), A2.hijoDrcho(n2));
    else if (n1 == Abin<T>::NODO_NULO 
    && n2 == Abin<T>::NODO_NULO)
        return true;
    else
        return false;
}

template <typename T>
bool AbinSimilar(Abin<T>& A1, Abin<T>& A2)
{
    return AbinSimilarRec(A1, A2, A1.raiz(), 
    A2.raiz()); 
}

int main(int argc, char const *argv[])
{
    Abin<int> A1, A2, B1, B2, C1, C2;
    ifstream f("abin,dat");

    rellenarAbin(f, A1);
    rellenarAbin(f, A2);
    rellenarAbin(C1, -1);
    rellenarAbin(C2, -1);

    cout << "similarity of A1 and A2 is " <<
    boolalpha << AbinSimilar(A1, A2) << "\n";

    // Empty trees
    cout << "similarity of B1 and B2 is " <<
    boolalpha << AbinSimilar(B1, B2) << "\n";

    // Manually set trees
    cout << "similarity of C1 and C2 is " <<
    boolalpha << AbinSimilar(C1, C2) << endl;

    return 0;
}
