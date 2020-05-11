#include <iostream>
#include <fstream>
#include "Agen_lis.h"
#include "agen_E-S.h"

using namespace std;

int NumHijos(const Agen<int>::nodo& n, const Agen<char>& A)
{
    Agen<int>::nodo hijo;
    int numhijos;

	if(n == Agen<int>::NODO_NULO)
		return(0);
	else
	{
        numhijos = 0;
        hijo = A.hijoIzqdo(n);

		while(hijo != Agen<int>::NODO_NULO)
		{
			numhijos++;
			hijo= A.hermDrcho(hijo);
		}

		return(numhijos);
	}
}

bool ternario_recur(const Agen<int>::nodo& n, const Agen<char>& A)
{
    int nHijos;
    Agen<int>::nodo hijo{};
    bool ternario;

    nHijos = NumHijos(n, A);
    if(nHijos == 0)
        return(true);
    else 
    {
        if (nHijos !=3)
            return(false);
        else
        {
            ternario=true;
            hijo = A.hijoIzqdo(n);

            while(ternario && hijo!=Agen<int>::NODO_NULO)
            {
                ternario = ternario & ternario_recur(hijo, A);
                hijo=A.hermDrcho(hijo);
            }
            
            return(ternario);
        }
    }
}   

bool ternario(const Agen<char>& A)
{
    if (A.arbolVacio())
        return(true);
    else
        return(ternario_recur(A.raiz(), A));
}

int main()
{
    Agen<char> A(16);

    ifstream fe("agen.dat"); // Abrir fichero de entrada.
    rellenarAgen(fe, A); // Desde fichero.
    fe.close();

    if(ternario(A))
        cout<< "Es ternario"<<endl;
    else 
        cout<< "No es ternario"<<endl;

    imprimirAgen(A);

    return(0);
}