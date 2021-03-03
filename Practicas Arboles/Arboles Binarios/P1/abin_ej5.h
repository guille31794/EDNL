#ifndef ABIN_H
#define ABIN_H
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
class Abin
{
    struct celda; // declaración adelantada privada
public:
    typedef celda *nodo;
    static const nodo NODO_NULO;
    Abin(); // constructor
    void insertarRaiz(const T &e);
    void insertarHijoIzqdo(nodo n, const T &e);
    void insertarHijoDrcho(nodo n, const T &e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();
    ~Abin(); // destructor
    bool arbolVacio() const;
    const T &elemento(nodo n) const; // acceso a elto, lectura
    T &elemento(nodo n);             // acceso a elto, lectura/escritura
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    Abin(const Abin<T> &a);               // ctor. de copia
    Abin<T> &operator=(const Abin<T> &a); //asignación de árboles
    uint_fast8_t profundidad(nodo n) const;
    uint_fast8_t altura(nodo n) const;

private:
    uint_fast8_t alturaRec(typename Abin<T>::nodo n) const;
    struct celda
    {
        T elto;
        nodo padre, hizq, hder;
        celda(const T &e, nodo p = NODO_NULO) : elto(e),
                                                padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
    };
    nodo r; // nodo raíz del árbol
    void destruirNodos(nodo &n);
    nodo copiar(nodo n);
};

template <typename T>
inline uint_fast8_t Abin<T>::altura(typename Abin<T>::nodo n) const
{
    if(NODO_NULO == n)
        return -1;
    else
        return max(alturaRec(hijoIzqdo(n)), alturaRec(hijoDrcho(n)));
}

template <typename T>
uint_fast8_t Abin<T>::alturaRec(typename Abin<T>::nodo n) const
{
    if(NODO_NULO == n)
        return 0;
    else
        return 1 + max(alturaRec(hijoIzqdo(n)), alturaRec(hijoDrcho(n)));
}

template <typename T>
uint_fast8_t Abin<T>::profundidad(typename Abin<T>::nodo n) const
{
    if(raiz() == n)
        return 0;
    else
        return 1 + profundidad(padre(n));
}

/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(0);

template <typename T>
inline Abin<T>::Abin() : r(NODO_NULO) {}

template <typename T>
inline void Abin<T>::insertarRaiz(const T &e)
{
    assert(r == NODO_NULO); // árbol vacío
    r = new celda(e);
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(Abin<T>::nodo n,
                                       const T &e)
{
    assert(n != NODO_NULO);
    assert(n->hizq == NODO_NULO); // no existe hijo
    n->hizq = new celda(e, n);
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(Abin<T>::nodo n, const T &e)
{
    assert(n != NODO_NULO);
    assert(n->hder == NODO_NULO); // no existe hijo
    n->hder = new celda(e, n);
}
template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(Abin<T>::nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hizq != NODO_NULO);        // existe hijo izqdo.
    assert(n->hizq->hizq == NODO_NULO && // hijo izqdo.
           n->hizq->hder == NODO_NULO);  // es hoja
    delete (n->hizq);
    n->hizq = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarHijoDrcho(Abin<T>::nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hder != NODO_NULO);        // existe hijo drcho.
    assert(n->hder->hizq == NODO_NULO && // hijo drcho.
           n->hder->hder == NODO_NULO);  // es hoja
    delete (n->hder);
    n->hder = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarRaiz()
{
    assert(r != NODO_NULO); // árbol no vacío
    assert(r->hizq == NODO_NULO &&
           r->hder == NODO_NULO); // la raíz es hoja
    delete (r);
    r = NODO_NULO;
}

template <typename T>
inline Abin<T>::~Abin()
{
    destruirNodos(r); // vacía el árbol
}
template <typename T>
inline bool Abin<T>::arbolVacio() const
{
    return (r == NODO_NULO);
}

template <typename T>
inline const T &Abin<T>::elemento(Abin<T>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename T>
inline T &Abin<T>::elemento(Abin<T>::nodo n)
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{
    return r;
}

template <typename T>
inline
    typename Abin<T>::nodo
    Abin<T>::padre(Abin<T>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->padre;
}

template <typename T>
inline
    typename Abin<T>::nodo
    Abin<T>::hijoIzqdo(Abin<T>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->hizq;
}

template <typename T>
inline
    typename Abin<T>::nodo
    Abin<T>::hijoDrcho(Abin<T>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->hder;
}

template <typename T>
inline Abin<T>::Abin(const Abin<T> &a)
{
    r = copiar(a.r);
}

template <typename T>
Abin<T> &Abin<T>::operator=(const Abin<T> &a)
{
    if (this != &a) // evitar autoasignación
    {
        this->~Abin(); // vaciar el árbol
        r = copiar(a.r);
    }
    return *this;
}

// Métodos privados
// Destruye un nodo y todos sus descendientes
template <typename T>
void Abin<T>::destruirNodos(Abin<T>::nodo &n)
{
    if (n != NODO_NULO)
    {
        destruirNodos(n->hizq);
        destruirNodos(n->hder);
        delete n;
        n = NODO_NULO;
    }
}

// Devuelve una copia de un nodo y todos sus descendientes
template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(Abin<T>::nodo n)
{
    nodo m = NODO_NULO;
    if (n != NODO_NULO)
    {
        m = new celda(n->elto);    // copiar n
        m->hizq = copiar(n->hizq); // copiar subárbol izqdo.

        if (m->hizq != NODO_NULO)
        {
            m->hizq->padre = m;
        }

        m->hder = copiar(n->hder); // copiar subárbol drcho.

        if (m->hder != NODO_NULO)
        {
            m->hder->padre = m;
        }
    }
    return m;
}

#endif // ABIN_H
