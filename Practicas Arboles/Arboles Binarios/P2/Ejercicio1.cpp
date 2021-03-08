#include <fstream>
#include <iostream>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

template<typename T>
bool similarTrees(Abin<T>& A1, Abin<T>& A2)
{
    return A1.arbolVacio() && A2.arbolVacio() ? true : similarTrees(A1, A1.raiz(), A2, A2.raiz());
}

template<typename T>
bool similarTrees(Abin<T>& A1, typename Abin<T>::nodo n1, Abin<T>& A2, typename Abin<T>::nodo n2)
{
    if(Abin<T>::NODO_NULO == n1 && Abin<T>::NODO_NULO == n2)
        return true;
    else if(Abin<T>::NODO_NULO != n1 && Abin<T>::NODO_NULO != n2)
        return similarTrees(A1, A1.hijoIzqdo(n1), A2, A2.hijoIzqdo(n2)) && similarTrees(A1, A1.hijoDrcho(n1), A2, A2.hijoDrcho(n2));
    else
        return false;
}

int main(int argc, char const *argv[])
{
    ifstream ef("abin.dat");
    Abin<int> T1, T2, T3;
    rellenarAbin(ef, T1);
    ef.close();
    ef = ifstream("abin.dat");
    rellenarAbin(ef, T2);
    ef.close();

    imprimirAbin(T1);
    imprimirAbin(T2);

    cout << "The trees T1 & T2 are";
    similarTrees(T1, T2) ? cout << " similar" : cout << "n't similar\n";
    cout << "The trees T1 & T3 are";
    similarTrees(T1, T2) ? cout << " similar" : cout << "n't similar";
    cout << endl;

    return 0;
}
