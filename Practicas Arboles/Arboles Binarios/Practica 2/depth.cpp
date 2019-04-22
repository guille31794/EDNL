#include <iostream>
#include "Ejercicio4.hpp"

int main(int argc, char const *argv[])
{
    Abin<int> T{4};
    T.rootInsert(4);
    T.leftSonInsert(T.root(), 2);
    T.printA();

    return 0;
}
