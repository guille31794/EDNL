#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
bool AbinPseudoCompleteRec
(Abin<T>& A, typename Abin<T>::nodo n)
{
    if(A.hijoIzqdoB(n) != Abin<T>::NODO_NULO
    && A.hijoDrchoB(n) != Abin<T>::NODO_NULO)
        return AbinPseudoCompleteRec(A, A.hijoDrchoB(n)) &&
        AbinPseudoCompleteRec(A, A.hijoIzqdoB(n));
    else if (A.hijoDrchoB(n) == Abin<T>::NODO_NULO
    && A.hijoIzqdoB(n) == Abin<T>::NODO_NULO)
        return true;
    else
        return false;
}

template <typename T>
bool AbinPseudoComplete(Abin<T>& A)
{
    assert(!A.arbolVacioB());
    return AbinPseudoCompleteRec(A, A.raizB());
}

int main(int argc, char const *argv[])
{
    Abin<int> A;
    ifstream f("abin.dat");

    //rellenarAbin(f,A);
    rellenarAbin(A,-1);

    cout << "The tree is pseudocomplete: " << 
    boolalpha << AbinPseudoComplete(A) << endl;

    return 0;
}
