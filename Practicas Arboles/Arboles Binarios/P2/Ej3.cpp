#include "../abin.h"
#include "abin_E-S.h"

// TAD to store operators or operands
union Expresion
{
    char operation;
    double operand;
};

double AbinEvaluateExpresionRec( typename Abin<Expresion>::nodo n, 
Abin<Expresion>& A)
{
    if (A.hijoIzqdo(n) == Abin<Expresion>::NODO_NULO
    && A.hijoDrcho(n) == Abin<Expresion>::NODO_NULO)
        return A.elemento(n).operand;
    else
        switch (A.elemento(n).operation)
        {
            case '+': 
                return AbinEvaluateExpresionRec(
                A.hijoIzqdo(n), A) + AbinEvaluateExpresionRec(
                A.hijoDrcho(n), A);
                break;
            case '-': 
                return AbinEvaluateExpresionRec(
                A.hijoIzqdo(n), A) - AbinEvaluateExpresionRec(
                A.hijoDrcho(n), A);
                break;
            case '*': 
                return AbinEvaluateExpresionRec(
                A.hijoIzqdo(n), A) * AbinEvaluateExpresionRec(
                A.hijoDrcho(n), A);
                break;
            case '/':
                return AbinEvaluateExpresionRec(
                A.hijoIzqdo(n), A) / AbinEvaluateExpresionRec(
                A.hijoDrcho(n), A);
                break;
        }
}

double AbinEvaluateExpresion(Abin<Expresion>& A)
{
    return AbinEvaluateExpresionRec(A.raiz(), A);
}

int main(int argc, char const *argv[])
{
    Abin<Expresion> A;

    cout << "The result of : " << 
    AbinEvaluateExpresion(A) << endl;

    return 0;
}
