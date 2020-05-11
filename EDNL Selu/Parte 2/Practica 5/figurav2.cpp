#include <cmath>
#include <cassert>
#include "Agen.h"
#include "agen_E-S.h"

struct Coordenada
{
    int fila,columna;
};

enum Color{Blanco, Negro, Indefinido};

int AlturaAgen_rec(const Agen<Color>::nodo& n, const Agen<Color>& A)
{
    int AlturaMax;
    Agen<Color>::nodo hijo;

    if(n == Agen<Color>::NODO_NULO)   //Si árbol vacío->Altura=-1, si un único nodo, Altura=0
        return(-1);
    else
    {
        AlturaMax = 0;
        hijo = A.hijoIzqdo(n);
		while(hijo != Agen<Color>::NODO_NULO)
		{
			AlturaMax = std::max(AlturaMax, AlturaAgen_rec(hijo, A));
			hijo = A.hermDrcho(hijo);
		}
		return(1 + AlturaMax);
    } 
}

int AlturaAgen(const Agen<Color>& A)
{
    return(AlturaAgen_rec(A.raiz(), A));
}

void Rellenar_matriz(Color C, size_t dim, Coordenada sup_izq, Coordenada inf_der, Color* fig)
{
    int i, j;

    i=sup_izq.fila;
    j=sup_izq.columna;
    while(i<= inf_der.fila)
    {
        while(j<= inf_der.columna)
        {
            *(fig + i * dim + j) = C;
            j++;
        }
        i++;    
    }
}

void Figura_Asociada_recur(const Agen<Color>::nodo& n, const Agen<Color>& A, Color* fig, size_t dim, Coordenada sup_izq , Coordenada inf_der)
{
    Agen<Color>::nodo evaluado;
    Coordenada a, b;

    if(A.elemento(n)==Blanco || A.elemento(n)==Negro)
    {
        Rellenar_matriz(A.elemento(n), dim, sup_izq, inf_der, fig);
    }
    else
    {
        //Primer Cuadrante
        a = sup_izq;
        b.fila = (sup_izq.fila + inf_der.fila)/2; 
        b.columna = (sup_izq.columna + inf_der.columna )/2;  //Es división entera, si inf_der columna es 7, da 3,5, cuyo entero es 3 y así con todos los inf_der que también serán impares
        Figura_Asociada_recur(A.hijoIzqdo(n), A, fig, dim, a, b); //Llamada al primer hijo

        //Segundo Cuadrante
        a.fila = sup_izq.fila;
        a.columna = (sup_izq.columna + inf_der.columna )/2 + 1;
        b.fila = (sup_izq.fila + inf_der.fila)/2;
        b.columna = inf_der.columna;
        Figura_Asociada_recur(A.hermDrcho(A.hijoIzqdo(n)), A, fig, dim, a, b); //Llamada al segundo hijo

        //Tercer Cuadrante
        a.fila = (sup_izq.fila + inf_der.fila)/2 + 1;
        a.columna = (sup_izq.columna + inf_der.columna )/2 + 1;
        b.fila = inf_der.fila;
        b.columna = inf_der.columna;
        Figura_Asociada_recur(A.hermDrcho(A.hermDrcho(A.hijoIzqdo(n))), A, fig, dim, a, b); //Llamada al tercer hijo

        //Cuarto Cuadrante
        a.fila = (sup_izq.fila + inf_der.fila)/2 + 1;
        a.columna = sup_izq.columna;
        b.fila = inf_der.fila;
        b.columna = (sup_izq.columna + inf_der.columna )/2;
        Figura_Asociada_recur(A.hermDrcho(A.hermDrcho(A.hermDrcho(A.hijoIzqdo(n)))), A, fig, dim, a, b); //Llamada al cuarto hijo
    }
}

void FiguraAsociada(const Agen<Color>& A, Color* fig, size_t dim)
{
    Coordenada sup_izq{0,0};
    Coordenada inf_der{dim-1, dim-1};

    Figura_Asociada_recur(A.raiz(), A, fig, dim, sup_izq, inf_der);
}

int main()
{
    Agen<Color> A;
    LeerArbolColor(A); //Función no implementada
    assert(!A.arbolVacio()); //Precondición: el árbol no está vacío
    const size_t dim = pow(2, AlturaAgen(A));// dimensión de la figura, se calcula según la altura del árbol A.
    Color Figura[dim][dim]; // Figura es de tipo Color (*)[dim], o sea, puntero a vector de dim elementos de tipo Color.
    FiguraAsociada(A, *Figura, dim); // *Figura es de tipo vector de dim elementos Color, o sea, puntero a Color o Color*
    // se puede utilizar la matriz Figura mediante índices, por ejemplo Figura[5][8]
}

