#include "../abinvec.h"
#include "../abin_E-S.h"

int main(int argc, char const *argv[])
{
    Abin<int> A{5};
    int fin = -1;
    
    rellenarAbin(A, fin);

    Abin<int>::nodo n = A.raizB();
    while(A.hijoIzqdoB(n) != Abin<int>::NODO_NULO)
       n = A.hijoIzqdoB(n); 

    cout << "Depth is: " << A.profundidad(n) << endl;

    return 0;
}
