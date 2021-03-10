#include <fstream>
#include <iostream>
#include <string>
#include "../abin.h"
#include "../abin_E-S.h"

using namespace std;

// a)
typedef union Expression
{
    char math_operator;
    double operand;
} Expression;

istream& operator >>(istream& is, Expression& ex)
{
    string s;
    is >> s;

    ex.operand = strtod(s.c_str(), NULL);
    
    if(ex.operand == 0.0)
        ex.math_operator = s.c_str()[0];
    
    return is;
}

ostream& operator <<(ostream& os, Expression ex)
{
    if( ex.operand < 1.0 / 10000000) 
        os << ex.math_operator;
    else
        os << std::to_string(ex.operand);

    return os;
}

bool operator ==(Expression ex1, Expression ex2)
{
    return ex1.math_operator == ex2.math_operator;
}

bool operator !=(Expression ex1, Expression ex2)
{
    return ex1.math_operator != ex2.math_operator;
}

// b)

double computeTree(Abin<Expression>& T, Abin<Expression>::nodo n)
{
    if(Abin<Expression>::NODO_NULO == T.hijoIzqdo(n))
        return T.elemento(n).operand;
    else switch(T.elemento(n).math_operator)
    {
        case '+': return computeTree(T, T.hijoIzqdo(n)) + computeTree(T, T.hijoDrcho(n));
        break;
        case '-': return computeTree(T, T.hijoIzqdo(n)) - computeTree(T, T.hijoDrcho(n));
        break;
        case 'x': return computeTree(T, T.hijoIzqdo(n)) * computeTree(T, T.hijoDrcho(n));
        break;
        case '*': return computeTree(T, T.hijoIzqdo(n)) * computeTree(T, T.hijoDrcho(n));
        break;
        case '/': return computeTree(T, T.hijoIzqdo(n)) / computeTree(T, T.hijoDrcho(n));
        break;
        default: return 0.0;
    }
}

double computeTree(Abin<Expression>& T)
{
    if(T.arbolVacio())
        return 0.0; 
    else    
        return computeTree(T, T.raiz());
}

int main(int argc, char const *argv[])
{
    Abin<Expression> T;
    ifstream ef("mathTree.dat");
    rellenarAbin(ef, T);
    ef.close();

    imprimirAbin(T);

    cout << "The result is: " << computeTree(T) << endl;

    return 0;
}