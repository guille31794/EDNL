#include <fstream>
#include <iostream>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

uint_fast8_t nodeCounter(Abin<uint_fast8_t>& T)
{
    if (T.arbolVacio())
        return 0;
    else
        return 1 + nodeCounterRec(T, T.hijoIzqdo(T.raiz())) + nodeCounterRec(T, T.hijoDrcho(T.raiz()));
}

uint_fast8_t nodeCounterRec(Abin<uint_fast8_t>& T, Abin<uint_fast8_t>::nodo n)
{
    if(Abin<uint_fast8_t>::NODO_NULO == n)
        return 0;
    else
        return 1 + nodeCounterRec(T, T.hijoIzqdo(n)) + nodeCounterRec(T, T.hijoDrcho(n));
}

int main(int argc, char const *argv[])
{
    Abin<uint_fast8_t> T;
    ifstream ef("abin.dat");
    rellenarAbin(ef, T);
    ef.close();

    imprimirAbin(T);
    cout << "Nodes number is: " << nodeCounter(T) << endl;

    return 0;
}
