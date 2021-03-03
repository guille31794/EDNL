#include <fstream>
#include <iostream>
#include <algorithm>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

uint_fast8_t treeDepth(Abin<uint_fast8_t>& T, Abin<uint_fast8_t>::nodo n)
{
    if(Abin<uint_fast8_t>::NODO_NULO == n || T.arbolVacio() || T.raiz() == n)
        return 0;
    else
        return 1 + treeDepthRec(T, T.padre(n));
}

uint_fast8_t treeDepthRec(Abin<uint_fast8_t>& T, Abin<uint_fast8_t>::nodo n)
{
    if(T.raiz() == n)
        return 0;
    else
        return 1 + treeDepthRec(T, T.padre(n));
}

int main(int argc, char const *argv[])
{
    Abin<uint_fast8_t> T;
    ifstream ef("abin.dat");
    rellenarAbin(ef, T);
    ef.close();

    imprimirAbin(T);
    Abin<uint_fast8_t>::nodo n = T.raiz();

    cout << "Nodes number is: " << treeDepth(T, n) << endl;

    return 0;
}