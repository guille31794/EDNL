#include "../agen.h"
#include "../agen_E-S.h"
#include <queue>

using namespace std;

template <typename T>
int imbalanceRec(Agen<T>& A, typename Agen<T>::nodo n)
{
    queue<typename Agen<T>::nodo> Q;
    int height = 0, height1 = 0;

    if (n != Agen<T>::NODO_NULO) 
    {
        do
        {
            if(!Q.empty())
            {
                n = Q.front();
                Q.pop();
            }

            //Here goes the iterative height
            while(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
            {
                ++height1;
            }
            
            height = std::max(height, height1);

            typename Agen<T>::nodo son = A.hijoIzqdo(n);

            while(son != Agen<T>::NODO_NULO)
            {
                Q.push(son);
                son = A.hermDrcho(son);
            }
            
            height1 = 0;
        } while (!Q.empty());
    }
    
    return height;
}

template <typename T>
int imbalance(Agen<T>& A)
{
    int height = 0;

    if(!A.arbolVacio())
        height = imbalanceRec(A, A.raiz());

    return height;
}

int main()
{
    Agen<int> T;
    int fin = -1;

    rellenarAgen(T, fin);

    cout << "Tree imbalance is: " << imbalance(T) << endl;

    return 0;
}