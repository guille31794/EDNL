#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
bool simRec(Abin<T> A1, Abin<T> A2, typename Abin<T>::nodo nA1, typename Abin<T>::nodo nA2)
{
     if (nA1 != Abin<T>::NODO_NULO && nA2 != Abin<T>::NODO_NULO) 
     {
        bool simIzq = simRec(A1, A2, A1.hijoIzqdoB(nA1), A2.hijoIzqdoB(nA2));
        bool simDer = simRec(A1, A2, A1.hijoDrchoB(nA1), A2.hijoDrchoB(nA2));
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
    Abin<int> A1, A2;
    int fin = -1;
    
    rellenarAbin(A1, fin);
    imprimirAbin(A1);
    rellenarAbin(A2, fin); 
    imprimirAbin(A2);

    if(similar(A1, A2))
        cout << "The trees are similar";
    else
        cout << "Thre trees arent similar";
    
    cout << endl;

    return 0;
}