#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
int distancia(GrafoP<tCoste>& G,const vector<tCoste>& partetrabajo);


int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Zuelandia.txt";
	GrafoP<int> G(a);

	//Parte trabajo:
	vector<int> partetrabajo(G.numVert());
	partetrabajo[0]=0;
	partetrabajo[1]=3;
	partetrabajo[2]=12;
	partetrabajo[3]=1;
	partetrabajo[4]=10;
	partetrabajo[5]=1;
	partetrabajo[6]=9;

	cout << "La distancia a recorrer de hoy es " << distancia(G,partetrabajo) << " km." << endl;
}

template <typename tCoste>
int distancia(GrafoP<tCoste>& G,const vector<tCoste>& partetrabajo){
	typedef typename GrafoP<tCoste>::vertice vertice;
	typename GrafoP<tCoste>::vertice origen=0;
	vector<vertice> P;

	vector<tCoste> M=Dijkstra(G,origen,P);

 	int distancia=0;
 	for(int i=1;i<G.numVert();i++){
 		if(G[origen][i]!=GrafoP<tCoste>::INFINITO){
 			distancia=distancia+(M[i]*partetrabajo[i])*2;
 		}
 	}

	return distancia;
}

