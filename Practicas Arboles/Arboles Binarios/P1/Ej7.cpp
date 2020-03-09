#include "../abin.h"
#include "../abin_E-S.h"

/*
    Si la altura del h.Izq > h.Der
        pseudocompleto del izquierdo
    sino si la altura del h.Der > h.Izq
        pseudocompleto del derecho
    sino

*/

template <typename T>
bool AbinPseudoCompleteRec
(Abin<T>& A, typename Abin<T>::nodo n)
{
    if(A.altura(A.hijoIzqdo(n)) > A.altura(A.hijoDrcho(n)))
        return AbinPseudoCompleteRec(A, A.hijoIzqdo(A));
    else if(A.altura(A.hijoDrcho(n)) > A.altura(A.hijoIzqdo(n)))
        return AbinPseudoCompleteRec(A, A.hijoDrcho(n));
    else
        return AbinPseudoCompleteRec(A, A.hijoIzqdo(n)) && 
        AbinPseudoCompleteRec(A, A.hijoDrcho(n));
}

template <typename T>
bool AbinPseudoComplete(Abin<T>& A)
{
    //assert(!A.arbolVacioB());
    if(A.arbolVacio())
        return true;
    else
        return AbinPseudoCompleteRec(A, A.raiz());
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
