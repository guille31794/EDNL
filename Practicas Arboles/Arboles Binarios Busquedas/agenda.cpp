#include <iostream>
#include "abb.h"
#include <list>
#include <cstring>

using namespace std;

typedef struct Palabra
{
    Palabra(string = "", string = "");
    string palabraEspaniol;
    string palabraZuelandes;
} Palabra;

Palabra::Palabra(string pEsp, string pZld): palabraEspaniol{pEsp},
palabraZuelandes{pZld} {}

bool operator <(const Palabra& p1, const Palabra& p2)
{
    return p1.palabraEspaniol < p2.palabraEspaniol;
}

bool operator ==(const Palabra& p1, const Palabra& p2)
{
    return p1.palabraEspaniol == p2.palabraEspaniol;
}

ostream& operator <<(ostream& os, const Palabra& p)
{
    return os << p.palabraEspaniol << " - " << p.palabraZuelandes;
}

class Diccionario
{
private:
    Abb<Palabra> A;
    void imprimirRec(const Abb<Palabra>&);
public:
    Diccionario();
    void insertarPalabra(const Palabra& );
    void eliminarPalabra(const Palabra& );
    void modificarTraduccion(const Palabra&);
    string buscarPalabra(const string);
    void imprimirPalabras();
};

Diccionario::Diccionario(){}

void Diccionario::insertarPalabra(const Palabra& p)
{
    A.insertar(p);
}

void Diccionario::eliminarPalabra(const Palabra& p)
{
    A.eliminar(p);
}

void Diccionario::modificarTraduccion(const Palabra& p)
{
    if (!A.buscar(p).vacio()) 
    {   
        A.eliminar(p);
        A.insertar(p);
    }
    else
        cout << "Palabra no encontrada\n" << endl;
}

string Diccionario::buscarPalabra(string p)
{
    Palabra w{p};
    if (!A.buscar(w).vacio())
        return A.buscar(w).elemento().palabraZuelandes;
    else
        return string{"Palabra no encontrada\n"};
}

void Diccionario::imprimirPalabras()
{
    if(!A.vacio())
    {
        cout << A.elemento() << '\n';

        if(!A.izqdo().vacio())
            imprimirRec(A.izqdo());
        if(!A.drcho().vacio())
            imprimirRec(A.drcho());
    }

    cout << endl;
}

void Diccionario::imprimirRec(const Abb<Palabra>& A)
{
    cout << A.elemento() << '\n';

    if (!A.izqdo().vacio())
        imprimirRec(A.izqdo());
    if (!A.drcho().vacio())
        imprimirRec(A.drcho());
}

int main()
{
    Diccionario Vox{};
    Palabra a{"hola", "hello"},
    b{"holi", "hi"}, c{"adios", "bye"},
    d{"adiosito", "good bye"}, e{"holi", "mariquita"};

    Vox.insertarPalabra(a);
    Vox.insertarPalabra(b);
    Vox.insertarPalabra(c);
    Vox.insertarPalabra(d);

    cout << Vox.buscarPalabra("hola") << '\n' <<
    Vox.buscarPalabra("cuack");

    Vox.eliminarPalabra(a);
    Vox.modificarTraduccion(e);
    Vox.modificarTraduccion(a);

    cout << Vox.buscarPalabra(b.palabraEspaniol) << endl;

    Vox.imprimirPalabras();

    return 0;
}