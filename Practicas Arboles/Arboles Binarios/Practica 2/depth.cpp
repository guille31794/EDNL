#include <iostream>
#include "Ejercicio4.hpp"

int main(int argc, char const *argv[])
{
    Abin<int> T{2};
    Abin<int>::node n;
    T.rootInsert(4);
    n = T.root();
    T.leftSonInsert(n, 2);
    n = T.leftSon(n);
    T.leftSonInsert(n, 3);
    //n = T.leftSon(n);
    //T.leftSonInsert(n, 1);
    //n = T.leftSon(n);
    //T.leftSonInsert(n, 5);
    cout << T.father(n) << endl;
    T.printA();

    return 0;
}
