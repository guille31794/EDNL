#include "../agen.h"
#include "../agen_E-S.h"

void prune(Abin<int>& T)
{
    
}

void prune(Abin<int>& T)
{
    if (!T.arbolVacio()) 
        pruneRec(T);
}

int main(int argc, char const *argv[])
{
    Agen<int> T;
    int end = -1;

    rellenarAgen(T, end);
    imprimirAgen(T);
    prune(T, 5);
    imprimirAgen(T);

    return 0;
}
