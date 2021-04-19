#include <fstream>
#include "Ejercicio1.hpp"
#include "abb_ES.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Abb<int> A, B;
    int fin = -1;
    ofstream fs("ej3.dat");

    rellenarAbb(A, fin);
    imprimirAbb(A, fs, fin);
    imprimirAbb(A);
    
    fs.close();

    ifstream fe("ej3.dat");
    rellenarAbb(B, fe, fin);
    imprimirAbb(B);

    fe.close();
    
    return 0;
}