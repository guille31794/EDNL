#include "iostream"
#include "fstream"
#include "../agen.h"
#include "../agen_E-S.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Agen<int> T;
    rellenarAgen(T, -1);

    ofstream of("agen.dat");
    imprimirAgen(of, T, -1);
    of.close();

    return 0;
}
