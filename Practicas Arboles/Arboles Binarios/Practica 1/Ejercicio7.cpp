#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
bool pseudocompleteNode(Abin<T> A, typename Abin<T>::nodo n)
{
    return (A.hijoIzqdoB(n) == Abin<T>::NODO_NULO && A.hijoDrchoB(n) == Abin<T>::NODO_NULO) ||
    (A.hijoIzqdoB(n) != Abin<T>::NODO_NULO && A.hijoDrchoB(n) != Abin<T>::NODO_NULO);
}

template <typename T>
bool pseudocompleteRec(Abin<T> A, typename Abin<T>::nodo n)
{
    if(A.altura(n) <= 2)
        return pseudocompleteNode(A, A.hijoIzqdoB(n)) && 
        pseudocompleteNode(A, A.hijoDrchoB(n));
    else if(A.altura(A.hijoIzqdoB(n)) > A.altura(A.hijoDrchoB(n)))
        return pseudocompleteRec(A, A.hijoIzqdoB(n));
    else if (A.altura(A.hijoDrchoB(n)) > A.altura(A.hijoIzqdoB(n)))
        return pseudocompleteRec(A, A.hijoDrchoB(n));
    else
        return pseudocompleteRec(A, A.hijoIzqdoB(n)) && 
        pseudocompleteRec(A, A.hijoDrchoB(n));
}

template <typename T>
bool pseudocomplete(Abin<T> A)
{
    bool pseudocomplete = true;
    if(!A.arbolVacioB())
    {
        typename Abin<T>::nodo root = A.raizB();

        if((A.hijoIzqdoB(root) != Abin<T>::NODO_NULO && 
        A.hijoDrchoB(root) != Abin<T>::NODO_NULO) || 
        (A.hijoIzqdoB(root) == Abin<T>::NODO_NULO && 
        A.hijoDrchoB(root) == Abin<T>::NODO_NULO))
            pseudocomplete = pseudocompleteRec(A, root);
        else
            pseudocomplete = false;
    }
    else
        pseudocomplete = true;

    return pseudocomplete;
}

int main(int argc, char const *argv[])
{
    Abin<int> A;
    int fin = -1;

    rellenarAbin(A, fin);

    if(pseudocomplete(A))
        cout << "The tree is pseudocomplete" << endl;
    else
        cout << "The tree isn't pseudocomplete" << endl;

    return 0;
}
