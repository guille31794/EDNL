/*
Se resolverá el siguiente problema utilizando un subconjunto de las operaciones del TAD Abin
representado mediante listas enlazadas y específicas para valores enteros

Definición de los prototípos de las operaciones a emplear del tad y los tipos de datos

Abin<int>();
Abin<int> Abin<int>(const Abin<int>&);
typedef struct nodo;
.
Las que necesites realmente, yo hay algunas como eliminar que no las he puesto por lo obvio, no las voy a usar
.
.
.

Prototipo: uint AbinEsAbb(const Abin<int>&);
Precondición: Recibe un arbol binario.
Postcondición: Devuelve 0 si el arbol binario no tiene estructura de ABB, o 1 en caso contrario.
               En caso de que el arbol se encuentre vacío, se considerará que este es ABB hasta poder demostrar lo contrario.
*/

uint AbinEsAbb(const Abin<int>& A)
{
    if(A.vacio())
    {
        return 1;
    }
    else
    {
        return AbinEsAbbRec(A, A.hijoIzq(A.raiz()), A.hijoDer(A.raiz()));
    }
}

/*
* Protitpo: uint AbinEsAbbRec(const Abin<int>&, const Abin<int>::nodo&, const Abin<int>::nodo&);
* Precondición: Recibe un arbol binario no vacío y dos nodos desde los que comenzar la busqueda.
* Postcondición: Devuelve 0 si el arbol binario no tiene estructura de ABB, o 1 en caso contrario.
*/

uint AbinEsAbbRec(const Abin<int>& A, const Abin<int>::nodo& nI, const Abin<int>::nodo& nD)
{
    if(Abin<int>::nodo::NODO_NULO != nI && Abin<int>::nodo::NODO_NULO != nD)
    {
        if(A.elemento(nI) < A.elemento(nD))
        {
            return AbinEsAbbRec(A, A.hijoIzq(nI), A.hijoDer(nI)) && AbinEsAbbRec(A, A.hijoIzq(nD), A.hijoDer(nD));
        }
        else
        {
            return 0;
        }
    }
    else if(Abin<int>::nodo::NODO_NULO == nI && Abin<int>::nodo::NODO_NULO == nD)
    {
        return 1;
    }
    else if(Abin<int>::nodo::NODO_NULO == nI)
    {
        if(A.elemento(A.padre(nD)) < A.elemento(nD))
        {
            return AbinEsAbbRec(A, A.hijoIzq(nD), A.hijoDer(nD));
        }
        else
        {
            return 0;
        }
    }
    else if(Abin<int>::nodo::NODO_NULO == nD)
    {
        if(A.elemento(A.padre(nI)) > A.elemento(nI))
        {
            return AbinEsAbbRec(A, A.hijoIzq(nI), A.hijoDer(nI));
        }
        else
        {
            return 0;
        }
    }
}