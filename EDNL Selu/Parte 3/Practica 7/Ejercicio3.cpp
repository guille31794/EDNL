#include<iostream>
#include"alg_grafoPMC.h"
#include<cstdlib>

using namespace std;

void Ejercicio();
void inicializar(vector<int>& subvencion,vector<int>& almacen);
template <typename tCoste>
void lugares(GrafoP<tCoste>& G,int producto,vector<int> subvencion,vector<int> almacen);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Zuelandia.txt";
	GrafoP<float> G(a);
	vector<int> subvencion(6),almacen(6);

	inicializar(subvencion,almacen);

	lugares(G,100,subvencion,almacen);
}

void inicializar(vector<int>& subvencion,vector<int>& almacen){
	subvencion[0]=15;
	subvencion[1]=10;
	subvencion[2]=50;
	subvencion[3]=25;
	subvencion[4]=30;
	subvencion[5]=40;

	almacen[0]=40;
	almacen[1]=20;
	almacen[2]=30;
	almacen[3]=15;
	almacen[4]=10;
	almacen[5]=50;
}

template <typename tCoste>
void lugares(GrafoP<tCoste>& G,int producto,vector<int> subvencion,vector<int> almacen){
	//Calculamos el precio con las subvenciones:
	for(int i=1;i<G.numVert();i++){
		float aux=(G[0][i]*subvencion[i-1])/100;
		G[0][i]=G[0][i]-aux;
	}

	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> P;
	typename GrafoP<tCoste>::vertice origen=0;
	vector<tCoste> M=Dijkstra(G,origen,P);
    M[0]=GrafoP<tCoste>::INFINITO;

	int escoger;
	float precio=0;
	while(producto>0){
		float aux=GrafoP<tCoste>::INFINITO;
		for(int i=0;i<G.numVert();i++){
			if(M[i]<aux){
				aux=M[i];
				escoger=i;
			}
		}
		if(almacen[escoger]>=producto){
			producto=0;
			almacen[escoger]=almacen[escoger]-producto;
		}else{
			producto=producto-almacen[escoger];
			almacen[escoger]=0;
		}
		precio=precio+M[escoger];
		M[escoger]=GrafoP<tCoste>::INFINITO;
		cout << producto << " ";
		system("pause");
	}
	cout << "Por un precio de " << precio << " $ " << "se logra el objetivo." << endl;
}


