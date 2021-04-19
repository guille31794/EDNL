#include "Ejercicio1.hpp"
#include "abb_ES.h"
#include <vector>

using namespace std;

template<typename T>
Abb<T> equilibrar(Abb<T>& A);

template<typename T>
void recorridoInorden(const Abb<T>& A, vector<T> &lista);

template <typename T>
void equilibradoRec(Abb<T>& A, vector<T> &lista, int I, int D);

int main(int argc, char const *argv[])
{
    Abb<int> A, AEquilibrado;
    int fin{-1};
    ifstream fe("ej3.dat");

    rellenarAbb(A, fe, fin);
    fe.close();

    imprimirAbb(A);
    AEquilibrado = equilibrar(A);

    cout << "El nuevo arbol es: \n";
    imprimirAbb(AEquilibrado);

    fe.open("ej2.dat");

    rellenarAbb(A, fe, fin);
    fe.close();

    imprimirAbb(A);
    AEquilibrado = equilibrar(A);

    cout << "El nuevo arbol es: \n";
    imprimirAbb(AEquilibrado);

    return 0;
}

template <typename T>
Abb<T> equilibrar(Abb<T>& A)
{
    assert(!A.vacio());

    Abb<T> AEquilibrado;
    vector<T> lista;
    int I, D, M;

    recorridoInorden(A, lista);

    I = 0;
    D = lista.size() - 1;

    if(D % 2 == 0)
        M = (D - I) / 2;
    else
        M = (D - I) / 2 + 1;

    AEquilibrado.insertar(lista.at(M));
    equilibradoRec(AEquilibrado, lista, I, M - 1);
    equilibradoRec(AEquilibrado, lista, M + 1, D);

    return AEquilibrado;
}

template <typename T>
void recorridoInorden(const Abb<T> &A, vector<T> &lista)
{
    if (!A.vacio())
    {
        recorridoInorden(A.izqdo(), lista);
        lista.push_back(A.elemento());
        recorridoInorden(A.drcho(), lista);
    }
}

template <typename T>
void equilibradoRec(Abb<T>& A, vector<T> &lista, int I, int D)
{
    int M = (D - I) / 2 + I;

    if ((D - I) % 2 != 0)
        ++M;

    if (I <= M && M <= D)
    {
        A.insertar(lista.at(M));

        equilibradoRec(A, lista, I, M - 1);
        equilibradoRec(A, lista, M + 1, D);
    }
}