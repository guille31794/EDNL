#include "../abin.h"
#include "../abin_E-S.h"

 bool simRec(Abin<T> A1, Abin<T> A2), typename Abin<T>::nodo nA1, typename Abin<T>::nodo nA2)
 {
     if(A1.hijoIzqdoB(nA1) == NODO_NULO && A2.hijoIzqdoB(nA2) == NODO_NULO) 
     {
        
     }
     
 }

template <typename T>
bool similar(Abin<T> A1, Abin<T> A2)
{
    if(!A1.arbolVacioB() && !A2.arbolVacioB())
       return simRec(A1, A2, A1.hijoIzqdoB(A.raizB()), A2.hijoIzqdoB(A2.raizB())) &&
        simRec(A1, A2, A1.hijoDrchoB(A1.raizB()), A2.hijoDrchoB(A2.raizB()));
    else if (A1.raizB() == NODO_NULO && A2.raizB() == NODO_NULO) 
        return true;
    else 
        return false;
}