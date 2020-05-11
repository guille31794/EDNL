#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void maxViaje(const GrafoP<tCoste>& G);
template <typename tCoste>
void maxRecorrido(const GrafoP<tCoste>& G);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Ejemplo.txt";
	GrafoP<int> G(a);

	cout << G << endl;

	maxViaje(G);
	maxRecorrido(G);
}

template <typename tCoste>
void maxViaje(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertices;
	typename GrafoP<tCoste>::vertice vertice,a,b;
	vector<vertices> P;
	vector<tCoste> alNodo;
	int max=0;

	for(vertice=0;vertice<G.numVert();vertice++){
		alNodo=DijkstraInv(G,vertice,P);
		for(int i=0;i<G.numVert();i++){
			if(alNodo[i]!=GrafoP<tCoste>::INFINITO && alNodo[i]>max){
				max=alNodo[i];
				a=vertice;
				b=i;
			}
		}
	}
	cout << "El maximo viaje posible es de " << max << " kilometros, " << " entre el nodo " << a << " y " << b <<endl;
}

template <typename tCoste>
void maxRecorrido(const GrafoP<tCoste>& G){
	typedef typename GrafoP<tCoste>::vertice vertices;
	matriz<vertices> P;
	matriz<tCoste> M=FloydInv(G,P);

	for(int i=0;i<G.numVert();i++){
		for(int j=0;j<G.numVert();j++){
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}
