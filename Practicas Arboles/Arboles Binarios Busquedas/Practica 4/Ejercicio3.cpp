#include "Ejercicio1.hpp"
#include "abb_ES.h"

using namespace std;

template <typename T>
Abb<T> unionAbb(Abb<T>& A, Abb<T>& B)
{
    if(A.vacio())
        return B;
    else if(B.vacio())
        return A;

}

int main(int argc, char const *argv[])
{
    Abb<int> A, B, unido;
    int fin{-1};
    ifstream fe("ej2.dat");

    rellenarAbb(A, fe, fin);
    fe.close();

    fe.open("ej3.dat");
    rellenarAbb(B, fe, fin);
    fe.close();

    imprimirAbb(A);
    imprimirAbb(B);
    unido = unionAbb(A, B);

    cout << "El nuevo arbol es: \n";
    imprimirAbb(unido);

    return 0;
}