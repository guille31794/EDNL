#include "../abin.h"
#include "../abin_E-S.h"

template <typename T>
void reflectRec(Abin<T>& T1, typename Abin<T>::nodo n1, 
Abin<T>& T2, typename Abin<T>::nodo n2)
{
    if(n1 != Abin<T>::NODO_NULO)
    {
        if(n1 == T1.raizB())
        {   
            reflectRec(T1, T1.hijoIzqdoB(n1), T2, n2);
            reflectRec(T1, T1.hijoDrchoB(n1), T2, n2);
        }
        //Compruebo si es hijo derecho o izquierdo
        else
        { 
            if(T1.hijoDrchoB(T1.padreB(n1)) != n1)
            {
                T2.insertarHijoDrchoB(n2, T1.elemento(n1));
                reflectRec(T1, T1.hijoIzqdoB(n1), T2, T2.hijoDrchoB(n2));
                reflectRec(T1, T1.hijoDrchoB(n1), T2, T2.hijoDrchoB(n2));
            }
            else
            {
                T2.insertarHijoIzqdoB(n2, T1.elemento(n1));
                reflectRec(T1, T1.hijoIzqdoB(n1), T2, T2.hijoIzqdoB(n2));
                reflectRec(T1, T1.hijoDrchoB(n1), T2, T2.hijoIzqdoB(n2));
            }
        }
    }
}

template <typename T>
Abin<T> reflect(Abin<T>& T1)
{
    Abin<T> T2;
    if (!T1.arbolVacioB()) 
    {
        T2.insertarRaizB(T1.elemento(T1.raizB()));
        reflectRec(T1, T1.raizB(), T2, T2.raizB());
        T1.~Abin();
    }
    return T2;
}

int main()
{
    Abin<int> T;
    int end = -1;

    rellenarAbin(T, end);
    imprimirAbin(T);

    Abin<int> RT = reflect(T);
    imprimirAbin(RT);
}