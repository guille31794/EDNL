#include "Ejercicio1.hpp"
#include "abb_ES.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Abb<int> A;
    ifstream fe("abb.dat");

    rellenarAbb(A, fe);
    fe.close();

    imprimirAbb(A);
    A.equilibrar();

    cout << "El nuevo arbol es: ";
    imprimirAbb(A);

    return 0;
}