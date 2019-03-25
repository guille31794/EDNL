#include "../abin.h"
#include "../abin_E-S.h"
#include <cstring>
#include <exception>
#include <stack>
#include <queue>

typedef struct mathExpr
{
    explicit mathExpr(char s): s_{s}, num_{0}
    {
        if(s_ != '/' && s_ != '+' && s_ != '-' && s != '*')
        {
            throw invalid_argument("Error. Invalid argument.");
            terminate();
        }
    }

    explicit mathExpr(double n): num_{n}, s_{}
    {}

    char s_;
    double num_; 
} mathExpr;

basic_ostream<char>& operator <<
(basic_ostream<char>& os, const mathExpr & m)
{
    if(m.s_ == '\0')
        os << m.num_;
    else
        os << m.s_;

    return os;
}

double compute(Abin<mathExpr> T, Abin<mathExpr>::nodo n)
{
    if(T.hijoIzqdoB(n) == Abin<mathExpr>::NODO_NULO && 
    T.hijoDrchoB(n) == Abin<mathExpr>::NODO_NULO)
        return T.elemento(n).num_;
    else
        switch (T.elemento(n).s_)
        {
            case '+': return compute(T, T.hijoIzqdoB(n)) + 
                compute(T, T.hijoDrchoB(n));
                break;
            case '-': return compute(T, T.hijoIzqdoB(n)) - 
                compute(T, T.hijoDrchoB(n));
                break;
            case '/': return compute(T, T.hijoIzqdoB(n)) / 
                compute(T, T.hijoDrchoB(n));
                break;
            case '*': return compute(T, T.hijoIzqdoB(n)) *
                compute(T, T.hijoDrchoB(n));
                break;
        }
}

double postfix(Abin<mathExpr>& T)
{
    double res{0.0};

    if(!T.arbolVacioB())
    {
        Abin<mathExpr>::nodo n = T.raizB();
        res += compute(T, n);
    }

    return res;
}

/*double postfix(Abin<mathExpr> T)
{
    stack<mathExpr> S;
    queue<Abin<mathExpr>::nodo> Q;
    double res;

    // Iterative travel in width through the three

    if(!T.arbolVacioB())
    {
        Abin<mathExpr>::nodo n = T.raizB();

        if (n != Abin<mathExpr>::NODO_NULO) 
        {
            do
            {
                if(n != Abin<mathExpr>::NODO_NULO)
                {
                    if (!Q.empty()) 
                    {
                        n = Q.front();
                        Q.pop();
                    }
                    
                    S.push(T.elemento(n));

                    if (T.hijoIzqdoB(n) != Abin<mathExpr>::NODO_NULO)
                        Q.push(T.hijoIzqdoB(n));
                    if (T.hijoDrchoB(n) != Abin<mathExpr>::NODO_NULO)
                        Q.push(T.hijoDrchoB(n));
                } 
            } while (!Q.empty());
        }
    }

    // Compute postfix expression
    while(!S.empty())
    {
        double term2{S.top().num_};
        S.pop();
        double term1{S.top().num_};
        S.pop();

        if(S.top().s_ == '\0')
        {
            mathExpr aux1{S.top()};
            S.pop();
            mathExpr aux2{S.top()};
            S.pop();
            S.push(aux1);
            S.push(aux2);
        }

        switch (S.top().s_)
        {
            case '+': res = term1 + term2;
                break;
            case '-': res = term1 - term2;
                break;
            case '/': res = term1 / term2;
                break;
            case '*': res = term1 * term2;
                break;
        }

        cout << term1 << " " << term2 << " " << res << endl;

        S.pop();
        if(!S.empty())
            S.push(mathExpr{res});
    }
    
    return res;
}*/

int main(int argc, char const *argv[])
{
    Abin<mathExpr> T;
    T.insertarRaizB(mathExpr{'*'});
    Abin<mathExpr>::nodo n = T.raizB();
    T.insertarHijoIzqdoB(n, mathExpr{7.0});
    T.insertarHijoDrchoB(n, mathExpr{'/'});
    n = T.hijoDrchoB(n);
    T.insertarHijoDrchoB(n, mathExpr{2.0});
    T.insertarHijoIzqdoB(n, mathExpr{'-'});
    n = T.hijoIzqdoB(n);
    T.insertarHijoIzqdoB(n, mathExpr{15.0});
    T.insertarHijoDrchoB(n, mathExpr{3.2});

    imprimirAbin(T);

    cout << "The result is: " << postfix(T) << endl;

    return 0;
}
