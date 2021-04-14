#include "Ejercicio2.hpp"
#include "abb_ES.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Abb<int> A;
    int fin{-1};
    ifstream fe("ej2.dat");

    rellenarAbb(A, fe, fin);
    fe.close();

    imprimirAbb(A);
    A.equilibrar();

    cout << "El nuevo arbol es: ";
    imprimirAbb(A);

    return 0;
}