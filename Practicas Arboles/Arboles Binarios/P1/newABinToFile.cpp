#include "../abin.h"
#include "../abin_E-S.h"

int main(int argc, char const *argv[])
{
    Abin<int> A;
    ofstream file("abin.dat");

    rellenarAbin(A, -1);
    imprimirAbin(file, A, -1);
    file.close();
    
    return 0;
}
