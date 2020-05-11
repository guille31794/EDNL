#include<iostream>
#include"particion.cpp"
#include"alg_grafoMA.cpp"
#include"grafoMA.cpp"
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void calcular(const GrafoP<tCoste>& G);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Espana.txt";
	GrafoP<int> G(a);

	cout << G << endl;

	calcular(G);
}

template <typename tCoste>
void calcular(const GrafoP<tCoste>& G){
	GrafoP<tCoste> G1=Prim(G);
	int coste=0;
	for(size_t i=0;i<G.numVert();i++){
		for(size_t j=0;j<G.numVert();j++){
			if(G1[i][j]!=GrafoP<tCoste>::INFINITO){
                coste=coste+G1[i][j];
			}
		}
	}
	cout << "Arbol minimo: " << endl;
	cout << G1 << endl;
	cout << "El coste es: " << float(coste/2) << "." << endl;
}

