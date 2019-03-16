#include "../abin.h"
#include "../abin_E-S.h"

int max(int a, int b)
{
    if(a >= b)
        return a;
    else
        return b;
}

template <typename T>
int heightRec(Abin<T> A, typename Abin<T>::nodo n)
{
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else 
        return 1 + max(heightRec(A, A.hijoIzqdoB(n)), heightRec(A, A.hijoDrchoB(n)));
}

template <typename T>
int height(Abin<T> A)
{
    if(A.arbolVacioB())
        return 0;
    else
        return heightRec(A, A.raizB())-1;
}

int main(int argc, char const *argv[])
{
    Abin<int> A;
    int fin = -1;
    
    rellenarAbin(A, fin);
    imprimirAbin(A);

    cout << "Tree height is: " << height(A) << endl;

    return 0;
}