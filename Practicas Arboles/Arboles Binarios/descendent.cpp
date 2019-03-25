/*
    Crea un subprograma que reciba un arbol bianrio de cualquier
    tipo y elimine la descendencia de los nodos que tengan 1 solo
    hijo
*/

#include "abin.h"
#include "abin_E-S.h"

template <typename T>
void deleteSons(Abin<T> &A, typename Abin<T>::nodo n)
{
    if (n != Abin<T>::NODO_NULO)
    {
        deleteSons(A,A.hijoIzqdoB(n));
        deleteSons(A,A.hijoDrchoB(n));
        
        if(A.hijoIzqdoB(n) != Abin<T>::NODO_NULO)
            A.eliminarHijoIzqdoB(n);

        if(A.hijoDrchoB(n) != Abin<T>::NODO_NULO)
            A.eliminarHijoDrchoB(n);
    }
}

/*template <typename T>
void deleteSons(Abin<T> A, typename Abin<T>::nodo n)
{
    if(A.hijoIzqdoB(n) != Abin<T>::NODO_NULO)
        if (A.hijoIzqdoB(A.hijoIzqdoB(n)) == Abin<T>::NODO_NULO
        && A.hijoDrchoB(A.hijoIzqdoB(n)) == Abin<T>::NODO_NULO) 
            A.eliminarHijoIzqdoB(n);
    else
    {
        deleteSons(A, A.hijoIzqdoB(n));
        deleteSons(A, n);
    }

    if (A.hijoDrchoB(n) != Abin<T>::NODO_NULO) 
        if (A.hijoIzqdoB(A.hijoDrchoB(n)) == Abin<T>::NODO_NULO
        && A.hijoDrchoB(A.hijoDrchoB(n)) == Abin<T>::NODO_NULO)
            A.eliminarHijoDrchoB(n);
    else
    {
        deleteSons(A, A.hijoDrchoB(n));
        deleteSons(A, n);
    }   
}*/

template <typename T>
void transformRec(Abin<T>& A, typename Abin<T>::nodo n)
{
    if (A.hijoIzqdoB(n) != Abin<T>::NODO_NULO && 
    A.hijoDrchoB(n) != Abin<T>::NODO_NULO)
    {
        transformRec(A, A.hijoIzqdoB(n));
        transformRec(A, A.hijoDrchoB(n));
    }
    else if (A.hijoIzqdoB(n) != Abin<T>::NODO_NULO ||
    A.hijoDrchoB(n) != Abin<T>::NODO_NULO) 
        deleteSons(A, n);
}

template <typename T>
void transform(Abin<T>& A)
{
    if(!A.arbolVacioB())
        transformRec(A, A.raizB());
}

int main(int argc, char const *argv[])
{
    Abin<int> T;
    int fin = -1;

    rellenarAbin(T, fin);
    imprimirAbin(T);

    transform(T);

    cout << "New tree: " << endl;
    imprimirAbin(T);

    return 0;
}
