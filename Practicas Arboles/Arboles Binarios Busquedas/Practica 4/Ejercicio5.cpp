#include "Ejercicio1.hpp"
#include "abb_ES.h"
#include <vector>

using namespace std;

template <typename T>
using Conjunto = Abb<T>;

template <typename T>
Conjunto<T> operator *(Conjunto<T>& A, Conjunto<T>& B);

template <typename T>
Conjunto<T> operator -(Conjunto<T> &A, Conjunto<T> &B);

template <typename T>
void diferenciaAbb(Conjunto<T> &A, const Conjunto<T> &B);

template <typename T>
bool pertenece(const T &e, Abb<T> &A);

template <typename T>
Abb<T> interseccionAbb(Abb<T> &A, Abb<T> &B);

template <typename T>
void intersecarRec(Abb<T> &I, const Abb<T> &A, Abb<T> &B);

template <typename T>
Abb<T> unionAbb(Abb<T> &A, Abb<T> &B);

template <typename T>
Abb<T> equilibrar(Abb<T> &A);

template <typename T>
void recorridoInorden(const Abb<T> &A, vector<T> &vector);

template <typename T>
void equilibradoRec(Abb<T> &A, vector<T> &lista, int I, int D);

template <typename T>
Abb<T> operator+(Abb<T> &A, Abb<T> &B);

template <typename T>
void suma(Abb<T> &A, const Abb<T> &B);

int main(int argc, char const *argv[])
{
    Abb<int> A, B, P;
    int fin{-1};
    ifstream fe("ej2.dat");

    rellenarAbb(A, fe, fin);
    fe.close();

    fe.open("ej3.dat");
    rellenarAbb(B, fe, fin);
    fe.close();

    imprimirAbb(A);
    imprimirAbb(B);
    P = A*B;

    cout << "El nuevo arbol es: \n";
    imprimirAbb(P);

    return 0;
}

template <typename T>
Conjunto<T> operator *(Conjunto<T> &A, Conjunto<T> &B)
{
    Conjunto<T> I(interseccionAbb(A, B)),
    U(unionAbb(A,B)), P(U-I);    
    
    return P;
}

template <typename T>
Conjunto<T> operator -(Conjunto<T> &A, Conjunto<T> &B)
{
    Conjunto<T> D(A);

    diferenciaAbb(D, B);

    return D;
}

template <typename T>
void diferenciaAbb(Conjunto<T> &A, const Conjunto<T>& B)
{
    if (!B.vacio())
    {
        if (pertenece(B.elemento(), A))
            A.eliminar(B.elemento());
        
        diferenciaAbb(A, B.izqdo());
        diferenciaAbb(A, B.drcho());
    }
}

template <typename T>
bool pertenece(const T &e, Abb<T> &A)
{
    if (A.buscar(e).vacio())
        return false;
    else
        return true;
}

template <typename T>
Abb<T> interseccionAbb(Abb<T> &A, Abb<T> &B)
{
    Abb<T> I;

    intersecarRec(I, A, B);

    return I;
}

template <typename T>
void intersecarRec(Abb<T> &I, const Abb<T> &A, Abb<T> &B)
{
    if (!A.vacio())
    {
        if (!(B.buscar(A.elemento())).vacio())
            I.insertar(A.elemento());

        intersecarRec(I, A.izqdo(), B);
        intersecarRec(I, A.drcho(), B);
    }
}

template <typename T>
Abb<T> unionAbb(Abb<T> &A, Abb<T> &B)
{
    Abb<T> U(A + B);

    U = equilibrar(U);

    return U;
}

template <typename T>
Abb<T> equilibrar(Abb<T> &A)
{
    assert(!A.vacio());

    Abb<T> AEquilibrado;
    vector<T> lista;
    int I, D, M;

    recorridoInorden(A, lista);

    I = 0;
    D = lista.size() - 1;

    if (D % 2 == 0)
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
void equilibradoRec(Abb<T> &A, vector<T> &lista, int I, int D)
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

template <typename T>
Abb<T> operator+(Abb<T> &A, Abb<T> &B)
{
    Abb<T> S(A);

    suma(S, B);

    return S;
}

template <typename T>
void suma(Abb<T> &A, const Abb<T> &B)
{
    if (!B.vacio())
    {
        A.insertar(B.elemento());
        suma(A, B.izqdo());
        suma(A, B.drcho());
    }
}