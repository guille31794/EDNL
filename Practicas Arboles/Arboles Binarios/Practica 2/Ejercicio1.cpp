#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
bool simRec(Abin<T> A1, Abin<T> A2, typename Abin<T>::nodo nA1, typename Abin<T>::nodo nA2)
{
     if (nA1 != Abin<T>::NODO_NULO && nA2 != Abin<T>::NODO_NULO) 
     {
        bool simIzq = simRec(A1, A2, A1.hijoIzqdoB(nA1), A2.hijoIzqdo(nA2));
        bool simDer = simRec(A1, A2, A1.hijoDrcho(nA1), A2.hijoDrchoB(nA2));
        return simIzq && simDer;          
     }
     else
         return (nA1 == Abin<T>::NODO_NULO && nA2 == Abin<T>::NODO_NULO);
}

template <typename T>
bool similar(Abin<T> A1, Abin<T> A2)
{
    if(A1.arbolVacioB() && A2.arbolVacioB())
        return true;
    else 
        return simRec(A1, A2, A1.raizB(), A2.raizB());
}

int main()
{
    return 0;
}