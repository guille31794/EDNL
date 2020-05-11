#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
bool subvencion(const GrafoP<tCoste>& G);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
    typedef typename GrafoP<int>::vertice vertice;

    string a="Aciclico.txt";
    GrafoP<int> G(a);
    int n=G.numVert();
    cout << G;

    cout << subvencion(G);
}

//Hay que quitar la condicion de poner la diagonal principal a 0.
template <typename tCoste>
bool subvencion(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertice;

    //Es necesario hacer floyd7
    matriz<vertice> P(G.numVert());

    matriz<tCoste> M=Floyd(G,P);

    for(vertice i=0;i<G.numVert();++i){
        if(M[i][i]!=GrafoP<tCoste>::INFINITO)return false;
        cout<<G[i][i]<<endl;
    }
    return true;
}





