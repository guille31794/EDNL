#ifndef ABIN_H
#define ABIN_H

#include <cassert>

template<typename T> class Abin
{
    struct celda; //declaracion adelantada privada
    
public:
    typedef celda* nodo;
    static const nodo NODO_NULO;
    Abin(); //constructor
    ~Abin(); //destructor
    void insertarRaizB(const T& e);
    void insertarHijoIzqdoB(nodo n, const T& e);
    void insertarHijoDrchoB(nodo n, const T& e);
    void eliminarHijoIzqdoB(nodo n);
    void eliminarHijoDrchoB(nodo n);
    void eliminarRaizB();
    bool arbolVacioB() const;
    const T& elemento(nodo n) const; //acceso a elto, lectura
    T& elemento(nodo n); //acceso a elto, lectura/escritura
    nodo raizB() const;
    nodo padreB(nodo n) const;
    nodo hijoIzqdoB(nodo n) const;
    nodo hijoDrchoB(nodo n) const;
    Abin(const Abin<T>& a); //ctor. de copia
    Abin<T>& operator =(const Abin<T>& a); //Asignacion de arboles
private:
    struct celda
    {
        T elto;
        nodo padre, hizq, hder;
        celda(const T& e, nodo p = NODO_NULO): elto(e),
        padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
    };
    nodo r; //nodo raiz del arbol

    void destruirNodos(nodo& n);
    nodo copiar(nodo n);
};

/* Definicion del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(0);

template <typename T>
inline Abin<T>::Abin(): r(NODO_NULO){}

template <typename T>
inline void Abin<T>::insertarRaizB(const T& e)
{
    assert(r == NODO_NULO); //arbol vacio
    r = new celda(e);
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n -> hizq == NODO_NULO); //no existe hijo
    n -> hizq = new celda(e, n);
}

template <typename T> inline
void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n -> hder == NODO_NULO); //no existe hijo
    n -> hder = new celda(e, n);
}

template <typename T>
inline void Abin<T>::eliminarHijoIzqdoB(Abin<T>::nodo n)
{
    assert(n != NODO_NULO);
    assert(n -> hizq != NODO_NULO); //existe hijo izqdo.
    //hijo izqdo es hoja
    assert(n -> hizq == NODO_NULO && n -> hizq -> hder == NODO_NULO);
    delete(n -> hizq);
    n -> hizq = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarHijoDrchoB(Abin<T>::nodo n)
{
    assert(n != NODO_NULO); //arbol no vacio
    assert(n->hder != NODO_NULO); //existe hijo drcho.
    //hijo drcho. es hoja
    assert(n->hder->hizq == NODO_NULO && n ->hder->hder == NODO_NULO);
    delete(n->hder);
    n->hder = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarRaizB()
{
    assert(r != NODO_NULO); //arbol no vacio
    //la raiz es hoja
    assert(r->hizq == NODO_NULO && r->hder == NODO_NULO);
    delete(r);
    r = NODO_NULO;
}

template <typename T> inline Abin<T>::~Abin()
{ destruirNodos(r);}

#endif