#ifndef Abin_VEC1_H
#define Abin_VEC1_H
#include <cassert>
#include <cmath>
#include <iostream>

template <typename T> class Abin {
    public:
        typedef int nodo; // índice del vector entre 0 y maxNodos-1
        static const nodo NODO_NULO;
        //explicit Abin(size_t maxNodos, const T& e_nulo = T()); //ctor
        explicit Abin(unsigned alturaArbol, const T& e_nulo = T()); //ctor
        void insertarRaizB(const T& e);
        void insertarHijoIzqdoB(nodo n, const T& e);
        void insertarHijoDrchoB(nodo n, const T& e);
        void eliminarHijoIzqdoB(nodo n);
        void eliminarHijoDrchoB(nodo n);
        
        void enseniarVector();
        ~Abin(); // destructor
        
        bool arbolVacioB() const;
        void eliminarRaizB();
        const T& elemento(nodo n) const; // acceso a elto, lectura
        
        T& elemento(nodo n); // acceso a elto, lectura/escritura
        nodo raizB() const;
        nodo padreB(nodo n) const;
        nodo hijoIzqdoB(nodo n) const;
        nodo hijoDrchoB(nodo n) const;
        Abin(const Abin<T>& a); // ctor. de copia
        Abin<T>& operator =(const Abin<T>& a); //asignación de árboles
        
        int profundidad(nodo n) const;
        //int profundidadNodoRec(nodo n, nodo nodo, int inicio, int fin) const;
    private:
        T* nodos; // vector de nodos
        int maxNodos; // tamaño del vector
        T ELTO_NULO; // marca celdas vacías
};

/* Definición del nodo nulo */
template <typename T> const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

template <typename T> Abin<T>::Abin(unsigned alturaArbol, const T& e_nulo) : ELTO_NULO(e_nulo)
{
    maxNodos = pow(2, alturaArbol) - 1;
    nodos = new T[maxNodos];
    
    // marcar todas las celdas libres
    for (nodo n = 0; n <= maxNodos-1; n++)
        nodos[n] = ELTO_NULO;
}

template <typename T> inline void Abin<T>::insertarRaizB(const T& e)
{
    assert(nodos[maxNodos / 2] == ELTO_NULO); // árbol vacío
    nodos[maxNodos / 2] = e;
}

template <typename T> inline int Abin<T>::profundidad(Abin<T>::nodo n) const {
    //return profundidadNodoRec(n, raizB(), 0, maxNodos);
    int profundidad = 0;

    while(n != NODO_NULO)
    {
        ++profundidad;
        n = padreB(n);
    }

    return profundidad;
}

/*template <typename T> inline int Abin<T>::profundidadNodoRec(Abin<T>::nodo n, Abin<T>::nodo nodo, int inicio, int fin) const {
    if(nodo == n)
        return 0;
    else if(nodo > n)
    {
        inicio += (inicio + fin) / 2;
        return 1 + profundidadNodoRec(n, ((inicio + fin) / 2), inicio, fin);
    }
    else
    {
        fin = fin / 2;
        return 1 + profundidadNodoRec(n, ((inicio + fin) / 2), inicio, fin);
    }
}*/

template <typename T> inline void Abin<T>::enseniarVector() {
    for (int i = 0; i < maxNodos; i++) {
        if(nodos[i] != ELTO_NULO)
            std::cout << " " << nodos[i] << " ";
        else
            std::cout << " - ";
    }
    std::cout << std::endl;
}

template <typename T> inline typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const
{
    int num = n - ((maxNodos+1) / pow(2, profundidad(n) + 2));
    
    assert(n >= 0 && n <= maxNodos-1); // nodo válido
    assert(nodos[n] != ELTO_NULO);     // nodo del árbol
    
    return (num >= maxNodos || nodos[num] == ELTO_NULO) ?  NODO_NULO : num;
}

template <typename T> inline typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const
{
    int num = n + ((maxNodos+1) / pow(2, profundidad(n) + 2));
    
    assert(n >= 0 && n <= maxNodos-1); // nodo válido
    assert(nodos[n] != ELTO_NULO);     // nodo del árbol
    
    return (num >= maxNodos || nodos[num] == ELTO_NULO) ?  NODO_NULO : num;
}

template <typename T> inline void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n, const T& e)
{
    int num = n - ((maxNodos+1) / pow(2, profundidad(n) + 2));
    
    assert(n >= 0 && n <= maxNodos-1);      // nodo válido
    assert(nodos[n] != ELTO_NULO);          // nodo del árbol
    
    assert(num < maxNodos);               // hijo izqdo. cabe en el árbol
    assert(nodos[num] == ELTO_NULO);      // n no tiene hijo izqdo.
    
    nodos[num] = e;
}

template <typename T> inline void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n,const T& e)
{
    int num = n + ((maxNodos+1) / pow(2, profundidad(n) + 2));
    assert(n >= 0 && n < maxNodos-1);       // nodo válido
    assert(nodos[n] != ELTO_NULO);          // nodo del árbol
    
    assert(num < maxNodos);               // hijo drcho. cabe en el árbol
    assert(nodos[num] == ELTO_NULO);      // n no tiene hijo drcho.
    nodos[num] = e;
}

//template <typename T> inline void Abin<T>::eliminarHijoIzqdoB(Abin<T>::nodo n)
//{
//    assert(n >= 0 && n <= maxNodos-1);      // nodo válido
//    assert(nodos[n] != ELTO_NULO);          // nodo del árbol
//    assert(2*n+1 < maxNodos);               // hijo izqdo. cabe en el árbol
//    assert(nodos[2*n+1] != ELTO_NULO);      // n tiene hijo izqdo.
//    
//    if (4*n+4 < maxNodos)                   // caben los hijos del hijo izqdo. de n
//        assert(nodos[4*n+3] == ELTO_NULO && // hijo izqdo. de
//        nodos[4*n+4] == ELTO_NULO);         // n es hoja
//    else if (4*n+3 < maxNodos)              //sólo cabe h. izq. de h. izq. de n
//        assert(nodos[4*n+3] == ELTO_NULO);  //hijo izq. de n es hoja
//    
//    nodos[2*n+1] = ELTO_NULO;
//}
//
//template <typename T> inline void Abin<T>::eliminarHijoDrchoB(Abin<T>::nodo n)
//{
//    assert(n >= 0 && n <= maxNodos-1);      // nodo válido
//    assert(nodos[n] != ELTO_NULO);          // nodo del árbol
//    assert(2*n+2 < maxNodos);               // hijo drcho. cabe en el árbol
//    assert(nodos[2*n+2] != ELTO_NULO);      // n tiene hijo drcho.
//    
//    if (4*n+6 < maxNodos)                   // caben los hijos del hijo drcho. de n
//        assert(nodos[4*n+5] == ELTO_NULO && // hijo drcho. de
//        nodos[4*n+6] == ELTO_NULO);         // n es hoja
//    else if (4*n+5 < maxNodos)              //sólo cabe h. izq. de h. drch de n
//        assert(nodos[4*n+5] == ELTO_NULO);  //hijo drch de n es hoja
//    
//    nodos[2*n+2] = ELTO_NULO;
//}

template <typename T> inline void Abin<T>::eliminarRaizB()
{
    assert(nodos[maxNodos / 2] != ELTO_NULO);          // árbol no vacío
    assert(nodos[maxNodos / 4] == ELTO_NULO &&
    nodos[(int) (maxNodos * 1.5 / 2)] == ELTO_NULO);                 // la raíz es hoja
    nodos[maxNodos / 2] = ELTO_NULO;
}

template <typename T> inline Abin<T>::~Abin()
{
    delete[] nodos;
}

template <typename T> inline bool Abin<T>::arbolVacioB() const
{
    return (nodos[maxNodos / 2] == ELTO_NULO);
}

template <typename T> inline const T& Abin<T>::elemento(Abin<T>::nodo n) const
{
    assert(n >= 0 && n <= maxNodos-1);    // nodo válido
    assert(nodos[n] != ELTO_NULO);        // nodo del árbol
    return nodos[n];
}

template <typename T> inline T& Abin<T>::elemento(Abin<T>::nodo n)
{
    assert(n >= 0 && n <= maxNodos-1);   // nodo válido
    assert(nodos[n] != ELTO_NULO);       // nodo del árbol
    return nodos[n];
}

template <typename T> inline typename Abin<T>::nodo Abin<T>::raizB() const
{
    return (nodos[maxNodos / 2] == ELTO_NULO) ? NODO_NULO : nodo(maxNodos / 2);
}

template <typename T> inline typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const
{
    assert(n >= 0 && n <= maxNodos-1);  // nodo válido
    assert(nodos[n] != ELTO_NULO);      // nodo del árbol
    
    if (n % ((maxNodos+1) / pow(2, profundidad(n)+1)) == (((maxNodos + 1) / pow(2, profundidad(n)+1)) - 1))
    {
        return n + (maxNodos + 1) / pow(2, profundidad(n) + 1);
    }
    else
    {
        return n - (maxNodos + 1) / pow(2, profundidad(n) + 1);
    }
}

template <typename T> Abin<T>::Abin(const Abin<T>& a) : nodos(new T[a.maxNodos]), maxNodos(a.maxNodos), ELTO_NULO(a.ELTO_NULO)
{
    // copiar el vector
    for (nodo n = 0; n <= maxNodos-1; n++)
        nodos[n] = a.nodos[n];
}

template <typename T> Abin<T>& Abin<T>::operator =(const Abin<T>& a)
{
    if (this != &a) // evitar autoasignación
    {
        // Destruir el vector y crear uno nuevo si es necesario
        if (maxNodos != a.maxNodos)
        {
            delete[] nodos;
            maxNodos = a.maxNodos;
            nodos = new T[maxNodos];
        }
        ELTO_NULO = a.ELTO_NULO;
        
        // Copiar el vector
        for (nodo n = 0; n <= maxNodos-1; n++)
            nodos[n] = a.nodos[n];
    }
    return *this;
}
#endif // Abin_VEC1_H
