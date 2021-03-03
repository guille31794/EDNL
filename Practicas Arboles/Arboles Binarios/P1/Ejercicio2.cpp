#include <fstream>
#include <iostream>
#include <algorithm>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

uint_fast8_t treeHeight(Abin<uint_fast8_t>& T)
{
    if(T.arbolVacio())
        return 0;
    else
        return 1 + max(treeHeightRec(T, T.hijoIzqdo(T.raiz())), treeHeightRec(T, T.hijoDrcho(T.raiz())));
}

uint_fast8_t treeHeightRec(Abin<uint_fast8_t>& T, Abin<uint_fast8_t>::nodo n)
{
    if(Abin<uint_fast8_t>::NODO_NULO == n)
        return 0;
    else
        return 1 + max(treeHeightRec(T, T.hijoIzqdo(T.raiz())), treeHeightRec(T, T.hijoDrcho(T.raiz())));
}

int main(int argc, char const *argv[])
{
    Abin<uint_fast8_t> T;
    ifstream ef("abin.dat");
    rellenarAbin(ef, T);
    ef.close();

    imprimirAbin(T);
    cout << "Nodes number is: " << treeHeight(T) << endl;

    return 0;
}