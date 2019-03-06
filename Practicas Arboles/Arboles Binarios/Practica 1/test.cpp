#include "abin.h"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#';

int main () 
{
   Abin<tElto> A, B;

   cout << "*** Lectura del árbol binario A ***\n";
   rellenarAbin(A, fin);      // desde std::cin
    ofstream fs("abin.dat"); // abrir fichero de salida 
    imprimirAbin(fs, A, fin); // en fichero
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n"; 
    ifstream fe("abin.dat"); // abrir fichero de entrada 
    rellenarAbin(fe, B); // desde fichero
    fe.close();
   cout << "\n*** Mostrar árbol binario B ***\n";
   imprimirAbin(B);           // en std::cout
}