#include<iostream>
#include"particion.cpp"
#include"alg_grafoMA.cpp"
#include"grafoMA.cpp"
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void hacer(const GrafoP<tCoste>& G);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Caceres.txt";
	GrafoP<int> G(a);

	cout << G << endl;

	hacer(G);
}

template <typename tCoste>
void hacer(const GrafoP<tCoste>& G){
	GrafoP<tCoste> G1(G);

	for(size_t i=0;i<G.numVert();i++){
		for(size_t j=0;j<G.numVert();j++){
			if(G1[i][j]!=GrafoP<tCoste>::INFINITO){
				G1[i][j]=-1*G[i][j];
			}
		}
	}

	G1=Kruskall(G1);

	for(size_t i=0;i<G.numVert();i++){
		for(size_t j=0;j<G.numVert();j++){
			if(G1[i][j]!=GrafoP<tCoste>::INFINITO){
				G1[i][j]=-1*G1[i][j];
			}
		}
	}

    cout << "Arbol maximo: " << endl;
	cout << G1 << endl;
}
