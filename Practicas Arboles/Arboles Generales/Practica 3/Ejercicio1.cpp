#include "../agen.h"
#include "../agen_E-S.h"

template <typename T>
int degreeRec(Agen<T>& A, typename Agen<T>::nodo n)
{
    int max = 0;

    if(n != Agen<T>::NODO_NULO)
    {
        typename Agen<T>::nodo hIzq = n;
        
        while(hIzq != Agen<T>::NODO_NULO)
        {
            ++max;
            hIzq = A.hermDrcho(hIzq);
        }
        
        if(A.hermDrcho(n) != Agen<T>::NODO_NULO)
            max = std::max(max, std::max(degreeRec(A, A.hijoIzqdo(n)), degreeRec(A, A.hijoIzqdo(A.hermDrcho(n)))));
        else
            max = std::max(max, degreeRec(A, A.hijoIzqdo(n)));
    }

    return max;
}

template <typename T>
int degree(Agen<T>& A)
{
    int max = 0;

    if (!A.arbolVacio())
        max = degreeRec(A, A.raiz());
    
    return max;
}

int main(int argc, char const *argv[])
{
    Agen<int> T;
    int fin = -1;

    rellenarAgen(T, fin);

    cout << "Tree degree is: " << degree(T) << endl;

    return 0;
}
