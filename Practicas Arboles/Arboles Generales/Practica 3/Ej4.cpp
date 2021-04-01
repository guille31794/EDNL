#include <iostream>
#include <fstream>
#include <queue>
#include "../agen.h"
#include "../agen_E-S.h"

using namespace std;

void prunePostOrder(Agen<int>& T, Agen<int>::nodo n, int x)
{
   if(Agen<int>::NODO_NULO != n)
   {
       Agen<int>::nodo son = T.hijoIzqdo(n);
       
       while(Agen<int>::NODO_NULO != son)
       {
           prunePostOrder(T, son, x);
           son = T.hermDrcho(son);
       }
       
       if(T.elemento(n) != x)
         T.eliminarHijoIzqdo(T.padre(n));
   }
}

// it runs over the width of the tree until it finds the integer
void pruneTree(Agen<int> &T, Agen<int>::nodo n, int x)
{
    queue<Agen<int>::nodo> Q;

    if(Agen<int>::NODO_NULO != n)
    {
        do
        {
            if(!Q.empty())
            {
                n = Q.front();
                Q.pop();
            }

            if (T.elemento(n) == x)
            {
                prunePostOrder(T, n, x);
                break;
            }

            Agen<int>::nodo son = T.hijoIzqdo(n);
            while(Agen<int>::NODO_NULO != son)
            {
                Q.push(son);
                son = T.hermDrcho(son);
            }

        } while (!Q.empty());
        
    }
    

}

void pruneTree(Agen<int> &T, int x)
{
    if(!T.arbolVacio())
        pruneTree(T, T.raiz(), x);
}

int main(int argc, char const *argv[])
{
    Agen<int> T;
    ifstream inf("agen.dat");

    rellenarAgen(inf, T);
    inf.close();
    imprimirAgen(T);

    int x;
    cout << "Insert an integer number: ";
    cin >> x ;
    pruneTree(T, x);
    cout << "The new tree is: " << endl;
    imprimirAgen(T);

    return 0;
}
