#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
int AbinHeightRec(Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + max(AbinHeightRec(A, A.hijoIzqdo(n)), 
        AbinHeightRec(A, A.hijoDrcho(n)));
}

template <typename T>
int AbinHeight(Abin<T>& A)
{
    return AbinHeightRec(A, A.raiz());
}



int main(int argc, char const *argv[])
{
    Abin<int> A;
    ifstream file("abin.dat");

    rellenarAbin(file, A);
    file.close();

    imprimirAbin(A);

    cout << "The height of the tree is: " << 
    AbinHeight(A) << endl;

    return 0;
}
